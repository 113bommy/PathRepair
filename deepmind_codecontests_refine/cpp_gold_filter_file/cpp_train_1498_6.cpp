#include <bits/stdc++.h>
using namespace std;
int n, T;
long long mul = 1000000;
struct pro {
  int ss, sl, ts, tl;
  long double pb;
  long long mpb;
} pros[2333];
long long s[1111][1563];
long double t[1111][1563];
bool operator<(pro a, pro b) {
  if (a.pb + 1e-6 > 1) return 0;
  if (b.pb + 1e-6 > 1) return 1;
  return a.tl * a.pb / (1 - a.pb) < b.tl * b.pb / (1 - b.pb);
}
int main() {
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) {
    double tmp;
    scanf("%d%d%d%d%lf", &pros[i].ss, &pros[i].sl, &pros[i].ts, &pros[i].tl,
          &tmp);
    pros[i].pb = tmp;
    pros[i].mpb = pros[i].pb * mul + 0.5;
  }
  sort(pros + 1, pros + 1 + n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= T; j++) {
      {
        if (j <= T) {
          long long x = s[i][j];
          long double y = t[i][j];
          if (s[i + 1][j] < x || (s[i + 1][j] == x && t[i + 1][j] > y))
            s[i + 1][j] = x, t[i + 1][j] = y;
        }
      }
      {
        if (j + pros[i].ts <= T) {
          long long x = s[i][j] + mul * pros[i].ss;
          long double y = t[i][j] + pros[i].ts;
          if (s[i + 1][j + pros[i].ts] < x ||
              (s[i + 1][j + pros[i].ts] == x && t[i + 1][j + pros[i].ts] > y))
            s[i + 1][j + pros[i].ts] = x, t[i + 1][j + pros[i].ts] = y;
        }
      }
      {
        if (j + pros[i].ts + pros[i].tl <= T) {
          long long x =
              s[i][j] + mul * pros[i].ss + (mul - pros[i].mpb) * pros[i].sl;
          long double y = (t[i][j] + pros[i].ts) * pros[i].pb +
                          (pros[i].ts + pros[i].tl + j) * (1 - pros[i].pb);
          if (s[i + 1][j + pros[i].ts + pros[i].tl] < x ||
              (s[i + 1][j + pros[i].ts + pros[i].tl] == x &&
               t[i + 1][j + pros[i].ts + pros[i].tl] > y))
            s[i + 1][j + pros[i].ts + pros[i].tl] = x,
                                      t[i + 1][j + pros[i].ts + pros[i].tl] = y;
        }
      }
    }
  }
  long long anss = -233;
  long double anst;
  for (int i = 0; i <= T; i++) {
    long long ss = s[n + 1][i];
    long double tt = t[n + 1][i];
    if (ss > anss || (ss == anss && tt < anst)) anss = ss, anst = tt;
  }
  long double as = anss, at = anst;
  as /= 1000000.0;
  double aa = as, bb = at;
  printf("%.9lf %.9lf\n", aa, bb);
}
