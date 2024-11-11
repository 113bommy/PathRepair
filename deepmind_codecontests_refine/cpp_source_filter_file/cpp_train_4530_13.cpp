#include <bits/stdc++.h>
using namespace std;
inline int max(int a, int b) { return a < b ? b : a; }
inline int min(int a, int b) { return a > b ? b : a; }
inline long long max(long long a, long long b) { return a < b ? b : a; }
inline long long min(long long a, long long b) { return a > b ? b : a; }
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const long long INF = 1e18;
double fabs(double x) {
  if (x < 0)
    return -x;
  else
    return x;
}
double pi = acos(-1);
int arr[N];
int calc(double t, double v, double r, double d) {
  long double ang = v * t / r;
  long double dd = 2 * r * sin(ang / 2);
  return v * t + dd >= d;
}
int main() {
  int t, r, v;
  scanf("%d%d%d", &t, &r, &v);
  while (t--) {
    int s, f;
    scanf("%d%d", &s, &f);
    double b = (1.0 * (f - s - 2 * r)) / v, t = (1.0 * (f - s + 2ll * r)) / v;
    if (b < 0) b = 0;
    int it = 0;
    while (t - b > 1e-7 && it < 100) {
      double m = (b + t) / 2;
      it++;
      if (calc(m, v, r, f - s))
        t = m;
      else
        b = m;
    }
    printf("%.7lf\n", b);
  }
  return 0;
}
