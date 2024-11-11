#include <bits/stdc++.h>
using namespace std;
int n, q;
int A[200006];
bool as[200006];
map<pair<int, int>, int> ex;
vector<pair<int, int> > G[200006 << 2];
void pus(int rt, int l, int r, int L, int R, pair<int, int> e) {
  if (L <= l && R >= r) {
    G[rt].push_back(e);
    return;
  }
  int m = l + r >> 1;
  if (L <= m) pus(rt << 1, l, m, L, R, e);
  if (R > m) pus(rt << 1 | 1, m + 1, r, L, R, e);
}
int wf[200006], fa[200006], siz[200006];
int find(int x, int& w) {
  return x == fa[x] ? x : (w ^= wf[x], find(fa[x], w));
}
void solve(int rt, int l, int r) {
  int fk = 0;
  vector<pair<int, int> > chs;
  for (auto e : G[rt]) {
    int u = e.first, v = e.second, wu = 0, wv = 0;
    u = find(u, wu), v = find(v, wv);
    if (u == v) {
      if (wu == wv) {
        fk = 1;
        break;
      }
    } else {
      if (siz[u] > siz[v]) swap(u, v);
      siz[v] += siz[u], fa[u] = v, wf[v] = !(wv ^ wu);
      chs.emplace_back(make_pair(u, v));
    }
  }
  if (l == r && !fk) as[l] = 1;
  int m = l + r >> 1;
  if (l != r && !fk) solve(rt << 1, l, m), solve(rt << 1 | 1, m + 1, r);
  reverse((chs).begin(), (chs).end());
  for (auto t : chs) {
    int u = t.first, v = t.second;
    wf[u] = 0, fa[u] = u, siz[v] -= siz[u];
  }
}
void solve() {
  cin >> n >> q;
  for (int i = (1), iend = (q); i <= iend; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    pair<int, int> e = make_pair(u, v);
    if (ex.count(e))
      pus(1, 1, q, ex[e], i - 1, e), ex.erase(e);
    else
      ex[e] = i;
  }
  for (auto p : ex) pus(1, 1, q, p.second, q, p.first);
  for (int i = (1), iend = (n); i <= iend; ++i) fa[i] = i, siz[i] = 1;
  solve(1, 1, q);
  for (int i = (1), iend = (q); i <= iend; ++i) puts(as[i] ? "YES" : "NO");
}
signed main() { solve(); }
