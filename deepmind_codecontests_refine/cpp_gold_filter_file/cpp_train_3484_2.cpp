#include <bits/stdc++.h>
using namespace std;
int a[105];
vector<pair<int, int> > v[105];
int p[3005];
bool vis[3005];
vector<int> g[3005];
bool solve(int i) {
  for (auto x : g[i]) {
    if (!vis[x]) {
      vis[x] = 1;
      if (p[x] == -1) {
        p[x] = i;
        return true;
      } else {
        if (solve(p[x])) {
          p[x] = i;
          return true;
        }
      }
    }
  }
  return false;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int k = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int x = a[i];
    for (int j = 2; j * j <= x; j++) {
      while (a[i] % j == 0) {
        v[i].emplace_back(pair<int, int>(j, k++));
        a[i] /= j;
      }
    }
    if (a[i] > 1) v[i].emplace_back(pair<int, int>(a[i], k++));
  }
  memset(p, -1, sizeof(p));
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a % 2 == 0) swap(a, b);
    for (int j = 0; j < v[a].size(); j++) {
      for (int k = 0; k < v[b].size(); k++) {
        if (v[a][j].first == v[b][k].first) {
          g[v[a][j].second].emplace_back(v[b][k].second);
        }
      }
    }
  }
  memset(p, -1, sizeof(p));
  int ans = 0;
  for (int i = 1; i <= k - 1; i++) {
    memset(vis, 0, sizeof(vis));
    if (solve(i)) ans++;
  }
  printf("%d\n", ans);
}
