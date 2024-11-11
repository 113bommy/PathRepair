#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 1000 + 10;
const int maxn5 = 3 * 1000 * 100 + 10;
const int maxnJ = 1000 + 10;
const long long mod = 998244353;
const long long inf = 1LL * 2 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 10;
vector<int> adj[maxn5];
bool leaf[maxn5];
long long perf[maxn5], joda[maxn5], kolyat[maxn5], tak[maxn5];
long long pw(long long a, long long b) {
  return (b == 0 ? 1LL
                 : ((pw(a * a % mod, b / 2) * (b & 1 == 1 ? a : 1LL)) % mod));
}
void dfs(int v, int par = -1) {
  joda[v] = 1, tak[v] = 1;
  int sz = 0, cnt = 0, es;
  for (auto u : adj[v])
    if (u != par) {
      dfs(u, v);
      tak[v] *= perf[u];
      tak[v] %= mod;
      joda[v] *= kolyat[u];
      joda[v] %= mod;
      if (kolyat[u] == 0) cnt++, es = u;
      sz++;
    }
  perf[v] = tak[v];
  if (sz == 0) kolyat[v] = 1;
  if (sz == 0 or cnt > 1) return;
  if (cnt == 0) {
    for (auto u : adj[v])
      if (u != par and joda[u] != 0) {
        perf[v] += joda[u] * (joda[v] * pw(kolyat[u], mod - 2) % mod) % mod;
        perf[v] %= mod;
      }
  } else {
    long long a = 1;
    for (auto u : adj[v])
      if (u != par and u != es) a *= kolyat[u], a %= mod;
    perf[v] += a * joda[es] % mod;
    perf[v] %= mod;
  }
  kolyat[v] = (mod + 2 * perf[v] - tak[v]) % mod;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  cout << perf[1] << endl;
  return 0;
}
