#include <bits/stdc++.h>
using namespace std;
bool isPrime(int val) {
  for (int i = 2; i * i <= val; i++)
    if (val % i == 0) return false;
  return true;
}
int n, m, a[300], cap[222][222], orcap[222][222];
bool vis[300];
vector<int> e[222], g[222];
vector<vector<int>> ans;
void CreateEdge(int from, int to, int c) {
  e[from].push_back(to), e[to].push_back(from);
  cap[from][to] = orcap[from][to] = c, cap[to][from] = orcap[to][from] = 0;
}
bool dive(int v) {
  if (v == n + 1) return true;
  vis[v] = true;
  for (auto u : e[v]) {
    if (vis[u] || cap[v][u] <= 0) continue;
    if (dive(u)) {
      cap[v][u]--;
      cap[u][v]++;
      return true;
    }
  }
  return false;
}
int main() {
  cin >> n;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    cin >> a[i];
    if (a[i] % 2)
      CreateEdge(n, i, 2);
    else
      CreateEdge(i, n + 1, 2);
  }
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if (a[i] % 2 == 0) continue;
    for (__typeof(n) j = (0) - ((0) > (n)); j != (n) - ((0) > (n));
         j += 1 - 2 * ((0) > (n)))
      if (isPrime(a[i] + a[j])) CreateEdge(i, j, 1);
  }
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if (!dive(n)) {
      cout << "Impossible";
      return 0;
    }
    for (__typeof(n + 2) j = (0) - ((0) > (n + 2));
         j != (n + 2) - ((0) > (n + 2)); j += 1 - 2 * ((0) > (n + 2)))
      vis[j] = false;
  }
  for (__typeof(n) v = (0) - ((0) > (n)); v != (n) - ((0) > (n));
       v += 1 - 2 * ((0) > (n)))
    for (auto u : e[v])
      if (u < n && orcap[v][u] - cap[v][u] > 0)
        g[u].push_back(v), g[v].push_back(u);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if (vis[i]) continue;
    vector<int> ans1;
    int p = i, nxt = g[i][0];
    vis[i] = true;
    ans1.push_back(i + 1);
    while (nxt != i) {
      vis[nxt] = true;
      ans1.push_back(nxt + 1);
      int pp = nxt;
      nxt = p ^ g[nxt][0] ^ g[nxt][1];
      p = pp;
    }
    ans.push_back(ans1);
  }
  cout << ans.size() << "\n";
  for (auto res : ans) {
    cout << res.size() << " ";
    for (__typeof(res.size()) i = (0) - ((0) > (res.size()));
         i != (res.size()) - ((0) > (res.size()));
         i += 1 - 2 * ((0) > (res.size())))
      cout << res[i] << " ";
    cout << "\n";
  }
}
