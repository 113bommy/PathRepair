#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
using ll = long long;
struct TNode {
  int ch[2], f;
  ll v;
};
TNode t[N];
ll val[N], val2[N];
inline bool isroot(int pos) {
  return t[t[pos].f].ch[0] != pos && t[t[pos].f].ch[1] != pos;
}
inline void pushup(int pos) {
  t[pos].v = t[t[pos].ch[0]].v + val[pos] + t[t[pos].ch[1]].v + 1;
}
void rotate(int pos) {
  int y = t[pos].f, z = t[y].f, k = t[y].ch[1] == pos, w = t[pos].ch[k ^ 1];
  if (!isroot(y)) t[z].ch[t[z].ch[1] == y] = pos;
  t[pos].f = z;
  t[pos].ch[!k] = y;
  t[y].ch[k] = w;
  t[w].f = y;
  t[y].f = pos;
  pushup(y);
  pushup(pos);
}
void splay(int pos) {
  while (!isroot(pos)) {
    int y = t[pos].f, z = t[y].f;
    if (!isroot(y)) rotate((t[y].ch[0] == pos) ^ (t[z].ch[0] == y) ? pos : y);
    rotate(pos);
  }
}
void access(int pos) {
  for (int last = 0; pos; pos = t[last = pos].f) {
    splay(pos);
    val[pos] += t[t[pos].ch[1]].v;
    val2[pos] += t[t[pos].ch[1]].v * t[t[pos].ch[1]].v;
    t[pos].ch[1] = last;
    val[pos] -= t[t[pos].ch[1]].v;
    val2[pos] -= t[t[pos].ch[1]].v * t[t[pos].ch[1]].v;
    pushup(pos);
  }
}
inline void makeroot(int pos) {
  access(pos);
  splay(pos);
}
int findroot(int pos) {
  access(pos);
  splay(pos);
  while (t[pos].ch[0]) pos = t[pos].ch[0];
  splay(pos);
  return pos;
}
ll ans;
inline void add(int x, int v) {
  int rt;
  makeroot(rt = findroot(x));
  ans += v * val2[rt];
}
inline void link(int x, int y) {
  add(x, -1);
  add(y, -1);
  makeroot(x);
  makeroot(y);
  t[x].f = y;
  val[y] += t[x].v;
  val2[y] += t[x].v * t[x].v;
  add(y, 1);
}
inline void cut(int x, int y) {
  add(x, -1);
  makeroot(x);
  t[t[x].ch[0]].f = 0;
  t[x].ch[0] = 0;
  pushup(x);
  add(x, 1);
  add(y, 1);
}
int fa[N], n, m, a[N];
bool vis[N];
vector<int> v[N];
vector<pair<int, int>> vv[N];
void dfs(int pos) {
  for (auto &i : v[pos])
    if (i != fa[pos]) fa[i] = pos, dfs(i);
}
ll final_ans[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i], vv[a[i]].push_back({i, 0});
  int t1, t2;
  for (int i = 1; i < n; i++)
    cin >> t1 >> t2, v[t1].push_back(t2), v[t2].push_back(t1);
  dfs(1);
  fa[1] = n + 1;
  for (int i = 1; i <= m; i++)
    cin >> t1 >> t2, vv[a[t1]].push_back({t1, i}),
        vv[a[t1] = t2].push_back({t1, i});
  for (int i = 1; i <= n + 1; i++) t[i].v = 1;
  for (int i = 1; i <= n; i++) link(i, fa[i]);
  for (int i = 1; i <= n; i++) {
    int lst = 0;
    for (auto &j : vv[i]) {
      int x = j.first;
      if (vis[x])
        link(x, fa[x]);
      else
        cut(x, fa[x]);
      vis[x] ^= 1;
      final_ans[j.second] += 1ll * n * n - ans - lst;
      lst = 1ll * n * n - ans;
    }
    for (auto &j : vv[i])
      if (vis[j.first]) vis[j.first] = 0, link(j.first, fa[j.first]);
  }
  for (int i = 1; i <= m; i++) final_ans[i] += final_ans[i - 1];
  for (int i = 0; i <= m; i++) cout << final_ans[i] << endl;
  return 0;
}
