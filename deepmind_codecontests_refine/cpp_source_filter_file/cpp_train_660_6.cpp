#include <bits/stdc++.h>
#pragma GCC optimize("O2")
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
using namespace std;
const int maxn = 1000 * 100 + 5;
const long long inf = 9223372036854775807;
const long long mod = 1e9 + 7;
int n, m, k, mark[maxn], par[maxn], b, cnt = 0, h[maxn];
vector<int> vc, adj[maxn];
void dfs(int v) {
  cnt++;
  mark[v] = 1;
  if (b == 0) vc.push_back(v);
  for (auto u : adj[v]) {
    if (u != par[v]) {
      if (mark[u]) {
        if (b == 0 && h[v] - h[u] > k) {
          b = 1;
          vc.push_back(u);
        }
      } else {
        h[u] = h[v] + 1;
        par[u] = v;
        dfs(u);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  dfs(1);
  int x = vc[vc.size() - 1], g = 0, y = 0;
  for (int i = 0; i < vc.size() - 1; i++) {
    if (vc[i] == x) g = 1;
    if (g) y++;
  }
  cout << y << endl;
  g = 0;
  for (int i = 0; i < vc.size() - 1; i++) {
    if (vc[i] == x) g = 1;
    if (g) cout << vc[i] << " ";
  }
}
