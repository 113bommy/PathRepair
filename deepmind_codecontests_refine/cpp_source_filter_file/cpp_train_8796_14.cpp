#include <bits/stdc++.h>
using namespace std;
clock_t __START, __END;
double __TOTALTIME;
void _MS() { __START = clock(); }
void _ME() {
  __END = clock();
  __TOTALTIME = (double)(__END - __START) / CLOCKS_PER_SEC;
  cout << "Time: " << __TOTALTIME << " s" << endl;
}
const double E = 2.718281828;
const double PI = acos(-1.0);
const long long INF = (1LL << 60);
const int inf = (1 << 30);
const double ESP = 1e-12;
const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 10;
int main() {
  int n;
  double r, v;
  scanf("%d%lf%lf", &n, &r, &v);
  for (int i = 1; i <= n; ++i) {
    double s, t;
    scanf("%lf%lf", &s, &t);
    double len = t - s;
    double cnt = int(len / (2 * PI * r));
    double ans = cnt * 2 * PI * r / v;
    double L = 0, R = 2 * PI;
    double alpha = 0;
    int cc = 49;
    while (cc--) {
      double mid = (L + R) / 2;
      alpha = mid * r;
      if (alpha * 2 + 2 * r * sin(mid) > len - (cnt * 2 * PI * r))
        R = mid;
      else
        L = mid;
    }
    printf("%.10lf\n", ans + alpha * 2 / v);
  }
  return 0;
}
