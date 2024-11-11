#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int IT_MAX;
const int MOD = 1000;
const int INF = 1034567891;
const long long LL_INF = 2234567890123456789ll;
const double PI = 3.141592653589793238;
bool isEqual(long double a, long double b) { return abs(a - b) <= 1E-10; }
int main() {
  int N, R, V, i, j;
  long double s, f;
  scanf("%d %d %d", &N, &R, &V);
  for (i = 1; i <= N; i++) {
    cin >> s >> f;
    long double x = f - s;
    long double t = (x / (2 * R * PI));
    long double rt = (long long)(t + 0.5);
    if (isEqual(t, rt)) {
      double ans = (double)(x / V);
      printf("%.20lf\n", ans);
      continue;
    }
    double ans = 0;
    ans += (2 * R * PI * (long long)t) / V;
    t -= (long long)t;
    long double v = t * 2 * PI;
    long double st = 0, en = PI / 2, mi;
    for (j = 1; j <= 200; j++) {
      mi = (st + en) / 2;
      if (2 * sin(mi) + 2 * mi >= v)
        en = mi;
      else
        st = mi;
    }
    printf("%.20lf\n", (double)((1.0 * (f - s) - 2 * R * sin(mi)) / V));
  }
  return 0;
}
