#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const double EPS = (1e-7);
const int sz = 2e5 + 4;
const int mod = 998244353;
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
int arr[sz];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  double k, d, t, res = 0.0;
  cin >> k >> d >> t;
  long long times2 = ceil(k / d);
  long long interval = k + times2 * d - k;
  double cook = k + (times2 * d - k) / 2;
  long long nint = t / cook;
  t -= cook * nint, res += nint * interval;
  if (t < k)
    res += t;
  else
    res += k + (t - k) / 2;
  printf("%.9lf\n", res);
}
