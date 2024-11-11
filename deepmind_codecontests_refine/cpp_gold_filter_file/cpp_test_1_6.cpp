#include <bits/stdc++.h>
using namespace std;
int rd() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  cout << setprecision(10) << fixed;
  int n = rd(), k = rd();
  vector<int> x(n + 1), y(n + 1);
  for (int i = 1; i <= n; i++) x[i] = rd(), y[i] = rd();
  double low = 0.0, high = 2e5, eps = 1e-7, pi = acos(-1.0);
  while (high - low > eps) {
    double R = (low + high) / 2;
    vector<pair<double, double>> line;
    for (int i = 1; i <= n; i++) {
      double dis = sqrt((double)x[i] * x[i] + (double)y[i] * y[i]);
      if (dis > 2 * R) continue;
      double alpha = atan2((double)y[i], (double)x[i]);
      double sita = acos(1.0 - dis * dis / (2 * R * R));
      double delta = (pi - sita) / 2;
      double l = alpha - delta, r = alpha + delta;
      while (l < 0) {
        l += 2 * pi;
        r += 2 * pi;
      }
      if (r > 2 * pi) {
        line.push_back({l, 2 * pi});
        if (r != 2 * pi) line.push_back({0, r - 2 * pi});
      } else {
        line.push_back({l, r});
      }
    }
    vector<double> nums;
    for (auto pi : line) {
      nums.push_back(pi.first);
      nums.push_back(pi.second);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int len = nums.size();
    vector<int> d(len + 1, 0);
    for (auto pi : line) {
      int l = lower_bound(nums.begin(), nums.end(), pi.first) - nums.begin();
      int r = lower_bound(nums.begin(), nums.end(), pi.second) - nums.begin();
      d[l]++;
      d[r + 1]--;
    }
    int mx = d[0];
    for (int i = 1; i <= len; i++) d[i] += d[i - 1], mx = max(mx, d[i]);
    if (mx >= k)
      high = R;
    else
      low = R;
  }
  cout << low;
  return 0;
}
