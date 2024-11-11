#include <bits/stdc++.h>
using namespace std;
int Read() {
  int X = 0, flag = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    X = (X << 1) + (X << 3) + ch - 48, ch = getchar();
  return X * flag;
}
void Write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) Write(x / 10);
  putchar(x % 10 + 48);
}
int n;
int edgenum, Edge[500005 << 1], nxt[500005], head[500005];
inline void addedge(int x, int y) {
  Edge[++edgenum] = y;
  nxt[edgenum] = head[x];
  head[x] = edgenum;
}
int dp[500005];
void dfs(int now, int fa) {
  int prod = 1;
  for (int i = head[now]; i; i = nxt[i]) {
    int tmp = Edge[i];
    if (tmp == fa) continue;
    dfs(tmp, now);
    prod = (long long)prod * (dp[tmp] + 1) % 998244353 * 499122177 % 998244353;
  }
  dp[now] = (1 - prod + 998244353) % 998244353;
}
int main() {
  n = Read();
  for (int i = 1; i < n; i++) {
    int x = Read(), y = Read();
    addedge(x, y);
    addedge(y, x);
  }
  dfs(1, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + dp[i]) % 998244353;
  for (int i = 1; i < n; i++) ans = ans * 2 % 998244353;
  ans = ans * 2 % 998244353;
  Write(ans);
  (putchar('\n'));
  return 0;
}
