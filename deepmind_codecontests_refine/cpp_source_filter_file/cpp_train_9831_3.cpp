#include <bits/stdc++.h>
using namespace std;
int n, m;
int b[5010];
int a[5010];
int g[5010];
int c[1000010];
int tp = 0;
int p[1000010];
int gcd(int x, int y) {
  if (x % y == 0)
    return y;
  else
    return gcd(y, x % y);
}
void init() {
  int maxa = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    if (a[i] > maxa) maxa = a[i];
  }
  for (int i = 0; i < m; ++i) scanf("%d", b + i);
  for (int i = 2; i < maxa / i; ++i)
    if (c[i] == 0) {
      p[tp] = i;
      tp++;
      int t = i;
      while (true) {
        t += i;
        if (t > 1000000) break;
        c[t] = 1;
      }
    }
  g[0] = a[0];
  for (int i = 1; i < n; ++i) g[i] = gcd(g[i - 1], a[i]);
}
int value(int x) {
  int ret = 0;
  for (int i = 0; i < m; ++i)
    while (x % b[i] == 0) {
      ret--;
      x /= b[i];
    }
  for (int i = 0; i < tp && p[i] <= x / p[i]; ++i)
    while (x % p[i] == 0) {
      ret++;
      x /= p[i];
    }
  if (x != 1) ret++;
  return ret;
}
void work() {
  for (int i = n - 1; i >= 0; --i)
    if (value(g[i]) < 0) {
      for (int j = 0; j <= i; ++j) {
        a[j] /= g[i];
        g[j] /= g[i];
      }
    }
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += value(a[i]);
  printf("%d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
