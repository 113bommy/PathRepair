#include <bits/stdc++.h>
using namespace std;
long long rd() {
  long long rx = 0, fx = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') fx = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) {
    rx = rx * 10 + c - 48;
    c = getchar();
  }
  return rx * fx;
}
const long long N = 2e5 + 50, V = 2e6 + 50;
long long n, T;
long long ans[V];
struct Node {
  long long f, t, s;
} p[2][N];
struct Data {
  long long t, s;
} pl[N];
bool cmp(const Node &a, const Node &b) { return a.t < b.t; }
bool Solve(long long c) {
  long long i, j, L, R, f1, f2, s1, s2, dt, num, h, top, now, der;
  L = 0;
  R = T;
  sort(p[c] + 1, p[c] + n + 1, cmp);
  for (i = 1; i < n; i++) {
    f1 = p[c][i].f;
    f2 = p[c][i + 1].f;
    s1 = p[c][i].s;
    s2 = p[c][i + 1].s;
    dt = p[c][i + 1].t - p[c][i].t;
    if (f2 == f1 + dt) {
      if (s2 - s1 < 0 || s2 - s1 > dt) return 0;
    } else if (f2 > f1 + dt) {
      num = (f2 - dt - f1) / T;
      L = max(L,
              (long long)ceil((long double)(s2 - s1 - dt) / (long double)num));
      R = min(R, (long long)floor((long double)(s2 - s1) / (long double)num));
    } else {
      num = (f1 + dt - f2) / T;
      R = min(R,
              (long long)floor((long double)(s1 + dt - s2) / (long double)num));
      L = max(L, (long long)ceil((long double)(s1 - s2) / (long double)num));
    }
  }
  f1 = p[c][n].f;
  s1 = p[c][n].s;
  if (f1 <= T) {
    L = max(L, s1);
    R = min(R, T - f1 + s1);
  } else {
    dt = T - p[c][n].t;
    num = (f1 + dt - T) / T;
    R = min(R,
            (long long)floor((long double)(s1 + dt) / (long double)(num + 1)));
    L = max(L, (long long)ceil((long double)(s1) / (long double)(num + 1)));
  }
  if (L > R) return 0;
  h = L;
  for (i = 1; i <= n; i++) {
    pl[i].t = p[c][i].t;
    num = (p[c][i].f - 1) / T;
    pl[i].s = p[c][i].s - num * h;
  }
  pl[n + 1].t = T;
  pl[n + 1].s = h;
  top = 0;
  now = 0;
  for (i = 1; i <= n + 1; i++) {
    der = pl[i].s - now;
    for (j = top + 1; j <= top + der; j++) ans[j] += (1ll << c);
    top += der;
    now += der;
    top = pl[i].t;
  }
  return 1;
}
int main() {
  long long i, t, x, y, w;
  n = rd();
  T = rd();
  for (i = 1; i <= n; i++) {
    t = rd();
    x = rd();
    y = rd();
    p[0][i].f = p[1][i].f = t;
    p[0][i].t = p[1][i].t = (t - 1) % T + 1;
    w = x + y + t;
    if (w < 0 || (w & 1ll)) {
      puts("NO");
      return 0;
    }
    p[0][i].s = w >> 1;
    w = y - x + t;
    if (w < 0 || (w & 1ll)) {
      puts("NO");
      return 0;
    }
    p[1][i].s = w >> 1;
  }
  if (Solve(0) == 0) {
    puts("NO");
    return 0;
  }
  if (Solve(1) == 0) {
    puts("NO");
    return 0;
  }
  for (i = 1; i <= T; i++) {
    if (ans[i] == 3) putchar('U');
    if (ans[i] == 2) putchar('L');
    if (ans[i] == 1) putchar('R');
    if (ans[i] == 0) putchar('D');
  }
  return 0;
}
