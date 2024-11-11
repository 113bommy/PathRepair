#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300100;
vector<int> g[MAXN];
int st[MAXN], ind;
bool mk[MAXN], mk2[MAXN];
bool cycle(int u) {
  if (mk2[u]) {
    return true;
  }
  if (mk[u]) {
    return false;
  }
  mk[u] = mk2[u] = true;
  for (auto v : g[u]) {
    if (cycle(v)) {
      return true;
    }
  }
  mk2[u] = false;
  st[--ind] = u;
  return false;
}
int n, m;
string s;
int dp[MAXN];
int solve(char c) {
  fill(dp, dp + n + 1, 0);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int u = st[i];
    if (s[u - 1] == c) {
      dp[u]++;
    }
    for (auto v : g[u]) {
      dp[v] = max(dp[v], dp[u]);
    }
    mx = max(mx, dp[u]);
  }
  return mx;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  ind = n;
  for (int u = 1; u <= n; u++) {
    if (cycle(u)) {
      cout << "-1\n";
      return 0;
    }
  }
  int sol = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    sol = max(sol, solve(c));
  }
  cout << sol << '\n';
}
