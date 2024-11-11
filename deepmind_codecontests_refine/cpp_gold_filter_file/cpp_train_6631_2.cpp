#include <bits/stdc++.h>
int get_weight(double sumx, double sumy, int64_t x, int64_t y) {
  double xp = sumx + x;
  double yp = sumy + y;
  double rp = xp * xp + yp * yp;
  double xm = sumx - x;
  double ym = sumy - y;
  double rm = xm * xm + ym * ym;
  if (rm < rp) {
    return -1;
  } else {
    return 1;
  }
}
std::vector<int> get_weights(const double sumx, const double sumy, int64_t x1,
                             int64_t y1, int64_t x2, int64_t y2) {
  std::vector<std::vector<int>> weights = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  std::vector<double> r(weights.size());
  int index = 0;
  for (const std::vector<int>& w : weights) {
    double sx = sumx + w[0] * x1 + w[1] * x2;
    double sy = sumy + w[0] * y1 + w[1] * y2;
    double rw = sx * sx + sy * sy;
    r[index] = rw;
    ++index;
  }
  int min_weight_index = std::min_element(r.begin(), r.end()) - r.begin();
  return weights[min_weight_index];
}
std::vector<int> get_weights(const double sumx, const double sumy, int64_t x1,
                             int64_t y1, int64_t x2, int64_t y2, int64_t x3,
                             int64_t y3) {
  std::vector<std::vector<int>> weights = {
      {1, 1, 1},  {1, 1, -1},  {1, -1, 1},  {1, -1, -1},
      {-1, 1, 1}, {-1, 1, -1}, {-1, -1, 1}, {-1, -1, -1}};
  std::vector<double> r(weights.size());
  int index = 0;
  for (const std::vector<int>& w : weights) {
    double sx = sumx + w[0] * x1 + w[1] * x2 + w[2] * x3;
    double sy = sumy + w[0] * y1 + w[1] * y2 + w[2] * y3;
    double rw = sx * sx + sy * sy;
    r[index] = rw;
    ++index;
  }
  int min_weight_index = std::min_element(r.begin(), r.end()) - r.begin();
  return weights[min_weight_index];
}
int main(int argc, char** argv) {
  int n;
  std::cin >> n;
  std::vector<std::pair<int64_t, int64_t>> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].first >> v[i].second;
  }
  std::vector<int> weights(n);
  double sumx = 0.0, sumy = 0.0;
  int i = 0;
  while (i < n) {
    if ((i + 2) < n) {
      std::vector<int> current_weights =
          get_weights(sumx, sumy, v[i].first, v[i].second, v[i + 1].first,
                      v[i + 1].second, v[i + 2].first, v[i + 2].second);
      weights[i] = current_weights[0];
      weights[i + 1] = current_weights[1];
      weights[i + 2] = current_weights[2];
      sumx += current_weights[0] * v[i].first +
              current_weights[1] * v[i + 1].first +
              current_weights[2] * v[i + 2].first;
      sumy += current_weights[0] * v[i].second +
              current_weights[1] * v[i + 1].second +
              current_weights[2] * v[i + 2].second;
      i += 3;
    } else {
      int w = get_weight(sumx, sumy, v[i].first, v[i].second);
      weights[i] = w;
      sumx += w * v[i].first;
      sumy += w * v[i].second;
      i += 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    std::cout << weights[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
