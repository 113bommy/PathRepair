#include <bits/stdc++.h>
using namespace std;
std::vector<int> g[100005];
int subt[100005];
bool vis[100005];
int n, cnt;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
void dfs(int u, int p) {
  subt[u] = 1;
  vis[u] = 1;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v, u);
      if (subt[v] % 2 == 0 && (n - subt[v]) % 2 == 0)
        cnt++, n - subt[v];
      else
        subt[u] += subt[v];
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  if (n % 2 == 0 && cnt == 0) {
    cout << -1;
    return 0;
  } else
    cout << cnt;
  return 0;
}
