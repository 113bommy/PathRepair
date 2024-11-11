#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
const long long M = 998244353;
inline long long mul(long long a, long long b) { return (a * b) % M; }
long long fp[300300];
long long fac(int n) {
  if (n <= 1) return 1;
  if (fp[n] != -1) return fp[n];
  return fp[n] = mul(n, fac(n - 1));
}
long long dfs(int u, int p) {
  long long ac = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == p) continue;
    ac = mul(ac, dfs(v, u));
  }
  int sz = g[u].size();
  if (u != 0) {
    sz--;
    ac = mul(ac, sz + 1);
  }
  ac = mul(ac, fac(sz));
  return ac;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  memset(fp, -1, sizeof(fp));
  g.assign(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  long long res = dfs(0, -1);
  res = mul(res, n);
  cout << res << '\n';
}
