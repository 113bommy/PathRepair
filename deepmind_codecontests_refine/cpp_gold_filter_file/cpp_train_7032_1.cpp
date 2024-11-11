#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const int maxn = 211111;
int n;
vector<int> g[maxn];
long long d[maxn];
long long cyc = 0;
int tt;
void dfs(int v, long long de, int par) {
  ++tt;
  d[v] = de;
  for (auto to : g[v]) {
    if (d[to] != 0) {
      cyc = max(cyc, d[v] - d[to] + 1);
    } else {
      dfs(to, de + 1, v);
    }
  }
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    g[x].push_back(i);
    g[i].push_back(x);
  }
  long long toret = 1;
  for (int v = 1; v <= n; ++v) {
    if (d[v] != 0) continue;
    tt = 0;
    cyc = 0;
    dfs(v, 1, -1);
    int ncy = tt - cyc;
    long long ans = 1, tot = 1;
    for (int i = 1; i <= cyc; ++i) {
      ans = 1ll * ans * 2ll % mod;
    }
    for (int i = 1; i <= ncy; ++i) {
      tot = 2ll * tot % mod;
    }
    toret = 1ll * toret * (((ans - 2ll + mod) % mod) * 1ll * tot % mod) % mod;
  }
  cout << toret << '\n';
  return 0;
}
