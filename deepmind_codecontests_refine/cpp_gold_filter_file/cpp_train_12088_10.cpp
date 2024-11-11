#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, mod = 1e9 + 7;
const long long inf = 1e18;
vector<pair<long long, long long> > v[maxn];
int h[maxn];
int wh[maxn][21];
long long sp[maxn][21];
long long ds[50][maxn];
bool mark[maxn];
vector<long long> verts;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    pq;
void dfs(int u, int par = 0) {
  mark[u] = 1;
  for (pair<long long, long long> p : v[u]) {
    if (p.first == par) {
      wh[u][0] = p.first;
      sp[u][0] = p.second;
    } else if (mark[p.first] && h[p.first] < h[u]) {
      verts.push_back(p.first);
      verts.push_back(u);
    } else if (!mark[p.first]) {
      h[p.first] = h[u] + 1;
      dfs(p.first, u);
    }
  }
}
long long DIS(int a, int b) {
  if (h[a] < h[b]) swap(a, b);
  long long ans = 0;
  for (int i = 20; i >= 0; i--) {
    if (h[wh[a][i]] >= h[b]) {
      ans += sp[a][i];
      a = wh[a][i];
    }
  }
  for (int i = 20; i >= 0; i--) {
    if (wh[a][i] != wh[b][i]) {
      ans += sp[a][i] + sp[b][i];
      a = wh[a][i];
      b = wh[b][i];
    }
  }
  if (a != b) ans += sp[a][0] + sp[b][0];
  return ans;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = int(1); i <= int(m); i++) {
    int a, b;
    long long c;
    scanf("%d%d%lld", &a, &b, &c);
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  h[1] = 1;
  dfs(1);
  for (int j = int(1); j <= int(20); j++) {
    for (int i = int(1); i <= int(n); i++) {
      wh[i][j] = wh[wh[i][j - 1]][j - 1];
      sp[i][j] = sp[i][j - 1] + sp[wh[i][j - 1]][j - 1];
    }
  }
  for (int i = int(0); i <= int(int((verts).size()) - 1); i++) {
    for (int j = int(1); j <= int(n); j++) {
      ds[i][j] = inf;
    }
    memset(mark, 0, sizeof mark);
    pq.push({0, verts[i]});
    ds[i][verts[i]] = 0;
    while (int((pq).size())) {
      int u = pq.top().second;
      pq.pop();
      if (mark[u]) continue;
      mark[u] = 1;
      for (pair<long long, long long> p : v[u]) {
        if ((ds[i][u] + p.second) < ds[i][p.first]) {
          ds[i][p.first] = ds[i][u] + p.second;
          pq.push({ds[i][p.first], p.first});
        }
      }
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    long long ans = DIS(a, b);
    for (int i = int(0); i <= int(int((verts).size()) - 1); i++) {
      ans = min(ans, DIS(a, verts[i]) + ds[i][b]);
    }
    cout << ans << endl;
  }
}
