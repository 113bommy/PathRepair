#include <bits/stdc++.h>
using namespace std;
int n, m, q;
vector<pair<int, int>> G[200006];
int a[31];
void ins(int x) {
  for (int i = 30; i >= 0; --i)
    if (x & (1 << i)) {
      if (!a[i]) {
        a[i] = x;
        return;
      }
      x ^= a[i];
    }
}
int chkmn(int* p, int x) {
  for (int i = 30; i >= 0; --i)
    if (x > (x ^ p[i])) x = (x ^ p[i]);
  return x;
}
vector<pair<pair<int, int>, int>> E[200006 << 2];
void inse(int rt, int l, int r, int L, int R, pair<pair<int, int>, int> e) {
  if (L <= l && R >= r) {
    E[rt].push_back(e);
    return;
  }
  int m = l + r >> 1;
  if (L <= m) inse(rt << 1, l, m, L, R, e);
  if (R > m) inse(rt << 1 | 1, m + 1, r, L, R, e);
}
pair<int, int> Q[200006];
int ans[200006];
int fa[200006], f[200006], dep[200006];
int getfa(int u) { return u == fa[u] ? u : getfa(fa[u]); }
int getdis(int u) { return u == fa[u] ? 0 : f[u] ^ getdis(fa[u]); }
void work(int rt, int l, int r) {
  int ta[31];
  memcpy(ta, a, sizeof a);
  vector<pair<pair<int, int>, int>> vec;
  for (auto& t : E[rt]) {
    int u = t.first.first, v = t.first.second, w = t.second;
    int fu = getfa(u), fv = getfa(v);
    w ^= getdis(u) ^ getdis(v);
    if (fu == fv)
      ins(w);
    else {
      if (dep[fu] > dep[fv]) swap(fu, fv), swap(u, v);
      vec.emplace_back(make_pair(make_pair(fu, fv), 0));
      fa[fu] = fv, f[fu] = w;
      if (dep[fu] == dep[fv]) ++dep[fv], vec.rbegin()->second = 1;
    }
  }
  int m = l + r >> 1;
  if (l == r)
    ans[l] = chkmn(a, getdis(Q[l].first) ^ getdis(Q[l].second));
  else
    work(rt << 1, l, m), work(rt << 1 | 1, m + 1, r);
  reverse((vec).begin(), (vec).end());
  for (auto& t : vec) {
    fa[t.first.first] = t.first.first;
    f[t.first.first] = 0;
    dep[t.first.second] -= t.second;
  }
  memcpy(a, ta, sizeof a);
}
pair<pair<int, int>, int> ed[200006];
set<pair<pair<int, int>, int>> cur;
map<pair<pair<int, int>, int>, int> tim;
void solve() {
  cin >> n >> m;
  for (int i = (1), iend = (n); i <= iend; ++i) fa[i] = i;
  for (int i = 1, u, v, x; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &x);
    G[u].emplace_back(make_pair(v, x)), G[v].emplace_back(make_pair(u, x));
    ed[i] = make_pair(make_pair(u, v), x);
  }
  for (int i = 1; i <= m; ++i) {
    int u = ed[i].first.first, v = ed[i].first.second;
    cur.insert(ed[i]), tim[ed[i]] = 0;
  }
  cin >> q;
  int opt, u, v, d;
  pair<pair<int, int>, int> qwq;
  vector<int> ques;
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d%d", &opt, &u, &v);
    if (opt == 1) {
      scanf("%d", &d);
      qwq = make_pair(make_pair(u, v), u);
      tim[qwq] = i;
      cur.insert(qwq);
    } else if (opt == 2) {
      qwq = make_pair(make_pair(u, v), 0);
      auto t = tim.lower_bound(qwq);
      cur.erase(qwq);
      inse(1, 0, q + 1, t->second, i, t->first);
      tim.erase(t);
    } else {
      Q[i] = make_pair(u, v);
      ques.push_back(i);
    }
  }
  for (auto& x : tim) inse(1, 0, q + 1, x.second, q + 1, x.first);
  work(1, 0, q + 1);
  for (int x : ques) printf("%d\n", ans[x]);
}
signed main() { solve(); }
