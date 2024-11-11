#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 1e9;
const int del = 728729;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
long long mod;
long long mark[maxn];
long long com;
vector<long long> adj[maxn];
long long u;
long long v;
long long n;
long long m;
long long ans = 1;
long long t;
void dfs(int v) {
  mark[v] = 1;
  com++;
  for (int u : adj[v]) {
    if (!mark[u]) dfs(u);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> mod;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (mark[i]) {
      continue;
    }
    com = 0;
    dfs(i);
    ans = ans * com % mod;
    t++;
  }
  if (t == 1) {
    return cout << 1 % mod, 0;
  }
  for (int i = 0; i < t - 2; i++) {
    ans = ans * n % mod;
  }
  cout << ans % mod;
  return 0;
}
