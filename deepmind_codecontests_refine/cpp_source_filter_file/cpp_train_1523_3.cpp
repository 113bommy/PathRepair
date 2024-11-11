#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, x[5000 + 5], y[5000 + 5], tot;
int color[5000 + 5];
bool flag;
int ksm(int b, int k) {
  int s = 1;
  while (k > 0) {
    if (k & 1) s = (1ll * s * b) % mod;
    k >>= 1;
    b = (1ll * b * b) % mod;
  }
  return s % mod;
}
int dis(int id1, int id2) {
  return abs(x[id1] - x[id2]) + abs(y[id1] - y[id2]);
}
void clearall() {
  flag = true;
  tot = 0;
  memset(color, 0, sizeof(color));
}
void dfs(int u, int lim) {
  if (flag) {
    for (int i = 1; i <= n; i++) {
      if (flag) {
        if (u == i || dis(u, i) <= lim) continue;
        if (!color[i]) {
          color[i] = color[i] ^ 1;
          dfs(i, lim);
        } else {
          if (color[i] != color[u]) continue;
          flag = false;
          return;
        }
      }
    }
  }
}
bool check(int lim) {
  int i, j;
  clearall();
  for (i = 1; i <= n; i++)
    if (!color[i]) {
      tot++;
      color[i] = 2;
      dfs(i, lim);
      if (!flag) break;
    }
  return flag;
}
int main() {
  int i, ans = -1;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  int l = 0, r = 10000;
  while (l < r - 5) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  for (i = l; i <= r; i++)
    if (check(i)) {
      ans = i;
      break;
    }
  printf("%d\n", ans);
  printf("%d\n", ksm(2, tot));
}
