#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, c = getchar();
  while (c < 48) c == '-' && (f = -1), c = getchar();
  while (c > 47) x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int MAXN = 2005;
const int MOD = 1000000007;
int a[MAXN][MAXN], c[MAXN];
int bin[MAXN], s[MAXN][MAXN];
int n, m, k;
inline int dfs(int x, int y) {
  if (y == m + 1) x++, y = 1;
  if (x == n + 1) return 1;
  int t = s[x - 1][y] | s[x][y - 1];
  int res = 0, f = -1;
  for (int i = (1 << k) - 1 - t; i; i -= i & -i) {
    int u = bin[i & -i];
    if (a[x][y] != 0 && a[x][y] != u + 1) continue;
    s[x][y] = t | (1 << u);
    c[u]++;
    if (c[u] == 1) {
      if (f == -1) f = dfs(x, y + 1);
      res += f;
    } else
      res += dfs(x, y + 1);
    res %= MOD;
    c[u]--;
  }
  return res;
}
int main(int argc, char const *argv[]) {
  n = read();
  m = read();
  k = read();
  if (n + m - 1 > k) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      a[i][j] = read();
      c[a[i][j] - 1]++;
    }
  for (int i = 0; i < k; i++) bin[1 << i] = i;
  printf("%lld\n", dfs(1, 1));
  return 0;
}
