#include <bits/stdc++.h>
using namespace std;
int n, m, x[20005], y[20005], f[20005], g[20005], cnt, p, ans;
char s[40005];
void solve(int x0, int y0, int x1, int y1) {
  if (x1 - x0 + y1 - y0 == 1) {
    s[cnt++] = y1 == y0 ? 'C' : 'S';
    return;
  }
  int k = (x0 + y0 + x1 + y1) >> 1;
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= min(y1, k - i); j++) {
      if (j ^ y0) f[j] = max(f[j], f[j - 1]);
      if (i + j == k) g[i] += f[j];
      f[j] += (x[i] + y[j]) % p;
    }
  }
  memset(f, 0, sizeof(f));
  for (int i = x1; i >= x0; i--) {
    for (int j = y1; j >= max(y0, k - i); j--) {
      if (j ^ y1) f[j] = max(f[j], f[j + 1]);
      f[j] += (x[i] + y[j]) % p;
      if (i + j == k) g[i] += f[j];
    }
  }
  int mx = -1, id;
  for (int i = x0; i <= x1; i++)
    if ((k - i) >= y0 && (k - i) <= y1 && g[i] > mx) {
      mx = g[i];
      id = i;
    }
  solve(x0, y0, id, k - id);
  solve(id, k - id, x1, y1);
  ans = mx;
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  for (int i = 0; i < m; i++) scanf("%d", &y[i]);
  if (n + m == 2) return printf("%d\n", (x[0] + y[0]) % p), 0;
  solve(0, 0, n - 1, m - 1);
  printf("%d\n", ans);
  puts(s);
  return 0;
}
