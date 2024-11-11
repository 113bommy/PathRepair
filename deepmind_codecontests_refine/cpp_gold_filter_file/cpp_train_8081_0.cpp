#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, M = 30;
vector<int> v[N];
char s[N], t[N], e[N];
int n, k, f[N], ft[N], gt[N], fa[N], dp[N], dq[N], dx[N], len[N], pre[N],
    ch[N][M];
inline void dfs(int u) {
  if (fa[u] != 1) {
    if (len[u] + len[fa[fa[u]]] == len[fa[u]] * 2) ft[u] = ft[fa[u]];
  }
  if (!ft[u]) ft[u] = u, dx[u] = 1919810;
  for (int i = 0; i < v[u].size(); i++) dfs(v[u][i]);
}
inline int getfail(int u, int v) {
  while (1) {
    if (u == 1) return 1;
    if (e[v] == e[v - len[u] - 1]) return ch[u][e[v] - 'a'];
    u = fa[u];
  }
}
inline void solve(int u) {
  if (u == 0) return;
  if (u - pre[u] > 2) printf("%d %d\n", pre[u] / 2 + 1, u / 2);
  solve(pre[u]);
}
int main() {
  scanf("%s%s", s + 1, t + 1), n = strlen(s + 1);
  for (int i = 1; i <= n; i++) e[i * 2 - 1] = s[i], e[i * 2] = t[i];
  k = 1, len[1] = 0, f[1] = 1, fa[1] = 1;
  for (int i = 2; i <= n + n; i++) {
    int c = f[i - 1];
    f[i] = 1;
    while (1) {
      if (e[i] == e[i - len[c] - 1]) {
        if (!ch[c][e[i] - 'a']) {
          ch[c][e[i] - 'a'] = ++k, len[k] = len[c] + 2,
                       fa[k] = getfail(fa[c], i);
          if (fa[k] == 1 && e[i] == e[i - 1]) fa[k] = ch[1][e[i] - 'a'];
          if (fa[k] == k) fa[k] = 1;
        }
        f[i] = ch[c][e[i] - 'a'];
        break;
      }
      if (c == 1) break;
      c = fa[c];
    }
  }
  for (int i = 2; i <= k; i++) v[fa[i]].push_back(i);
  dfs(1), dp[0] = 0;
  for (int i = 2; i <= n * 2; i += 2) {
    dp[i] = 1919810;
    if (e[i - 1] == e[i]) dp[i] = min(dp[i], dp[i - 2]), pre[i] = i - 2;
    int s = f[i];
    while (s > 1) {
      s = ft[s];
      if (dx[s] + len[s] - len[fa[s]] != i)
        dq[s] = dp[i - len[s]];
      else
        dq[s] = min(dq[s], dp[i - len[s]]);
      if (dq[s] == dp[i - len[s]]) gt[s] = i - len[s];
      dp[i] = min(dp[i], dq[s] + 1);
      if (dp[i] == dq[s] + 1) pre[i] = gt[s];
      dx[s] = i, s = fa[s];
    }
  }
  if (dp[n * 2] > n)
    cout << -1 << endl;
  else {
    cout << dp[n * 2] << endl;
    solve(n * 2);
  }
}
