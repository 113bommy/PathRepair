#include <bits/stdc++.h>
using namespace std;
char _;
const int maxN = 200 * 1000 + 2;
const int maxM = 5000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
const int base = 701;
const int SQ = 500;
const int maxL = 17;
vector<int> v;
int mp(int t) { return lower_bound(v.begin(), v.end(), t) - v.begin(); }
int par[maxN], L[maxN], R[maxN];
int gg(int v) { return (par[v] == -1 ? v : par[v] = gg(par[v])); }
void merge(int v, int u) {
  v = gg(v);
  u = gg(u);
  if (v != u) {
    par[u] = v;
    L[v] = min(L[v], L[u]);
    R[v] = max(R[v], R[u]);
  }
}
vector<int> seg[4 * maxN];
void get(int p, int v, int s, int e, int id) {
  for (auto u : seg[id]) merge(v, u);
  seg[id].clear();
  if (e - s == 1) return;
  int mid = (s + e) >> 1;
  if (p < mid)
    get(p, v, s, mid, 2 * id);
  else
    get(p, v, mid, e, 2 * id + 1);
}
void add(int l, int r, int v, int s, int e, int id) {
  if (l >= e || r <= s) return;
  if (l <= s && e <= r) {
    seg[id].push_back(v);
    return;
  }
  int mid = (s + e) >> 1;
  add(l, r, v, s, mid, 2 * id + 0);
  add(l, r, v, mid, e, 2 * id + 1);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(par, -1, sizeof par);
  int n;
  cin >> n;
  vector<pair<int, pair<int, int> > > que;
  vector<pair<int, int> > inter;
  for (int i = 0; i < n; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    que.push_back({t, {x, y}});
    if (t == 1) {
      v.push_back(x);
      v.push_back(y);
    }
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (int i = 0; i < n; i++) {
    int t = que[i].first, x = que[i].second.first, y = que[i].second.second;
    if (t == 1) {
      x = mp(x);
      y = mp(y);
      int id = inter.size();
      L[id] = x;
      R[id] = y;
      inter.push_back({x, y});
      get(x, id, 0, v.size(), 1);
      get(y, id, 0, v.size(), 1);
      add(L[gg(id)] + 1, R[gg(id)], id, 0, v.size(), 1);
    } else {
      x--;
      y--;
      int px = gg(x), py = gg(y);
      if (px == py || (L[py] <= inter[x].first && inter[x].second <= R[py] &&
                       (L[py] != inter[x].first || R[py] != inter[x].second)))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
