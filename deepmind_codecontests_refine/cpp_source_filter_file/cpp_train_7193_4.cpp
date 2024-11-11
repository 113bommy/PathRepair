#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
struct TNode {
  int ch[2], f, sz;
  bool r;
};
TNode t[N];
inline bool isroot(int pos) {
  return t[t[pos].f].ch[0] != pos && t[t[pos].f].ch[1] != pos;
}
inline void pushup(int pos) {
  t[pos].sz = t[t[pos].ch[0]].sz + 1 + t[t[pos].ch[1]].sz;
}
inline void pushdown(int pos) {
  if (t[pos].r) {
    t[pos].r = 0;
    t[t[pos].ch[0]].r ^= 1;
    t[t[pos].ch[1]].r ^= 1;
    swap(t[pos].ch[0], t[pos].ch[1]);
  }
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
  int ptr = 0, tmp = pos;
  static int stk[N];
  stk[ptr++] = tmp;
  while (!isroot(tmp)) stk[ptr++] = tmp = t[tmp].f;
  while (ptr--) pushdown(stk[ptr]);
  while (!isroot(pos)) {
    int y = t[pos].f, z = t[y].f;
    if (!isroot(y)) rotate((t[y].ch[0] == pos) ^ (t[z].ch[0] == y) ? pos : y);
    rotate(pos);
  }
}
void access(int pos) {
  for (int last = 0; pos; pos = t[last = pos].f)
    splay(pos), t[pos].ch[1] = last, pushup(pos);
}
int findroot(int pos) {
  access(pos);
  splay(pos);
  pushdown(pos);
  while (t[pos].ch[0]) pushdown(pos = t[pos].ch[0]);
  splay(pos);
  return pos;
}
inline void link(int x, int y) {
  access(x);
  t[x].f = y;
}
inline void cut(int x, int y) {
  access(y);
  splay(x);
  t[x].ch[1] = t[y].f = 0, pushup(x);
}
int lg[N], mn[N][20], mx[N][20], n, w, qq, a[N], ls[N], ans[N], nxt[N], vis[N];
vector<int> v[N];
inline int gmn(int l, int r) {
  int k = lg[r - l + 1];
  return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}
inline int gmx(int l, int r) {
  int k = lg[r - l + 1];
  return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
inline int calc(int l, int r) { return gmx(l, r) - gmn(l, r); }
struct Query {
  int v, id;
} q[N];
int gnxt(int x, int k) {
  int l = x, r = n + 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (calc(x, mid) > k)
      r = mid;
    else
      l = mid;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> w >> qq;
  int blk = sqrt(n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) mn[i][0] = mx[i][0] = a[i], t[i].sz = 1;
  lg[1] = 0;
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  mn[n + 1][0] = INT_MIN / 3;
  mx[n + 1][0] = INT_MAX / 3;
  for (int j = 1; j <= 17; j++)
    for (int i = 1; i <= n + 1; i++)
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]),
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
  for (int i = 1; i <= qq; i++) cin >> q[i].v, q[i].v = w - q[i].v, q[i].id = i;
  sort(q + 1, q + 1 + qq,
       [](const Query &a, const Query &b) { return a.v < b.v; });
  for (int i = 1; i <= qq; i++) ls[i] = q[i].v;
  for (int i = 1; i <= n; i++) nxt[i] = i, v[1].push_back(i);
  for (int i = 1; i <= qq; i++) {
    for (auto &pos : v[i]) {
      int j = nxt[pos] + 1;
      cut(pos, nxt[pos]);
      while (j <= n && j - pos <= blk && calc(pos, j) <= q[i].v) ++j;
      if (j - pos > blk)
        vis[pos] = 1;
      else {
        nxt[pos] = j;
        link(pos, nxt[pos]);
        int tt = lower_bound(ls + 1, ls + qq + 1, calc(pos, nxt[pos])) - ls;
        v[tt].push_back(pos);
      }
    }
    int gg = 0;
    for (int j = 1; j <= n; j = gnxt(j, q[i].v)) {
      if (!vis[j]) access(j), splay(j), gg += t[j].sz - 1, j = findroot(j);
      if (j > n)
        break;
      else
        ++gg;
    }
    ans[q[i].id] = gg - 1;
  }
  for (int i = 1; i <= qq; i++) cout << ans[i] << endl;
  return 0;
}
