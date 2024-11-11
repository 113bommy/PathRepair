#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)4e18;
const string name = "a";
int n;
double a, d, now;
int main() {
  cin >> n >> a >> d;
  double last = 0;
  for (int i = 0; i < (int)n; i++) {
    double t, v;
    scanf("%lf%lf", &t, &v);
    double t1 = v / a;
    if (v * t1 / 2 > d)
      now = sqrt(2 * d / a);
    else {
      t1 = v / a;
      now = t1 + (d - t1 * v / 2) / v;
    }
    now = max(last, t + now);
    printf("%.10lf\n", now);
    last = max(last, now);
  }
  return 0;
}
