#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 99;
int n, m, ans, w[N];
pair<int, int> par[N];
pair<int, pair<int, int> > edge[N];
int Get_par(int u) {
  if (par[u].first < 0) return u;
  return (par[u].first = Get_par(par[u].first));
}
void dsu(int u, int v) {
  if (par[u].first > par[v].first) swap(u, v);
  par[u].first += par[v].first;
  par[u].second += par[v].second + 1;
  par[v].first = u;
}
int main() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++)
    cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
  sort(edge, edge + m);
  reverse(edge, edge + m);
  for (long long i = 0; i < n + 2; i++) par[i].first = par[i].second = -1;
  for (long long i = 0; i < m; i++) {
    int u = Get_par(edge[i].second.first), v = Get_par(edge[i].second.second);
    if (u != v)
      if (par[u].second < 0 || par[v].second < 0)
        dsu(u, v), ans += edge[i].first;
      else if (par[u].second == -1)
        ans += edge[i].first, par[u].second = 0;
  }
  cout << ans;
}
