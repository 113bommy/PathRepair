#include <bits/stdc++.h>
using namespace std;
inline void EnableFileIO(const string& fileName) {
  if (fileName.empty()) return;
  freopen((fileName + ".in").c_str(), "r", stdin);
  freopen((fileName + ".out").c_str(), "w", stdout);
  return;
}
const int INF = (1 << 30) - 1;
const long long LINF = (1LL << 61) - 1;
const double EPS = 1e-10;
const int N = 120, M = 1e6;
double qpow(double b, int k) {
  double res = 1;
  while (k) {
    if (k & 1) res *= b;
    b *= b, k >>= 1;
  }
  return res;
}
int n, k[N];
double p[N], nval[N];
int main() {
  EnableFileIO("");
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i] /= 100.0;
    nval[i] = INF;
  }
  double ans = 0, last = 0;
  for (int t = 0; t < M; t++) {
    int mx = -1;
    for (int i = 0; i < n; i++) {
      if (mx == -1 || nval[i] > nval[mx]) mx = i;
    }
    k[mx]++;
    nval[mx] =
        (1.0 - qpow(1 - p[mx], k[mx] + 1)) / (1.0 - qpow(1 - p[mx], k[mx]));
    double cur = 1;
    for (int i = 0; i < n; i++) {
      cur *= 1.0 - qpow(1 - p[i], k[i]);
    }
    ans += (cur - last) * (t + 1);
    last = cur;
  }
  printf("%.10lf\n", ans);
  return 0;
}
