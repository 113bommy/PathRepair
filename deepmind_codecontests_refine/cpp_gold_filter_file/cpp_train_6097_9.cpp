#include <bits/stdc++.h>
using namespace std;
struct edge {
  int a, b, w, i;
  edge(int a, int b, int w, int i) : a(a), b(b), w(w), i(i) {}
};
bool cmp(edge A, edge B) { return A.w < B.w; }
const int N = 2e5 + 5;
vector<pair<long long, int> > G[N];
int n, m, a[N], b[N], par[N], cnt;
long long w[N], c[N], total, S, ans, MinC = 1e9 + 1;
int L[N], P[19][N], pMinC;
pair<long long, int> MX[19][N];
int Find(int u) {
  if (u == par[u]) return u;
  return par[u] = Find(par[u]);
}
void Join(int u, int v) { par[Find(u)] = Find(v); }
vector<edge> ve;
vector<int> mst;
bool msted[N];
void dfs(int u) {
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i].second, I = G[u][i].first;
    if (L[v] != 0) continue;
    L[v] = L[u] + 1;
    P[0][v] = u;
    MX[0][v] = pair<long long, int>(w[I], I);
    dfs(v);
  }
}
void build() {
  for (int I = 1; I < 19; ++I)
    for (int i = 1; i <= n; ++i) {
      int p = P[I - 1][i];
      P[I][i] = P[I - 1][p];
      MX[I][i] = max(MX[I - 1][p], MX[I - 1][i]);
    }
}
pair<long long, int> lca(int A, int B) {
  pair<long long, int> res = pair<long long, int>(0, 0);
  for (int i = 18; i >= 0; --i) {
    if (L[P[i][A]] >= L[B]) {
      res = max(res, MX[i][A]);
      A = P[i][A];
    }
  }
  for (int i = 18; i >= 0; --i) {
    if (L[P[i][B]] >= L[A]) {
      res = max(res, MX[i][B]);
      B = P[i][B];
    }
  }
  for (int i = 18; i >= 0; --i) {
    if (P[i][A] != P[i][B]) {
      res = max(res, MX[i][B]);
      res = max(res, MX[i][A]);
      B = P[i][B], A = P[i][A];
    }
  }
  while (A != B) {
    res = max(res, MX[0][B]);
    res = max(res, MX[0][A]);
    B = P[0][B], A = P[0][A];
  }
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) par[i] = i;
  for (int i = 1; i <= m; ++i) cin >> w[i];
  for (int i = 1; i <= m; ++i) cin >> c[i];
  for (int i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i];
    ve.push_back(edge(a[i], b[i], w[i], i));
  }
  cin >> S;
  sort(ve.begin(), ve.end(), cmp);
  for (int i = 0; i < ve.size(); ++i) {
    edge e = ve[i];
    if (Find(e.a) != Find(e.b)) {
      ++cnt;
      total += e.w;
      if (MinC > c[e.i]) {
        pMinC = e.i;
        MinC = c[e.i];
      }
      msted[e.i] = 1;
      Join(e.a, e.b);
      G[e.a].push_back({e.i, e.b});
      G[e.b].push_back({e.i, e.a});
      mst.push_back(e.a);
      mst.push_back(e.b);
    }
    if (cnt == n - 1) break;
  }
  sort(mst.begin(), mst.end());
  mst.resize(unique(mst.begin(), mst.end()) - mst.begin());
  L[1] = 1;
  dfs(1);
  build();
  ans = total - (S / MinC);
  int found = 0, Rm, Add;
  for (int i = 1; i <= m; ++i) {
    if (msted[i]) continue;
    pair<long long, int> tmp = lca(a[i], b[i]);
    long long res = (total - tmp.first + w[i]) - (S / c[i]);
    if (res < ans) {
      found = 1;
      Rm = tmp.second;
      Add = i;
      ans = res;
    }
  }
  cout << ans << '\n';
  if (!found)
    for (int i = 1; i <= m; ++i) {
      if (msted[i]) {
        cout << i << ' ';
        if (i == pMinC)
          cout << w[i] - (S / c[i]) << '\n';
        else
          cout << w[i] << '\n';
      }
    }
  else {
    for (int i = 1; i <= m; ++i) {
      if (msted[i] && i != Rm)
        cout << i << ' ' << w[i] << '\n';
      else if (i == Add) {
        cout << i << ' ' << w[i] - (S / c[i]) << '\n';
      }
    }
  }
}
