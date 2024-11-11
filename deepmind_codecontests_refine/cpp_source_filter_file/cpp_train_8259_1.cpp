#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, cnt, head[maxn], to[maxn], nxt[maxn], val[maxn];
inline void add(int x, int y, int z) {
  nxt[++cnt] = head[x];
  head[x] = cnt;
  to[cnt] = y;
  val[cnt] = z;
}
int dp[maxn], f[maxn];
void dfs(int x, int fa) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    dfs(to[i], x);
    dp[x] += dp[to[i]] + val[i];
  }
}
void DFS(int x, int fa) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    if (val[i] == 1) {
      f[to[i]] = f[x] - 1;
    } else
      f[to[i]] = f[x] + 1;
    DFS(to[i], x);
  }
}
int st[maxn], top;
int main() {
  cin >> n;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    add(x, y, 0);
    add(y, x, 1);
  }
  dfs(1, 0);
  f[1] = dp[1];
  DFS(1, 0);
  int res = 1e9;
  for (int i = 1; i <= n; ++i) {
    if (f[i] < res) {
      res = f[i];
      st[top = 1] = i;
    } else if (res == f[i]) {
      st[++top] = i;
    }
  }
  if (res < 0) res = 0;
  cout << res << endl;
  for (int i = 1; i <= top; ++i) cout << st[i] << " ";
  return 0;
}
