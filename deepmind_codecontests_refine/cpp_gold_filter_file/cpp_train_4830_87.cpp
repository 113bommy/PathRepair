#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double PI = 3.14159265;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n <= 4) {
    cout << "No solution";
    return 0;
  }
  vector<pair<double, double>> pts = {{0.0, 0.0}};
  pair<double, double> v = {10, 0.0};
  double eps = 0.37;
  double ang = PI - PI * (n - 2) / n;
  deque<double> allLen;
  for (int i = 1; i < n; i++) {
    allLen.push_back(10 + i * eps);
  }
  for (int i = 1; i < n; i++) {
    pair<double, double> pd = {pts.back().first + v.first,
                               pts.back().second + v.second};
    pts.push_back(pd);
    double curlen = sqrt(v.first * v.first + v.second * v.second);
    double nextlen;
    if (i % 2 || n < 8) {
      nextlen = allLen.back();
      allLen.pop_back();
    } else {
      nextlen = allLen.front();
      allLen.pop_front();
    }
    v.first *= nextlen / curlen;
    v.second *= nextlen / curlen;
    pair<double, double> v2 = {v.first * cos(ang) - v.second * sin(ang),
                               v.first * sin(ang) + v.second * cos(ang)};
    v = v2;
  }
  double alpha = -pts.back().second / v.second;
  pair<double, double> vst = {pts.back().first + alpha * v.first,
                              pts.back().second + alpha * v.second};
  pts[0] = vst;
  for (auto p : pts) {
    cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}
