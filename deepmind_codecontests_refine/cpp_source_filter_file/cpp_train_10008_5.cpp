#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
vector<int> p;
int dsu_get(int v) { return (v == p[v]) ? v : (p[v] = dsu_get(p[v])); }
void dsu_unite(int a, int b) {
  a = dsu_get(a);
  b = dsu_get(b);
  if (rand() & 1) swap(a, b);
  if (a != b) p[a] = b;
}
int main() {
  cin >> n >> m;
  p.resize(n);
  vector<pair<int, pair<int, int> > > g;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g.push_back(make_pair(w, make_pair(a - 1, b - 1)));
  }
  int cost = 0, ans = 0, fake = 0;
  vector<pair<int, int> > res;
  sort(g.begin(), g.end());
  p.resize(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int i = 0; i < m; ++i) {
    int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
    if (i != 0 && l != g[i - 1].first) {
      int kol = 1, j = i;
      while (j < n - 1 && l == g[i + 1].first) {
        kol++;
        j++;
      }
      for (j = i; j < i + kol; j++) {
        if (dsu_get(g[j].second.first) == dsu_get(g[j].second.second)) {
          fake++;
        }
      }
    }
    if (dsu_get(a) != dsu_get(b)) {
      cost += l;
      res.push_back(g[i].second);
      dsu_unite(a, b);
    } else
      ans++;
  }
  printf("%d", ans - fake);
  return 0;
}
