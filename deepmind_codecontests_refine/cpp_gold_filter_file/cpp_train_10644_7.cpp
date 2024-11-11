#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const double eps = 1e-9;
int n, k, q, len;
double f[N], d[N], w[N];
struct node {
  int x, y;
} e[N], g[N];
inline int read() {
  int num = 0;
  char t = '+', g = getchar();
  while (g < 48 || 57 < g) t = g, g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  if (t == '-') return -num;
  return num;
}
inline bool tmp(node a, node b) { return atan2(a.y, a.x) < atan2(b.y, b.x); }
inline bool cmp(node a, node b) {
  if (abs(a.x) == abs(b.x)) return abs(a.y) < abs(b.y);
  return abs(a.x) < abs(b.x);
}
inline bool check(double a, double b) {
  return (a - b <= eps && a - b >= -eps);
}
inline void solve() {
  sort(g + 1, g + q + 1, cmp);
  int a = 0, b = 0, c = 0;
  double sum = 0, ans = 0;
  for (int i = 1; i <= q; i++)
    d[i] = sqrt(1.0 * g[i].x * g[i].x + 1.0 * g[i].y * g[i].y),
    f[i] = d[i] - d[i - 1];
  double f1 = 0, f2 = 0, f3 = 0;
  while (a + b < min(k, q)) {
    double ans1 = sum + (d[q - a] - d[b]) * (a + 1) * (k - a - 1);
    double ans2 = sum + (d[q - a] - d[b + 1]) * a * (k - a) +
                  f[b + 1] * (a + 1) * (k - a - 1);
    c++;
    double val = max(ans1, ans2) + f1 * c * c + f2 * c + f3;
    if (ans1 >= ans2)
      sum += f[q - a] * (a + 1) * (k - a - 1), a++;
    else
      f1 += -f[b + 1], f2 += (k + 2 * b) * f[b + 1],
          f3 += -1.0 * b * (k + b) * f[b + 1], b++;
    w[++len] = val - ans, ans = val;
  }
}
int main() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    e[i].x = read(), e[i].y = read();
    if (e[i].x == 0 && e[i].y == 0) i--, n--;
  }
  sort(e + 1, e + n + 1, tmp);
  for (int i = 1; i <= n; i++) {
    int x = i;
    q = 0;
    while (check(atan2(e[i].y, e[i].x), atan2(e[x + 1].y, e[x + 1].x)) &&
           x + 1 <= n)
      x++;
    for (int c = i; c <= x; c++) g[++q] = e[c];
    i = x, solve();
  }
  double sum = 0;
  w[++len] = 0;
  sort(w + 1, w + len + 1);
  for (int i = 1; i <= k; i++) sum += w[len - i + 1];
  printf("%.9lf\n", sum);
}
