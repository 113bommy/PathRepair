#include <bits/stdc++.h>
int n;
struct pp {
  long long a[100001];
  void add(int p, long long d) {
    for (; p <= n; p += p & -p) a[p] += d;
  }
  long long suma(int p) {
    long long ret = 0;
    for (; p; p -= p & -p) ret += a[p];
    return ret;
  }
  long long sum(int l, int r) { return suma(r) - suma(l - 1); }
} mem[30];
int go[5] = {0, 2, 6, 12, 20};
int gao(int x, int m) {
  if (x * 2 <= m)
    return x;
  else
    return m + 2 - x;
}
int a[102400];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 0, t; i <= 4; ++i) {
    t = i * 2 + 2;
    for (int j = 1; j <= n; ++j) mem[go[i] + j % t].add(j, a[j]);
  }
  int m, l, r, t, x;
  for (scanf("%d", &m); m--;) {
    scanf("%d%d%d", &t, &l, &r);
    if (t == 1) {
      r -= a[l];
      a[l] += r;
      for (int i = 0, t; i <= 4; ++i) {
        t = i * 2 + 2;
        mem[go[i] + l % t].add(l, r);
      }
    } else {
      scanf("%d", &x);
      x -= 2;
      t = x * 2 + 2;
      long long ans = 0;
      for (int i = 1; i <= t && i + l <= r + 1; ++i)
        ans += mem[go[x] + (l + i - 1) % t].sum(l, r) * gao(i, t);
      printf("%I64d\n", ans);
    }
  }
}
