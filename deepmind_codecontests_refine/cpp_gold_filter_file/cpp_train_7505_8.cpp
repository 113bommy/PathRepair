#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5, inf = 1e9 + 5, L = 24;
int n, q, stt[maxn], ftt[maxn], ti, par[maxn][L], h[maxn];
int lzy[maxn << 2], mx;
vector<int> adj[maxn];
set<pair<int, int> > st;
pair<int, int> seg[maxn << 2];
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return {a.first, a.second + b.second};
  if (a.first < b.first) return b;
  return a;
}
void build(int l = 0, int r = n, int id = 1) {
  seg[id] = {0, r - l};
  if (r - l == 1) {
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, id << 1);
  build(mid, r, id << 1 | 1);
}
void shift(int id) {
  lzy[id << 1] += lzy[id];
  lzy[id << 1 | 1] += lzy[id];
  seg[id << 1].first += lzy[id];
  seg[id << 1 | 1].first += lzy[id];
  lzy[id] = 0;
}
void add(int ql, int qr, int val, int l = 0, int r = n, int id = 1) {
  if (max(ql, l) >= min(qr, r)) return;
  if (ql <= l && qr >= r) {
    seg[id].first += val;
    lzy[id] += val;
    return;
  }
  shift(id);
  int mid = l + r >> 1;
  add(ql, qr, val, l, mid, id << 1);
  add(ql, qr, val, mid, r, id << 1 | 1);
  seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
void dfs(int v = 0, int p = -1) {
  par[v][0] = p;
  for (int i = 1; i < L; i++)
    par[v][i] = (par[v][i - 1] == -1 ? -1 : par[par[v][i - 1]][i - 1]);
  stt[v] = ti++;
  for (auto u : adj[v])
    if (u != p) h[u] = h[v] + 1, dfs(u, v);
  ftt[v] = ti;
}
int getpar(int v, int p) {
  for (int i = L - 1; i >= 0; i--) {
    if (p >= (1 << i)) {
      v = par[v][i];
      p -= (1 << i);
    }
    if (v == -1) break;
  }
  return v;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs();
  build();
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    bool b = 0;
    if (stt[x] < stt[y] && ftt[x] >= ftt[y]) {
      if (st.count({min(x, y), max(x, y)})) {
        mx--;
        add(stt[y], ftt[y], -1);
        add(0, n, -1);
        int d = h[y] - h[x];
        add(stt[getpar(y, d - 1)], ftt[getpar(y, d - 1)], 1);
        st.erase({min(x, y), max(x, y)});
      } else {
        mx++;
        add(stt[y], ftt[y], 1);
        add(0, n, 1);
        int d = h[y] - h[x];
        add(stt[getpar(y, d - 1)], ftt[getpar(y, d - 1)], -1);
        st.insert({min(x, y), max(x, y)});
      }
      b = 1;
    }
    swap(x, y);
    if (!b && stt[x] < stt[y] && ftt[x] >= ftt[y]) {
      if (st.count({min(x, y), max(x, y)})) {
        mx--;
        add(stt[y], ftt[y], -1);
        add(0, n, -1);
        int d = h[y] - h[x];
        add(stt[getpar(y, d - 1)], ftt[getpar(y, d - 1)], 1);
        st.erase({min(x, y), max(x, y)});
      } else {
        mx++;
        add(stt[y], ftt[y], 1);
        add(0, n, 1);
        int d = h[y] - h[x];
        add(stt[getpar(y, d - 1)], ftt[getpar(y, d - 1)], -1);
        st.insert({min(x, y), max(x, y)});
      }
      b = 1;
    }
    if (!b) {
      if (st.count({min(x, y), max(x, y)})) {
        mx--;
        add(stt[y], ftt[y], -1);
        add(stt[x], ftt[x], -1);
        st.erase({min(x, y), max(x, y)});
      } else {
        mx++;
        add(stt[y], ftt[y], 1);
        add(stt[x], ftt[x], 1);
        st.insert({min(x, y), max(x, y)});
      }
    }
    if (seg[1].first == mx)
      cout << seg[1].second << '\n';
    else
      cout << 0 << '\n';
  }
}
