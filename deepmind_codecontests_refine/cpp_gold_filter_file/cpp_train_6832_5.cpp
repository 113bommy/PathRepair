#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int k, n, m, cnt, tot;
pair<double, double> g, a[N], c[N];
double d[N], b[N];
int Ans;
inline bool cmp(double a, double b) { return fabs(a - b) < 1e-7; }
inline pair<double, double> Get(pair<double, double> a,
                                pair<double, double> b) {
  return pair<double, double>((a.first + b.first) / 2,
                              (a.second + b.second) / 2);
}
inline double Dis(pair<double, double> a, pair<double, double> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}
inline bool Check(double k) {
  double t = g.first + k * g.second;
  for (int i = 1; i <= cnt; i++) d[i] = c[i].first + k * c[i].second - t;
  sort(d + 1, d + cnt + 1);
  for (int i = 1; i <= (cnt >> 1); i++)
    if (!cmp(d[i], -d[cnt - i + 1])) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf", &a[i].first, &a[i].second), g.first += a[i].first,
        g.second += a[i].second;
  g.first /= n;
  g.second /= n;
  for (int i = 1; i <= n; i++) {
    bool fl = 0;
    for (int j = 1; j <= n; j++)
      if (i != j) {
        pair<double, double> t = Get(a[i], a[j]);
        if (cmp(t.first, g.first) && cmp(t.second, g.second)) {
          fl = 1;
          break;
        }
      }
    if (!fl) c[++cnt] = a[i];
  }
  if (cnt <= 2) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= cnt; i++) d[i] = c[i].second - g.second;
  sort(d + 1, d + cnt + 1);
  bool fl = 0;
  for (int i = 1; i <= (cnt >> 1); i++)
    if (!cmp(d[i], -d[cnt - i + 1])) {
      fl = 1;
      break;
    }
  Ans += (!fl);
  for (int i = 1; i <= cnt; i++) {
    pair<double, double> t = Get(c[1], c[i]);
    if (t.second == g.second) continue;
    b[++tot] = (g.first - t.first) / (t.second - g.second);
  }
  sort(b + 1, b + tot + 1);
  Ans += Check(b[1]);
  for (int i = 2; i <= tot; i++)
    if (!cmp(b[i], b[i - 1])) Ans += Check(b[i]);
  cout << Ans << endl;
  return 0;
}
