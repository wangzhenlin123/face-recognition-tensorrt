#ifndef FACE_ANTI_SPOOFING_H_
#define FACE_ANTI_SPOOFING_H_

#include <memory>
#include <fstream>

#include <opencv2/opencv.hpp>
#include <ncnn/net.h>

#include <jsoncpp/json/json.h>

class FaceAntiSpoofing
{
public:
    FaceAntiSpoofing();
    ~FaceAntiSpoofing();

    void loadModel();
    float detect(cv::Mat &frame, const cv::Rect &bbox);

private:
    cv::Rect calculateBox(const cv::Rect &faceBbox, int width, int height, const Json::Value& config);

    std::vector<std::shared_ptr<ncnn::Net>> _ncnnNetworks;
    std::string _inputName;
    std::string _outputName;
    ncnn::Option _ncnnOption;

    Json::Value _jsonObject;
};

#endif // !FACE_ANTI_SPOOFING_H_