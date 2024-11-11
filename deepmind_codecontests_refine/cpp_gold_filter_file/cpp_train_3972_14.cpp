#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
const long long int base = 313;
const long long int inf = 1e8;
const long long int mod = 1e9 + 7;
const int lg = 20;
map<int, int> mp[N];
long long int res = 0, sz[2][2 * N], hres[4 * N];
int par[2 * N], n;
vector<int> hpar[4 * N];
vector<pair<int, pair<int, int>>> hsz[4 * N];
vector<pair<int, int>> ed[4 * N], t;
int find_par(int u) {
  if (par[u] == u) return u;
  return find_par(par[u]);
}
inline void merge(int x, int y, int id) {
  x = find_par(x);
  y = find_par(y);
  if (x == y) return;
  if (sz[0][x] + sz[1][x] < sz[0][y] + sz[1][y]) swap(x, y);
  hpar[id].push_back(y);
  hsz[id].push_back({x, {sz[0][x], sz[1][x]}});
  hres[id] += sz[0][x] * sz[1][y] + sz[0][y] * sz[1][x];
  res += sz[0][x] * sz[1][y] + sz[0][y] * sz[1][x];
  par[y] = x;
  sz[0][x] += sz[0][y];
  sz[1][x] += sz[1][y];
}
void solve(int b = 0, int e = n, int ind = 1) {
  for (auto it : ed[ind]) {
    merge(it.first, it.second, ind);
  }
  if (b + 1 != e) {
    int mid = (b + e) / 2;
    solve(b, mid, ind * 2);
    solve(mid, e, ind * 2 + 1);
  } else {
    cout << res << ' ';
  }
  reverse(hsz[ind].begin(), hsz[ind].end());
  res -= hres[ind];
  for (auto u : hpar[ind]) par[u] = u;
  for (auto it : hsz[ind]) {
    sz[0][it.first] = it.second.first;
    sz[1][it.first] = it.second.second;
  }
  hsz[ind].clear();
  hpar[ind].clear();
  ed[ind].clear();
}
void add(int l, int r, int x, int y, int b = 0, int e = n, int ind = 1) {
  if (r <= b || e <= l) return;
  if (l <= b && e <= r) {
    ed[ind].push_back({2 * x, 2 * y + 1});
    return;
  }
  int mid = (b + e) / 2;
  add(l, r, x, y, b, mid, ind * 2);
  add(l, r, x, y, mid, e, ind * 2 + 1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < 2 * N; i++) {
    par[i] = i;
    sz[i % 2][i] = 1;
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (mp[x][y] != 0) {
      add(mp[x][y] - 1, i, x, y);
      mp[x][y] = 0;
    } else {
      mp[x][y] = i + 1;
    }
    t.push_back({x, y});
  }
  for (auto it : t) {
    int x = it.first, y = it.second;
    if (mp[x][y] != 0) {
      add(mp[x][y] - 1, n, x, y);
      mp[x][y] = 0;
    }
  }
  solve();
  cout << endl;
  return 0;
}
