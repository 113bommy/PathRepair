#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5, INF = 1e9;
int n, m, k, mk[MAX];
vector<int> a;
vector<pair<int, int> > g[MAX];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    mk[x] = 1;
    a.push_back(x);
  }
  int sol = INF;
  for (int o : a) {
    for (auto p : g[o]) {
      int v = p.first;
      int w = p.second;
      if (!mk[v]) sol = min(sol, w);
    }
  }
  if (sol == INF) sol = -1;
  printf("%d\n", sol);
  return 0;
}
