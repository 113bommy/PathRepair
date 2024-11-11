#include <bits/stdc++.h>
using namespace std;
struct info {
  int u, v, w;
} edges[500005];
int par[500005];
int par1[500005];
vector<int> EW[500005];
vector<pair<int, int> > query[500005];
vector<pair<int, int> > v;
bool ans[500005];
bool cmp(pair<int, int> A, pair<int, int> B) { return A.first < B.first; }
int Find(int u) {
  if (par[u] == u) return u;
  par[u] = Find(par[u]);
  return par[u];
}
int Find1(int u) {
  if (par1[u] == u) return u;
  par1[u] = Find1(par1[u]);
  return par1[u];
}
void solve(int l, int r) {
  for (int i = l; i <= r; i++) {
    int id = v[i].second;
    int x = Find(edges[id].u);
    int y = Find(edges[id].v);
    if (x == y) {
      ans[v[i].first] = false;
      return;
    }
    par1[x] = x;
    par1[y] = y;
  }
  for (int i = l; i <= r; i++) {
    int id = v[i].second;
    int x = Find(edges[id].u);
    int y = Find(edges[id].v);
    x = Find1(x);
    y = Find1(y);
    if (x == y) {
      ans[v[i].first] = false;
      return;
    }
    par1[x] = y;
  }
}
int main() {
  memset(ans, false, sizeof(ans));
  int n, m, x, y, q;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    EW[edges[i].w].push_back(i);
  }
  for (int i = 1; i <= n; i++) par[i] = i;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int k;
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &x);
      query[edges[x].w].push_back(make_pair(i, x));
    }
  }
  memset(ans, true, sizeof(ans));
  for (int i = 1; i < 500005; i++) {
    v.clear();
    v = query[i];
    sort(v.begin(), v.end(), cmp);
    int len = v.size();
    for (int k = 0; k < len; k++) {
      int j = k;
      while (j + 1 < len && v[k].first == v[j + 1].first) j++;
      solve(k, j);
      i = j;
    }
    len = EW[i].size();
    for (int j = 0; j < len; j++) {
      int id = EW[i][j];
      par[Find(edges[id].u)] = Find(edges[id].v);
    }
  }
  for (int i = 1; i <= q; i++) {
    if (ans[i])
      printf("YES\n");
    else
      printf("NO\n");
  }
}
