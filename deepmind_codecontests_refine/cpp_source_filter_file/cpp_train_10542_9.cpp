#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x_{0}, y_{0};
  Point(long long x = 0, long long y = 0) : x_(x), y_(y){};
  Point operator-(const Point &p) const { return Point(x_ - p.x_, y_ - p.y_); };
  long long cross(const Point &p) const { return x_ * p.y_ - y_ * p.x_; };
};
int dp[500][500];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int num_red, num_blue;
  cin >> num_red >> num_blue;
  Point *red = new Point[num_red], *blue = new Point[num_blue];
  for (int i = 0; i < num_red; ++i) cin >> red[i].x_ >> red[i].y_;
  for (int i = 0; i < num_blue; ++i) cin >> blue[i].x_ >> blue[i].y_;
  Point i2j;
  for (int i = 0; i < num_red; ++i) {
    for (int j = 0; j < num_red; ++j) {
      if (red[i].x_ >= red[j].x_ || i == j) continue;
      Point i2j = red[j] - red[i];
      for (int k = 0; k < num_blue; ++k)
        if (blue[k].x_ > red[i].x_ && blue[k].x_ < red[j].x_ &&
            i2j.cross(blue[k] - red[i]) > 0)
          ++dp[i][j];
      dp[j][i] = -dp[i][j];
    }
  }
  int num_empty{0};
  for (int i = 0; i < num_red; ++i)
    for (int j = i + 1; j < num_red; ++j)
      for (int k = j + 1; k < num_red; ++k)
        if (dp[i][j] + dp[j][k] + dp[k][i] == 0) ++num_empty;
  cout << num_empty << endl;
  return 0;
}
