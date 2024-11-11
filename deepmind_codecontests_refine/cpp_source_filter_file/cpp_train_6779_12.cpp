#include <bits/stdc++.h>
using namespace std;
const long long MXN = 3e5 + 10;
const long long Mod = 998244353;
long long power(long long a, long long b) {
  return (!b ? 1 : power(a * a % Mod, b / 2) * (b & 1LL ? a : 1) % Mod);
}
long long inv(long long x) { return power(x, Mod - 2); }
long long mkay(long long &x) {
  if (x >= Mod) x -= Mod;
}
long long n;
long long dp1[MXN], dp2[MXN], dp3[MXN];
vector<long long> adj[MXN];
void dfs(long long u, long long par) {
  dp1[u] = dp3[u] = 1;
  long long zero = 0;
  for (auto v : adj[u]) {
    if (v == par) continue;
    dfs(v, u);
    dp3[u] = dp3[u] * (dp2[v] + dp3[v]) % Mod;
    long long now = (dp2[v] * 2 + dp3[v]) % Mod;
    if (now == 0)
      zero++;
    else
      dp1[u] = dp1[u] * now % Mod;
  }
  for (auto v : adj[u]) {
    if (v == par) continue;
    long long now = (dp2[v] * 2 + dp3[v]) % Mod, t;
    if (zero == 0)
      t = dp1[u] * inv(now);
    else
      t = (zero >= 2 ? 0 : (now == 0 ? dp1[u] : 0));
    t = t * dp1[v] % Mod;
    mkay(dp2[u] += t);
  }
  if (zero) dp1[u] = 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  dfs(1, 0);
  cout << (dp2[1] + dp3[1]) % Mod << '\n';
  return 0;
}
