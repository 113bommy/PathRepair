#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e5 + 6;
const double eps = 1e-9;
struct node {
  int len, h, l, r, f;
  node() {}
  node(int len, int h, int l, int r, int f)
      : len(len), h(h), l(l), r(r), f(f) {}
};
node IT[80 * maxn];
int nnode, n, m, s, t, d[maxn], pre[maxn], pw[maxn], minnode, maxnode;
vector<pair<int, int> > g[maxn];
void comb(node& x, int cl, int cr) {
  x.len = IT[cl].len + IT[cr].len;
  x.l = cl, x.r = cr;
  x.h = (1LL * IT[cl].h + 1LL * IT[cr].h * pw[IT[cl].len]) % mod;
  x.f = (IT[cl].f == -1 ? IT[cr].f : IT[cl].f);
}
int build(int l, int r, int x) {
  int k = ++nnode;
  if (l == r) {
    IT[k] = node(1, x, 0, 0, (x ? -1 : l));
    return k;
  }
  int mid = (l + r) >> 1;
  comb(IT[k], build(l, mid, x), build(mid + 1, r, x));
  return k;
}
int modify(int l, int r, int x, int y, int o, int p) {
  if (x > y || l > y || r < x) return p;
  if (x <= l && r <= y) return o;
  int k = ++nnode;
  int mid = (l + r) >> 1, cl = 0, cr = 0;
  cl = modify(l, mid, x, y, IT[o].l, IT[p].l);
  cr = modify(mid + 1, r, x, y, IT[o].r, IT[p].r);
  comb(IT[k], cl, cr);
  return k;
}
int cmp(int x, int y, int l, int r) {
  if (x == y) return 0;
  if (l == r) return IT[x].h - IT[y].h;
  int mid = (l + r) >> 1;
  int res = cmp(IT[x].r, IT[y].r, mid + 1, r);
  if (res != 0) return res;
  return cmp(IT[x].l, IT[y].l, l, mid);
}
int first0(int l, int r, int x, int o) {
  if (r < x) return -1;
  if (l == r) return IT[o].f;
  int mid = (l + r) >> 1;
  int res = first0(l, mid, x, IT[o].l);
  if (res != -1) return res;
  return first0(mid + 1, r, x, IT[o].r);
}
struct data {
  int dist, id;
  data() {}
  data(int a, int b) : dist(a), id(b) {}
  bool operator<(const data& tmp) const {
    int x = cmp(dist, tmp.dist, 0, maxn - 1);
    if (x == 0) return id < tmp.id;
    return (x < 0);
  }
};
set<data> S;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < maxn; i++) pw[i] = 2LL * pw[i - 1] % mod;
  cin >> n >> m;
  while (m--) {
    int u, v, x;
    cin >> u >> v >> x;
    g[u].push_back(make_pair(v, x));
    g[v].push_back(make_pair(u, x));
  }
  cin >> s >> t;
  IT[0] = node(0, 0, 0, 0, -1);
  minnode = build(0, maxn - 1, 0);
  maxnode = build(0, maxn - 1, 1);
  for (int i = 1; i < n + 1; i++) d[i] = maxnode;
  d[s] = minnode;
  S.insert(data(d[s], s));
  while (!S.empty()) {
    data ft = *S.begin();
    S.erase(S.begin());
    int u = ft.id, du = ft.dist;
    if (du != d[u]) continue;
    for (auto i : g[u]) {
      int v = i.first, w = i.second;
      int x = first0(0, maxn - 1, w, du);
      int nxt = modify(0, maxn - 1, w, x - 1, minnode, du);
      nxt = modify(0, maxn - 1, x, x, maxnode, nxt);
      if (cmp(nxt, d[v], 0, maxn - 1) < 0) {
        d[v] = nxt;
        S.insert(data(d[v], v));
        pre[v] = u;
      }
    }
  }
  if (d[t] == maxnode) return cout << "-1\n", 0;
  cout << IT[d[t]].h << endl;
  vector<int> ans;
  ans.push_back(t);
  while (t != s) {
    t = pre[t];
    ans.push_back(t);
  }
  cout << ((int)(ans).size()) << endl;
  for (int i = ((int)(ans).size()) - 1; i >= 0; i--) cout << ans[i] << ' ';
  cout << endl;
}
