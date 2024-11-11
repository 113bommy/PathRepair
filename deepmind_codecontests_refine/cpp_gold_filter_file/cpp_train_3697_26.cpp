#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void checkMin(T &a, T b) {
  if (b < a) a = b;
}
template <typename T>
inline void checkMax(T &a, T b) {
  if (a < b) a = b;
}
const int MAX_N = 2048;
const double EPS = 1e-12;
inline int sgn(double x) { return x < -EPS ? -1 : x > EPS; }
int n;
pair<double, double> ps[MAX_N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < int(n); ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    double t = (double)a * a + (double)b * b;
    ps[i] = make_pair((double)a * c / t, (double)b * c / t);
  }
  long long ans = 0;
  for (int i = 0; i < int(n); ++i) {
    map<double, int> mp;
    int c = 0;
    for (int j = i + 1; j < n; ++j) {
      bool tx = sgn(ps[j].first - ps[i].first) == 0;
      bool ty = sgn(ps[j].second - ps[i].second) == 0;
      if (tx && ty)
        ++c;
      else if (tx)
        mp[1e300] += 1;
      else
        mp[(ps[j].second - ps[i].second) / (ps[j].first - ps[i].first)] += 1;
    }
    vector<pair<double, int>> v;
    for (const auto &p : mp) {
      if (!v.empty() && p.first - v.back().first <= EPS) {
        v.back().second += p.second;
      } else {
        v.push_back(p);
      }
    }
    for (const auto &p : v) {
      ans += p.second * (p.second - 1LL) / 2;
      ans += p.second * (long long)c;
    }
    ans += c * (c - 1LL) / 2;
  }
  cout << ans << "\n";
  return 0;
}
