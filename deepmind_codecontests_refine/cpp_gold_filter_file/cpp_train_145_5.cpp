#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> child[MAXN], adj[MAXN];
bitset<MAXN> b;
vector<array<int, 3>> ans;
array<int, 3> o;
void build(int v, int par) {
  b[v] = true;
  for (auto i : adj[v])
    if (i != par && !b[i]) {
      child[v].push_back(i);
      build(i, v);
    }
}
int dfs(int v, int par) {
  b[v] = true;
  vector<int> k;
  for (auto i : adj[v])
    if (b[i] && i != par) k.push_back(i);
  for (auto i : child[v])
    if (!b[i]) {
      int now = dfs(i, v);
      if (now) {
        o[0] = v;
        o[1] = i;
        o[2] = now;
        ans.push_back(o);
      } else
        k.push_back(i);
    }
  int t = k.size();
  for (int i = 0; i + 1 < t; i += 2) {
    o[0] = k[i];
    o[1] = v;
    o[2] = k[i + 1];
    ans.push_back(o);
  }
  return (t % 2 ? k[t - 1] : 0);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  int a1, a2;
  for (int i = 0; i < m; ++i) {
    cin >> a1 >> a2;
    adj[a1].push_back(a2);
    adj[a2].push_back(a1);
  }
  build(1, 0);
  for (int i = 0; i < MAXN; ++i) b[i] = false;
  if (dfs(1, 0)) return cout << "No solution", 0;
  for (auto i : ans) cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
  return 0;
}
