#include <bits/stdc++.h>
using namespace std;
const int MaxN = 110;
int n;
pair<long double, long double> p[MaxN];
void init() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i].first >> p[i].second;
  sort(p + 1, p + n + 1);
}
pair<long double, long double> operator+(pair<long double, long double> a,
                                         pair<long double, long double> b) {
  return pair<long double, long double>(a.first + b.first, a.second + b.second);
}
pair<long double, long double> operator-(pair<long double, long double> a,
                                         pair<long double, long double> b) {
  return pair<long double, long double>(a.first - b.first, a.second - b.second);
}
pair<long double, long double> operator/(pair<long double, long double> a,
                                         long double k) {
  return pair<long double, long double>(a.first / k, a.second / k);
}
long double sqrmod(pair<long double, long double> a) {
  return a.first * a.first + a.second * a.second;
}
long double sqrgetdis(pair<long double, long double> a,
                      pair<long double, long double> b) {
  return sqrmod(a - b);
}
long double getdis(pair<long double, long double> a,
                   pair<long double, long double> b) {
  return sqrt(sqrgetdis(a, b));
}
void line(pair<long double, long double> a, pair<long double, long double> b,
          long double &A, long double &B, long double &C) {
  pair<long double, long double> c = (a + b) / 2;
  A = (a - b).first;
  B = (a - b).second;
  C = A * c.first + B * c.second;
}
void solve(long double a, long double b, long double c, long double d,
           long double e, long double f, long double &x, long double &y) {
  x = (c * e - b * f) / (a * e - b * d);
  y = (c * d - a * f) / (b * d - a * e);
}
pair<long double, long double> inner(pair<long double, long double> A,
                                     pair<long double, long double> B,
                                     pair<long double, long double> C) {
  long double a, b, c, d, e, f;
  line(A, B, a, b, c);
  line(A, C, d, e, f);
  long double x, y;
  solve(a, b, c, d, e, f, x, y);
  return pair<long double, long double>(x, y);
}
void work() {
  long double ans = -1;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      for (int k = j + 1; k <= n; ++k) {
        long double a = sqrgetdis(p[i], p[j]), b = sqrgetdis(p[i], p[k]),
                    c = sqrgetdis(p[j], p[k]);
        if (a + b > c && a + c > b && b + c > a) {
          pair<long double, long double> x = inner(p[i], p[j], p[k]);
          long double t = 1e40;
          for (int d = 1; d <= n; ++d)
            if (d != i && d != j && d != k) t = min(t, getdis(x, p[d]));
          if (t >= getdis(x, p[i])) ans = max(ans, getdis(x, p[i]));
        }
        if (a + b == c || a + c == b || b + c == a) {
          pair<long double, long double> x, y;
          if (a + b == c) {
            x = p[j] + p[k] - p[i];
            y = (p[j] + p[k]) / 2;
          }
          if (a + c == b) {
            x = p[i] + p[k] - p[j];
            y = (p[i] + p[k]) / 2;
          }
          if (b + c == a) {
            x = p[i] + p[j] - p[k];
            y = (p[i] + p[j]) / 2;
          }
          if (p[lower_bound(p + 1, p + n + 1, x) - p] == x) {
            x = y;
            long double t = 1e40;
            for (int d = 1; d <= n; ++d)
              if (d != i && d != j && d != k) t = min(t, getdis(x, p[d]));
            if (t >= getdis(x, p[i])) ans = max(ans, getdis(x, p[i]));
          }
        }
      }
  if (ans == -1)
    puts("-1");
  else
    printf("%.20lf\n", (double)ans);
}
int main() {
  init();
  work();
  return 0;
}
