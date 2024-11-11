#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct line {
  int a, b, c;
} e[2010];
struct point {
  double x, y;
} a[2010];
int n, ans;
double k[2010];
int dcmp(double x) { return (x > eps) - (x < -eps); }
point calc(line x) {
  if (x.a == 0) return (point){0, 1.0 * x.c / x.b};
  if (x.b == 0) return (point){1.0 * x.c / x.a, 0};
  double a = 1.0 * x.c / x.a, b = 1.0 * x.c / x.b, d = sqrt(a * a + b * b),
         c = a * b / d, e = a * c / b;
  return (point){a * (d - e) / d, b * e / d};
}
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].c), a[i] = calc(e[i]);
  for (int i = 1; i <= n; i++)
    if ((!dcmp(a[i].x)) && (!dcmp(a[i].y))) ans++;
  ans = (ans == 2) ? (n - 2) : 0;
  for (int i = 1; i <= n; i++)
    if ((dcmp(a[i].x)) || (dcmp(a[i].y))) {
      int m = 0, t = 0;
      for (int j = i + 1; j <= n; j++)
        if ((dcmp(a[j].x)) || (dcmp(a[j].y)))
          if (!dcmp(a[i].x - a[j].x))
            t++;
          else
            k[++m] = (a[i].y - a[j].y) / (a[i].x - a[j].x);
      ans += t * (t - 1) / 2;
      sort(k + 1, k + m + 1);
      for (int j = 1, s = 0; j <= m; j++)
        if (dcmp(k[j - 1] - k[j]))
          s = 1;
        else
          ans += s, s++;
    }
  printf("%d", ans);
}
int main() {
  work();
  return 0;
}
