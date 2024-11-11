#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool uax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
double d[5001][5001];
int main() {
  cout.precision(10);
  cout << fixed;
  int N, T;
  cin >> N >> T;
  d[0][0] = 1.0;
  double ans = 0.0;
  for (int i = 1; i <= (int)(N); ++i) {
    int _p, t;
    cin >> _p >> t;
    double p = 0.01 * _p;
    double s = 0.0;
    double q = p;
    double sq = 0.0;
    for (int j = 0; j < (int)(t - 1); ++j) {
      sq += q;
      q *= 1 - p;
    }
    for (int j = 1; j <= (int)(T); ++j) {
      s *= 1 - p;
      if (j >= t) s -= q * d[i - 1][j - t];
      s += p * d[i - 1][j - 1];
      d[i][j] = s;
      if (j >= t) d[i][j] += (1 - sq) * d[i - 1][j - t];
      ans += d[i][j];
    }
  }
  cout << ans << '\n';
  return 0;
}
