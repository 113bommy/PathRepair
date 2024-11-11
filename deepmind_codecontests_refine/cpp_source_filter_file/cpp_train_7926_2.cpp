#include <bits/stdc++.h>
using namespace std;
const int N = 1005, mod = 998244353;
char s[N];
vector<pair<int, int>> e[N << 1];
int n, fl, vis[N], col[N];
void dfs(int u, int c) {
  if (vis[u]) {
    if (c != col[u]) return (void)(fl = 0);
    return;
  }
  col[u] = c, vis[u] = 1;
  for (auto p : e[u]) dfs(p.first, c ^ p.second);
}
void add(int i, int j, int k) {
  e[i].push_back({j, k}), e[j].push_back({i, k});
}
signed main() {
  cin >> (s + 1);
  int sum = 0;
  n = strlen(s + 1);
  for (int len = 1; len < n; ++len) {
    for (int i = 1; i <= n + n + 2; ++i) e[i].clear(), col[i] = vis[i] = 0;
    for (int i = 1; i <= n / 2; ++i) add(i, n - i + 1, 0);
    for (int i = 1; i <= len / 2; ++i) add(i + n, n + len - i + 1, 0);
    for (int i = len + 1; i <= n; ++i) add(n + i, n + n + 2, 0);
    add(1, n + n + 1, 0), add(n + 1, n + n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      int u = n - i + 1;
      if (s[u] == '?') continue;
      add(i + n, i, s[u] - '0');
    }
    fl = 1;
    int cnt = 0;
    for (int i = 1; i <= n + len; ++i)
      if (!vis[i]) dfs(i, 0), ++cnt;
    int ans = fl;
    for (int i = 1; i < cnt; ++i) ans = (ans + ans) % mod;
    sum = (sum + ans) % mod;
  }
  cout << sum;
}
