#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
const double eps = 1e-12;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() {
  return pp1 == pp2 &&
                 (pp2 = (pp1 = buf) + fread(buf, 1, 1 << 12, stdin), pp1 == pp2)
             ? EOF
             : *pp1++;
}
inline int read() {
  int x = 0;
  ny = 1;
  while (nc = gc(), (nc < 48 || nc > 57) && nc != EOF)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  x = nc - 48;
  while (nc = gc(), 47 < nc && nc < 58 && nc != EOF)
    x = (x << 3) + (x << 1) + (nc ^ 48);
  return x * ny;
}
int n;
long long ans;
double x[MAXN], y[MAXN];
inline int sig(double x) { return x < -eps ? -1 : x > eps ? 1 : 0; }
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int a = read(), b = read(), c = read();
    x[i] = (double)(a * c) / (a * a + b * b),
    y[i] = (double)(b * c) / (a * a + b * b);
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    static double p[MAXN];
    int cnt, cntt;
    cnt = cntt = 0;
    for (int j = i + 1; j <= n; j++) {
      if (!sig(x[i] - x[j]) && !sig(y[i] - y[j]))
        cntt++;
      else if (!sig(x[i] - x[j]))
        p[++cnt] = 1e20;
      else
        p[++cnt] = (y[i] - y[j]) / (x[i] - x[j]);
    }
    for (int j = 1; j <= cntt; j++) ans += n - i - j;
    sort(p + 1, p + cnt + 1);
    for (int l = 1, r; l <= cnt; l = r + 1) {
      for (r = l; r < cnt && !sig(p[l] - p[r + 1]); r++)
        ;
      ans += (r - l + 1) * (r - l) / 2;
    }
  }
  cout << ans << "\n";
  return 0;
}
