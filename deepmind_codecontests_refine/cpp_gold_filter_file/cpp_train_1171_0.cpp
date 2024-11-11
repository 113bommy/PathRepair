#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, h, a[N], b[N], c[N], d[N], l, f[N], g[N], ans, ansx;
int getsum(int l, int r) {
  if (r < l) return 0;
  return g[r] - g[l - 1];
}
int sum(int s, int z) {
  int R = lower_bound(f + 1, f + 2 * l + 2, s + k) - f, L = z + 1;
  assert((f[R - 1] < s + k && f[R] >= s + k));
  return getsum(L, R - 1);
}
int main() {
  scanf("%d%d%d%d", &n, &h, &m, &k);
  ans = n + 1;
  for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);
  for (int i = 1; i <= n; i++) c[i] = b[i] % (m / 2);
  sort(c + 1, c + n + 1);
  c[0] = -1;
  for (int i = 1; i <= n; i++) {
    if (c[i] != c[i - 1]) f[++l] = c[i];
    g[l]++;
  }
  for (int i = 1; i <= l; i++) f[l + i] = f[i] + m / 2, g[l + i] = g[i];
  f[2 * l + 1] = m + 1;
  for (int i = 2; i <= 2 * l; i++) g[i] += g[i - 1];
  for (int i = 1; i <= l; i++) {
    int res = sum(f[i], i);
    if (res < ans) ansx = f[i], ans = res;
  }
  printf("%d %d\n", ans, (ansx + k) % (m / 2));
  for (int i = 1; i <= n; i++) {
    int x = b[i] % (m / 2);
    if (ansx + k >= m / 2) {
      if (x < (ansx + k) % (m / 2) || x > ansx) printf("%d ", i);
    } else {
      if (x < ansx + k && x > ansx) printf("%d ", i);
    }
  }
  return 0;
}
