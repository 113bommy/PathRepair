#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const long long INFL = (long long)9e18;
const int MAXINT = ((~0) ^ (1 << 31));
const long long MAXLL = ((~0) ^ ((long long)1 << 63));
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T& a, T b) {
  return (a > b) ? (a = b, true) : false;
}
template <class T>
inline bool maxeq(T& a, T b) {
  return (a < b) ? (a = b, true) : false;
}
const int maxn = 2e5 + 100;
int n, col[maxn];
vector<int> adj[maxn];
int dp_down[maxn], dp_up[maxn];
int mx[maxn], mx2[maxn];
void dfs_down(int v, int p) {
  for (auto u : adj[v]) {
    if (u == p) continue;
    dfs_down(u, v);
    int d = dp_down[u] + (col[v] != col[u]);
    if (d > mx[v]) {
      mx2[v] = mx[v];
      mx[v] = d;
    } else
      maxeq(mx2[v], d);
  }
  dp_down[v] = mx[v];
}
void dfs_up(int v, int p) {
  if (p != -1) {
    int d = ((dp_down[v] + (col[v] != col[p])) == mx[p] ? mx2[p] : mx[p]);
    dp_up[v] = max(d, dp_up[p]) + (col[v] != col[p]);
  }
  for (auto u : adj[v])
    if (u != p) dfs_up(u, v);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < (int)(n + 1); i++) cin >> col[i];
  for (int i = 0; i < (int)(n - 1); i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs_down(1, -1);
  dfs_up(1, -1);
  int ans = INF;
  for (int i = 1; i < (int)(n + 1); i++) mineq(ans, max(dp_up[i], dp_down[i]));
  cout << ans << endl;
}
