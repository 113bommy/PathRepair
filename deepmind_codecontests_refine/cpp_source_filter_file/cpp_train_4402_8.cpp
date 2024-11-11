#include <bits/stdc++.h>
using namespace std;
int n, id;
long long dp[2][30];
int t[2][5000006];
vector<int> adj[5000006];
void add_edge(int x, int pos) {
  int v = 0;
  for (int i = 29; i >= 0; i--) {
    int bit = ((x >> i) & 1);
    if (!t[bit][v]) t[bit][v] = ++id;
    v = t[bit][v];
    adj[v].push_back(pos);
  }
}
void rec(int v, int b = 29) {
  int l = t[0][v], r = t[1][v];
  if (l) rec(l, b - 1);
  if (r) rec(r, b - 1);
  if (!l || !r) return;
  int res = 0;
  int cur = 0;
  for (int u : adj[l]) {
    while (cur < adj[r].size() && adj[r][cur] < u) cur++;
    res += cur;
  }
  dp[0][b] += res;
  dp[1][b] += 1LL * (int)(adj[l]).size() * (int)(adj[r]).size() - res;
}
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    add_edge(x, i);
  }
  rec(0);
  long long cnt = 0;
  int res = 0;
  for (int i = 0; i < 30; i++) {
    cnt += min(dp[0][i], dp[1][i]);
    if (dp[1][i] < dp[0][i]) {
      res += (1 << i);
    }
  }
  cout << cnt << ' ' << res << '\n';
  return 0;
}
