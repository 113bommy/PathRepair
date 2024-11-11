#include <bits/stdc++.h>
template <typename Arg1>
void ZZ(const char* name, Arg1&& arg1) {
  std::cout << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cout.write(names, comma - names) << " = " << arg1;
  ZZ(comma, args...);
}
using namespace std;
int n, m, k;
vector<int> w, parent, b, v, nxt, sz, smb, smw, adj[1009];
int dp[1009][1009], vis[1009][1009];
int find(int x) {
  while (parent[x] != x) x = parent[x];
  return x;
}
void unite(int x, int y) {
  int px = find(x);
  int py = find(y);
  if (px == py) return;
  if (sz[px] <= sz[py]) {
    parent[py] = px;
    sz[px] += sz[py];
  } else {
    parent[px] = py;
    sz[py] += sz[px];
  }
}
int solve(int idx, int rem) {
  if (rem < 0) return -2000000000;
  if (idx == v.size()) return 0;
  if (vis[idx][rem] == 1) return dp[idx][rem];
  vis[idx][rem] = 1;
  return dp[idx][rem] = max(b[v[idx]] + solve(nxt[idx], rem - w[v[idx]]),
                            max(smb[idx] + solve(nxt[idx], rem - smw[idx]),
                                solve(idx + 1, rem)));
}
int main() {
  ios::sync_with_stdio(false);
  int i, j, x, y;
  cin >> n >> m >> k;
  parent.resize(n + 1);
  sz.resize(n + 1);
  for (i = 1; i <= n; i++) parent[i] = i;
  w.resize(n + 1);
  for (i = 1; i <= n; i++) cin >> w[i];
  b.resize(n + 1);
  for (i = 1; i <= n; i++) cin >> b[i];
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    unite(x, y);
  }
  for (i = 1; i <= n; i++) adj[find(i)].push_back(i);
  int idx = 0;
  for (i = 1; i <= 1000; i++) {
    int sumw = 0;
    int sumb = 0;
    for (j = 0; j < adj[i].size(); j++) {
      sumw += w[adj[i][j]];
      sumb += b[adj[i][j]];
    }
    for (j = 0; j < adj[i].size(); j++) {
      v.push_back(adj[i][j]);
      nxt.push_back(idx + adj[i].size());
      smw.push_back(sumw);
      smb.push_back(sumb);
    }
    idx += adj[i].size();
  }
  cout << solve(0, k) << "\n";
  return 0;
}
