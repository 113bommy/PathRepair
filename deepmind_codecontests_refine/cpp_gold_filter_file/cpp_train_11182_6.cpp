#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const int N = 1e5 + 100;
int Sz[N];
int Par[N];
long long Cost[N];
set<pair<long long, int>> Regions;
vector<int> Comp[N];
vector<pair<int, int>> Ans;
void Merge(int u, int v, int edge) {
  if (Sz[u] > Sz[v]) swap(u, v);
  Regions.erase({Cost[u], u});
  Regions.erase({Cost[v], v});
  for (auto x : Comp[u]) {
    Par[x] = v;
    Sz[v]++;
    Comp[v].push_back(x);
  }
  Comp[u].clear();
  Cost[v] += Cost[u] + edge;
  Regions.insert({Cost[v], v});
}
int main() {
  int n, m, p, q;
  scanf("%d%d%d%d", &n, &m, &p, &q);
  for (int i = 1; i <= n; i++) {
    Par[i] = i;
    Sz[i] = 1;
    Regions.insert({0, i});
    Comp[i].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int x, y, l;
    scanf("%d%d%d", &x, &y, &l);
    x = Par[x];
    y = Par[y];
    if (x == y) {
      Regions.erase({Cost[x], x});
      Cost[x] += l;
      Regions.insert({Cost[x], x});
    } else {
      Merge(x, y, l);
    }
  }
  while (Regions.size() > q) {
    auto it = Regions.begin();
    int x = it->second;
    it++;
    auto y = it->second;
    Ans.push_back({Comp[x][0], Comp[y][0]});
    Merge(x, y, min(INF, Cost[x] + Cost[y] + 1));
    p--;
  }
  for (int u = 1; u <= n; u++)
    if (Sz[u] > 1) {
      for (int i = 0; i < p; i++) Ans.push_back({Comp[u][0], Comp[u][1]});
      p = min(p, 0);
      break;
    }
  if (p != 0 || Regions.size() != q)
    puts("NO");
  else {
    puts("YES");
    for (auto e : Ans) printf("%d %d\n", e.first, e.second);
  }
  return 0;
}
