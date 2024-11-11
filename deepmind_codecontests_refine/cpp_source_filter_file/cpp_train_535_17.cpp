#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 * 50 * 50 + 100, inf = 1e9;
struct Flow {
  vector<pair<int, pair<int, int> > > v[maxn];
  vector<int> rv[maxn];
  int arr[maxn], ds[maxn], pt[maxn];
  bool inq[maxn];
  void add(int a, int b, int c, int d) {
    rv[a].push_back(int((v[b]).size()));
    rv[b].push_back(int((v[a]).size()));
    v[a].push_back({b, {c, d}});
    v[b].push_back({a, {0, -d}});
  }
  bool spfa(int src, int snk) {
    fill(ds, ds + maxn, inf);
    memset(inq, 0, sizeof inq);
    int L = 0, R = 0;
    arr[R++] = src;
    ds[src] = 0;
    inq[src] = 1;
    while (L != R) {
      int u = arr[L++];
      if (L == maxn) L = 0;
      inq[u] = 0;
      for (auto x : v[u]) {
        if (x.second.first == 0) continue;
        if (ds[x.first] <= ds[u] + x.second.second) continue;
        ds[x.first] = ds[u] + x.second.second;
        if (inq[x.first] == 0)
          inq[x.first] = 1, arr[R++] = x.first, R = (R == maxn ? 0 : R);
      }
    }
    return ds[snk] != inf;
  }
  pair<int, int> dfs(int u, int snk, int f) {
    if (u == snk) return {f, 0};
    inq[u] = 1;
    int &i = pt[u];
    int ff = 0, cc = 0;
    while (i < int((v[u]).size())) {
      int y = v[u][i].first, &w = v[u][i].second.first,
          &w2 = v[y][rv[u][i]].second.first, c = v[u][i].second.second;
      if (w > 0 && ds[u] + c == ds[y] && !inq[y]) {
        pair<int, int> p = dfs(y, snk, min(w, f - ff));
        cc += p.second + p.first * c;
        ff += p.first;
        w -= p.first, w2 += p.first;
        if (f == ff) break;
      }
      i++;
    }
    inq[u] = 0;
    return {ff, cc};
  }
  int flow(int src, int snk) {
    int cst = 0;
    while (spfa(src, snk)) {
      memset(pt, 0, sizeof pt);
      cst += dfs(src, snk, 100).second;
    }
    return cst;
  }
};
Flow flw;
vector<int> v[55];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k, c, d;
  cin >> n >> m >> k >> c >> d;
  int SALAM = 70;
  int src = SALAM * n + 3, snk = src + 1;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    flw.add(src, --x, 1, 0);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[--a].push_back(--b);
    v[b].push_back(a);
  }
  for (int i = 0; i < SALAM; i++) {
    flw.add(i * n, snk, k, 0);
  }
  for (int i = 0; i < SALAM - 1; i++) {
    for (int j = 0; j < n; j++) {
      flw.add(i * n + j, (i + 1) * n + j, k, c);
      for (int y : v[j]) {
        for (int w = 0; w < k; w++) {
          flw.add(i * n + j, (i + 1) * n + y, 1, c + (2 * w + 1) * d);
        }
      }
    }
  }
  return cout << flw.flow(src, snk) << endl, 0;
}
