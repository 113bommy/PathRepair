#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long t = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') t = t * 10 + c - 48, c = getchar();
  return t * f;
}
int dp[201][201][151], n, m, x, y;
char z[5];
char v[50001];
int head[2001], nxt[50001], poi[50001], cnt;
inline void add(int x, int y, char c) {
  poi[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
  v[cnt] = c;
}
inline int Dfs(int x, int y, int las) {
  if (dp[x][y][las] != 0) return dp[x][y][las];
  int win = -1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (v[i] < las) continue;
    int tmp = Dfs(y, poi[i], v[i]);
    if (tmp == -1) win = 1;
  }
  return dp[x][y][las] = win;
}
int main() {
  n = read();
  m = read();
  for (long long i = 1; i <= m; ++i)
    x = read(), y = read(), scanf("%s", z), add(x, y, z[0]);
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= n; ++j) dp[i][j][0] = Dfs(i, j, 0);
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= n; ++j)
      if (dp[i][j][0] == -1)
        putchar('B');
      else
        putchar('A');
    puts("");
  }
}
