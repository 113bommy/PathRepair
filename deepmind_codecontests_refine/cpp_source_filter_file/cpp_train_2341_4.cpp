#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 5;
const long long L = 2e6 + 5;
const long long inf = 1e9 + 7;
long long read() {
  long long s = 0;
  char c = getchar(), lc = '+';
  while (c < '0' || '9' < c) lc = c, c = getchar();
  while ('0' <= c && c <= '9') s = s * 10 + c - '0', c = getchar();
  return lc == '-' ? -s : s;
}
void error() {
  puts("NO");
  exit(0);
}
long long t[N], x[N], y[N], n, l, ans[2][L];
struct node {
  long long k, b, x;
  bool operator<(const node &a) const { return b < a.b; }
} a[N];
void solve(long long *x, long long *ans) {
  for (long long i = 1; i < l; i++) ans[i] = inf;
  for (long long i = 1; i <= n; i++) {
    a[i].k = t[i] / l;
    a[i].b = t[i] % l;
    a[i].x = x[i];
  }
  long long cnt = n + 1;
  a[cnt] = (node){-1, l, 0};
  sort(a + 1, a + 1 + cnt);
  long double L = -inf;
  for (long long i = 0; i < cnt; i++)
    if (a[i].k - a[i + 1].k > 0) {
      L = max(L, 1.0L * (a[i].x - a[i + 1].x) / (a[i].k - a[i + 1].k));
      if (L > 1.0L * (a[i].x - a[i + 1].x + a[i + 1].b - a[i].b) /
                  (a[i].k - a[i + 1].k))
        error();
    } else {
      L = max(L, 1.0L * (a[i + 1].x - a[i].x + a[i].b - a[i + 1].b) /
                     (a[i + 1].k - a[i].k));
      if (L > 1.0L * (a[i + 1].x - a[i].x) / (a[i + 1].k - a[i].k)) error();
    }
  if (L == -inf) {
    ans[l] = inf;
    for (long long i = 1; i <= cnt; i++) ans[a[i].b] = a[i].x;
  } else {
    long long Sn = ceil(L);
    ans[l] = Sn;
    for (long long i = 1; i <= cnt; i++) ans[a[i].b] = a[i].x - Sn * a[i].k;
  }
  int las = 0;
  for (long long i = 1; i <= l; i++)
    if (ans[i] < inf) {
      if (ans[i] - ans[las] > i - las || ans[i] < ans[las]) error();
      for (int j = las + 1; j <= i; ++j) {
        if (ans[j - 1] <= ans[i])
          ans[j] = ans[j - 1] + 1;
        else
          ans[j] = ans[j - 1];
      }
      las = i;
    }
  if (L == -inf)
    for (long long i = 1; i <= l; i++)
      if (ans[i] == inf) ans[i] = ans[i - 1];
  for (long long i = l; i >= 1; i--) ans[i] = ans[i] - ans[i - 1];
}
signed main() {
  n = read(), l = read();
  for (long long i = 1; i <= n; i++) {
    t[i] = read();
    long long tmpx = read(), tmpy = read();
    if ((tmpx + tmpy + t[i]) % 2) error();
    x[i] = (tmpx + tmpy + t[i]) / 2;
    y[i] = (tmpy - tmpx + t[i]) / 2;
  }
  solve(x, ans[0]);
  solve(y, ans[1]);
  for (long long i = 1; i <= l; i++) {
    if (ans[0][i] && ans[1][i]) putchar('U');
    if (ans[0][i] && !ans[1][i]) putchar('R');
    if (!ans[0][i] && ans[1][i]) putchar('L');
    if (!ans[0][i] && !ans[1][i]) putchar('D');
  }
  return 0;
}
