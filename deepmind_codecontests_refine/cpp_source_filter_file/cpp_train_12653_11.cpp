#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 4;
const int logn = 20;
int fa[maxn][logn], fb[maxn][logn];
int Log[maxn], n;
int Cal(int l, int r) {
  int k = Log[r - l + 1];
  int x = max(fa[l][k], fa[r - (1 << k) + 1][k]);
  int y = min(fb[l][k], fb[r - (1 << k) + 1][k]);
  return x - y;
}
int GetLeft(int x, int y) {
  int l = x, r = y, ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    int v = Cal(x, m);
    if (v <= 0) {
      if (v == 0) ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  return ans;
}
int GetRight(int x, int y) {
  int l = x, r = y, ans = -2;
  while (l <= r) {
    int m = (l + r) >> 1;
    int v = Cal(x, m);
    if (v >= 0) {
      if (v == 0) ans = m;
      l = m + 1;
    } else
      r = m - 1;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &fa[i][0]);
  for (int i = 1; i <= n; ++i) scanf("%d", &fb[i][0]);
  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 1; i + (1 << (j - 1)) <= n; ++i) {
      fa[i][j] = max(fa[i][j - 1], fa[i + (1 << (j - 1))][j - 1]);
      fb[i][j] = min(fb[i][j - 1], fb[i + (1 << (j - 1))][j - 1]);
    }
  for (int i = 0; (1 << i) <= n; ++i) Log[1 << i] = i;
  for (int i = 0; i <= n; ++i)
    if (!Log[i]) Log[i] = Log[i - 1];
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x = GetLeft(i, n);
    int y = GetRight(i, n);
    ans += (y - x + 1);
  }
  printf("%I64d", ans);
}
