#include <bits/stdc++.h>
using namespace std;
const int iinf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int N = 20000;
int n, m, e2dfn[N], dfn2seg[N];
namespace Flows {
const int fN = N * 5 + 2;
int fn, s, t, e[fN];
vector<int> nex, to, fw;
void init() {
  for (int u(0); u < (fn); ++u) e[u] = -1;
}
void adde(int u, int v, int w) {
  nex.push_back(e[u]), to.push_back(v), fw.push_back(w),
      e[u] = int((to).size()) - 1;
  nex.push_back(e[v]), to.push_back(u), fw.push_back(0),
      e[v] = int((to).size()) - 1;
}
int dep[fN], cur[fN], q[fN], *ta, *he;
bool bfs() {
  for (int u(0); u < (fn); ++u) dep[u] = -1, cur[u] = e[u];
  ta = he = q - 1, dep[ *++ta = s] = 0;
  while (ta != he) {
    int u = *++he;
    for (int v = e[u]; ~v; v = nex[v])
      if (fw[v] && !~dep[to[v]]) dep[ *++ta = to[v]] = dep[u] + 1;
  }
  return ~dep[t];
}
int dfs(int u, int r) {
  if (u == t || !r) return r;
  int res = 0, f;
  for (int &v = cur[u]; ~v; v = nex[v])
    if (fw[v] && dep[to[v]] == dep[u] + 1 &&
        (f = dfs(to[v], min(r, fw[v]))) > 0) {
      fw[v] -= f, fw[v ^ 1] += f, r -= f, res += f;
      if (!r) break;
    }
  if (r) dep[u] = iinf;
  return res;
}
int flow() {
  int res = 0;
  while (bfs()) res += dfs(s, iinf);
  return res;
}
}  // namespace Flows
using Flows::fn;
using Flows::s;
using Flows::t;
namespace Tree {
vector<pair<int, int>> e[N];
void adde(int u, int v, int i) {
  e[u].push_back(make_pair(v, i)), e[v].push_back(make_pair(u, i));
}
int in, dfn[N], sz[N], dep[N], tp[N], son[N], fa[N];
void dfs0(int u) {
  sz[u] = 1;
  for (const pair<int, int> &v : e[u])
    if (v.first ^ fa[u]) {
      dep[v.first] = dep[fa[v.first] = u] + 1, dfs0(v.first),
      sz[u] += sz[v.first];
      if (!~son[u] || sz[v.first] > sz[son[u]]) son[u] = v.first;
    }
}
void dfs1(int u) {
  dfn[u] = in++;
  if (~son[u]) tp[son[u]] = tp[u], dfs1(son[u]);
  for (const pair<int, int> &v : e[u])
    if (v.first ^ son[u])
      if (v.first == fa[u])
        e2dfn[v.second] = dfn[u];
      else
        dfs1(tp[v.first] = v.first);
}
void init() {
  for (int u(0); u < (n); ++u) son[u] = fa[u] = -1;
  dfs0(0), dfs1(tp[0] = 0);
}
}  // namespace Tree
using Tree::dfn;
using Tree::fa;
using Tree::tp;
namespace SegmentTree {
void init(int u = 0, int l = 0, int r = n) {
  if (r - l == 1) return dfn2seg[l] = u, Flows::adde(u + m, t, 1);
  init(u * 2 + 1, l, ((l + r) >> 1)), init(u * 2 + 2, ((l + r) >> 1), r);
  Flows::adde(u + m, u * 2 + 1 + m, iinf),
      Flows::adde(u + m, u * 2 + 2 + m, iinf);
}
void adde(int first, int second, int i, int u = 0, int l = 0, int r = n) {
  if (r <= first || second <= l) return;
  if (first <= l && r <= second) return Flows::adde(i, u + m, iinf);
  adde(first, second, i, u * 2 + 1, l, ((l + r) >> 1)),
      adde(first, second, i, u * 2 + 2, ((l + r) >> 1), r);
}
}  // namespace SegmentTree
namespace Functions {
void adde(int u, int v, int i) {
  for (; ~u && ~v && tp[u] != tp[v];
       SegmentTree::adde(dfn[tp[u]], dfn[u] + 1, i), u = fa[tp[u]])
    if (Tree::dep[tp[u]] < Tree::dep[tp[v]]) swap(u, v);
  SegmentTree::adde(min(dfn[u], dfn[v]) + 1, max(dfn[u], dfn[v]) + 1, i);
}
}  // namespace Functions
int main() {
  cin >> n >> m, fn = (t = (s = n * 5) + 1) + 1;
  for (int i(0); i < (n - 1); ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    Tree::adde(u, v, i);
  }
  Flows::init(), Tree::init(), SegmentTree::init();
  for (int i(0); i < (m); ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    Functions::adde(u, v, i), Flows::adde(s, i, 1);
  }
  cout << Flows::flow() << '\n';
  vector<int> nsc, nsg;
  for (int i(0); i < (m); ++i)
    if (!~Flows::dep[i]) nsc.push_back(i);
  for (int i(0); i < (n - 1); ++i)
    if (~Flows::dep[dfn2seg[e2dfn[i]] + m]) nsg.push_back(i);
  cout << int((nsc).size()) << " ";
  for (int i : nsc) cout << i + 1 << " ";
  cout << '\n';
  cout << int((nsg).size()) << " ";
  for (int i : nsg) cout << i + 1 << " ";
  cout << '\n';
  return 0;
}
