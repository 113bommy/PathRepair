#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 5e3 + 10;
const int MAXM = 1e6 + 10;
const long long mod = 1e9 + 7;
int main() {
  double k, d, t;
  scanf("%lf%lf%lf", &k, &d, &t);
  long long a = ceil(k / d);
  double one = k + (a * d - k) / 2.0;
  long long num = t / one;
  double ans = num * a * d;
  t -= num * one;
  if (t <= k)
    ans += t;
  else {
    ans += k;
    t -= k;
    ans += t * 2.0;
  }
  printf("%.10lf\n", ans);
  return 0;
}
