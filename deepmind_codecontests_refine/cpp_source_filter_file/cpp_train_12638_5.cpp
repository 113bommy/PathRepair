#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-10;
inline int read() {
  static char ch;
  bool sgn = false;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') sgn = true;
  int res = ch - 48;
  while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
  return sgn ? -res : res;
}
struct omg {
  int x, y;
  double ang;
};
const int N = 2e4 + 5;
omg p[N];
int x[N], y[N];
int Q[N];
bool cmp(omg a, omg b) { return a.ang < b.ang; }
int dis(int i) { return p[i].x * p[i].x + p[i].y * p[i].y; }
int main() {
  int i, j, k, n, m, t, h;
  double ans = -1 << 30;
  n = read();
  for (i = 1; i <= n; i++) {
    x[i] = read();
    y[i] = read();
  }
  for (i = 1; i <= n; i++) {
    m = 0;
    for (j = 1; j <= n; j++) {
      if (i == j) continue;
      m++;
      p[m].x = x[j] - x[i];
      p[m].y = y[j] - y[i];
      p[m].ang = atan2(p[m].y, p[m].x);
      if (p[m].ang < 0) p[m].ang += 2 * PI;
    }
    sort(p + 1, p + m + 1, cmp);
    for (j = m + 1; j <= 2 * m; j++) {
      p[j].x = p[j - m].x;
      p[j].y = p[j - m].y;
      p[j].ang = p[j - m].ang + 2 * PI;
    }
    k = 1;
    t = 0;
    h = 1;
    for (j = 1; j <= m; j++) {
      while (p[k].ang - p[j].ang < PI / 3 && k < 2 * m) k++;
      while (p[k].ang - p[j].ang >= PI / 3 && p[k].ang - p[j].ang < PI) {
        while (t - h >= 0 && dis(Q[t]) < dis(k)) t--;
        t++;
        Q[t] = k;
        k++;
      }
      while (t - h >= 0 && p[Q[h]].ang - p[j].ang < PI / 3) h++;
      if (t - h >= 0) ans = max(ans, min((double)dis(j), (double)dis(Q[h])));
    }
  }
  printf("%.8lf", sqrt(ans) / 2);
}
