#include <bits/stdc++.h>
using namespace std;
const int _ = 1e2;
const int maxn = 1e5 + _;
const int maxm = 6e6 + _;
const int fbin = (1 << 17) + _;
inline int p1(int x) { return x << 1; }
inline int p2(int x) { return x << 1 | 1; }
namespace S {
struct node {
  int y, next;
} a[maxm];
int len, last[maxm];
void ins(int x, int y) {
  a[++len].y = y;
  a[len].next = last[x];
  last[x] = len;
  a[++len].y = x ^ 1;
  a[len].next = last[y ^ 1];
  last[y ^ 1] = len;
}
int z, dfn[maxm], low[maxm];
int top, sta[maxm];
bool v[maxm];
int cnt, bel[maxm];
void dfs(int x) {
  dfn[x] = low[x] = ++z;
  sta[++top] = x;
  v[x] = true;
  for (int k = last[x]; k; k = a[k].next) {
    int y = a[k].y;
    if (!dfn[y]) {
      dfs(y);
      low[x] = min(low[x], low[y]);
    } else if (v[y] == true)
      low[x] = min(low[x], dfn[y]);
  }
  if (low[x] == dfn[x]) {
    int i;
    cnt++;
    do {
      i = sta[top--];
      v[i] = false;
      bel[i] = cnt;
    } while (i != x);
  }
}
int n, u;
void main() {
  for (int i = 1; i <= n + n; i++)
    if (!dfn[i]) dfs(i);
  for (int i = 1; i <= n; i++)
    if (bel[p1(i)] == bel[p2(i)]) {
      puts("NO");
      return;
    }
  puts("YES");
  for (int i = 1; i <= u; i++) printf("%d\n", bel[p1(i)] < bel[p2(i)] ? 1 : 2);
}
}  // namespace S
namespace T {
vector<int> vec[fbin << 1];
void insert(int now, int ql, int qr, int l, int r, int id) {
  if (ql == l && qr == r) {
    vec[now].push_back(id);
    return;
  }
  if (r <= (ql + qr) / 2)
    insert((now << 1), ql, (ql + qr) / 2, l, r, id);
  else if ((ql + qr) / 2 + 1 <= l)
    insert((now << 1) | 1, (ql + qr) / 2 + 1, qr, l, r, id);
  else
    insert((now << 1), ql, (ql + qr) / 2, l, (ql + qr) / 2, id),
        insert((now << 1) | 1, (ql + qr) / 2 + 1, qr, (ql + qr) / 2 + 1, r, id);
}
int id;
void cop(int now, int ql, int qr, int p) {
  int tt = id + 1;
  for (int i = 0; i < vec[now].size(); i++) {
    id++;
    S::ins(vec[now][i], p1(id));
    if (i)
      S::ins(p1(id - 1), p1(id)), S::ins(p1(id - 1), vec[now][i] ^ 1);
    else if (p)
      S::ins(p1(p), p1(tt)), S::ins(p1(p), vec[now][i] ^ 1);
  }
  id++;
  if (vec[now].size())
    S::ins(p1(id - 1), p1(id));
  else if (p)
    S::ins(p1(p), p1(id));
  if (ql == qr) return;
  int nowid = id;
  cop((now << 1), ql, (ql + qr) / 2, nowid);
  cop((now << 1) | 1, (ql + qr) / 2 + 1, qr, nowid);
}
struct node {
  int y, next;
} a[2 * maxn];
int len, last[maxn];
void ins(int x, int y) {
  a[++len].y = y;
  a[len].next = last[x];
  last[x] = len;
}
int fa[maxn], son[maxn], dep[maxn], tot[maxn];
void pre_tree_node(int x) {
  tot[x] = 1;
  for (int k = last[x]; k; k = a[k].next) {
    int y = a[k].y;
    if (fa[x] != y) {
      fa[y] = x;
      dep[y] = dep[x] + 1;
      pre_tree_node(y);
      if (tot[y] > tot[son[x]]) son[x] = y;
      tot[x] += tot[y];
    }
  }
}
int z, ys[maxn], tp[maxn];
void pre_tree_edge(int x, int tt) {
  ys[x] = ++z;
  tp[x] = tt;
  if (son[x]) pre_tree_edge(son[x], tt);
  for (int k = last[x]; k; k = a[k].next)
    if (fa[x] != a[k].y && son[x] != a[k].y) pre_tree_edge(a[k].y, a[k].y);
}
int n, m;
void Insert(int x, int y, int p) {
  int tx = tp[x], ty = tp[y];
  while (tx != ty) {
    if (dep[tx] > dep[ty]) swap(x, y), swap(tx, ty);
    insert(1, 2, n, ys[ty], ys[y], p);
    y = fa[ty], ty = tp[y];
  }
  if (x != y) {
    if (dep[x] > dep[y]) swap(x, y);
    insert(1, 2, n, ys[son[x]], ys[y], p);
  }
}
void main() {
  int x, y;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    ins(x, y), ins(y, x);
  }
  pre_tree_node(1);
  pre_tree_edge(1, 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y), Insert(x, y, p1(i));
    scanf("%d%d", &x, &y), Insert(x, y, p2(i));
  }
  id = m;
  cop(1, 2, n, 0);
}
}  // namespace T
int main() {
  T::main();
  S::n = T::id;
  S::u = T::m;
  S::main();
  return 0;
}
