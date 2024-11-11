#include <bits/stdc++.h>
#pragma warning(error : 4700)
#pragma warning(error : 4715)
#pragma warning(error : 4716)
using namespace std;
const long long MILLER_RABIN = 3215031751;
const long double PI = 3.14159265358979323846;
inline int lg2(long long n) {
  int h = 0;
  while ((1ll << h) < n) ++h;
  return h;
}
struct config_io {
  config_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
  }
} cnf_io;
struct config_rand {
  config_rand() {
    srand(chrono::duration_cast<chrono::nanoseconds>(
              chrono::high_resolution_clock::now().time_since_epoch())
              .count());
  }
} cnf_rand;
namespace std {
template <>
struct hash<pair<int, int> > {
  size_t operator()(const pair<int, int> &x) const {
    return (x.first * 31 + x.second) % ((int)1e9 + 7);
  }
};
}  // namespace std
long double dist(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
long double P(long double R, long double D) {
  if (D <= R) return 1;
  return exp(1 - (D * D) / (R * R));
}
long double calc(long double r, int k, vector<int> &x, vector<int> &y) {
  int n = x.size() - 1;
  long double dp[n + 1][n + 1];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] =
          dp[i - 1][j] * (1 - P(r, dist(x[0], y[0], x[i], y[i]))) +
          (j > 0 ? dp[i - 1][j - 1] : 0) * P(r, dist(x[0], y[0], x[i], y[i]));
    }
  }
  long double result = 0;
  for (int i = k; i <= n; ++i) {
    result += dp[n][i];
  }
  return result;
}
int main() {
  int n, k;
  long double eps;
  cin >> n >> k >> eps;
  vector<int> x(n + 1), y(n + 1);
  for (int i = 0; i <= n; ++i) {
    cin >> x[i] >> y[i];
  }
  long double l = 0, r = 1e4;
  const long double EPS = 1e-6;
  while (r - l > EPS) {
    long double mid = (l + r) / 2;
    long double prob = calc(mid, k, x, y);
    if (prob > 1 - eps / 1000) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << fixed << setprecision(8);
  cout << r << endl;
  return 0;
}
