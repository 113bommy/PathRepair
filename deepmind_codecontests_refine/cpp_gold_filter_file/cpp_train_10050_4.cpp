#include <bits/stdc++.h>
using namespace std;
namespace zyt {
template <typename T>
inline bool read(T &x) {
  char c;
  bool f = false;
  x = 0;
  do c = getchar();
  while (c != EOF && c != '-' && !isdigit(c));
  if (c == EOF) return false;
  if (c == '-') f = true, c = getchar();
  do x = x * 10 + c - '0', c = getchar();
  while (isdigit(c));
  if (f) x = -x;
  return true;
}
template <typename T>
inline void write(T x) {
  static char buf[20];
  char *pos = buf;
  if (x < 0) putchar('-'), x = -x;
  do *pos++ = x % 10 + '0';
  while (x /= 10);
  while (pos > buf) putchar(*--pos);
}
const int N = 1e5 + 10;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
long long pre[N], suf[N], w[N], g[N];
;
int nxt[N], n, k, ans;
vector<int> s[N];
namespace Segment_Tree {
struct node {
  long long minp, maxs, ans, tag;
} tree[N << 2];
void add(const int rot, const long long x) {
  tree[rot].maxs += x;
  tree[rot].ans += x;
  tree[rot].tag += x;
}
void pushdown(const int rot) {
  if (tree[rot].tag) {
    add(rot << 1, tree[rot].tag);
    add(rot << 1 | 1, tree[rot].tag);
    tree[rot].tag = 0;
  }
}
long long dfs(const int rot, const int lt, const int rt, const long long mx) {
  if (lt == rt) return mx + tree[rot].minp;
  int mid = (lt + rt) >> 1;
  pushdown(rot);
  if (tree[rot << 1].maxs <= mx)
    return min(mx + tree[rot << 1].minp, dfs(rot << 1 | 1, mid + 1, rt, mx));
  else
    return min(tree[rot].ans, dfs(rot << 1, lt, mid, mx));
}
void update(const int rot, const int lt, const int rt) {
  tree[rot].minp = min(tree[rot << 1].minp, tree[rot << 1 | 1].minp);
  tree[rot].maxs = max(tree[rot << 1].maxs, tree[rot << 1 | 1].maxs);
  int mid = (lt + rt) >> 1;
  tree[rot].ans = dfs(rot << 1 | 1, mid + 1, rt, tree[rot << 1].maxs);
}
void build(const int rot, const int lt, const int rt) {
  if (lt == rt) {
    tree[rot].minp = -suf[lt];
    tree[rot].maxs = suf[lt];
    tree[rot].ans = 0;
    return;
  }
  int mid = (lt + rt) >> 1;
  build(rot << 1, lt, mid), build(rot << 1 | 1, mid + 1, rt);
  update(rot, lt, rt);
}
void add(const int rot, const int lt, const int rt, const int ls, const int rs,
         const long long x) {
  if (ls <= lt && rt <= rs) return void(add(rot, x));
  int mid = (lt + rt) >> 1;
  pushdown(rot);
  if (ls <= mid) add(rot << 1, lt, mid, ls, rs, x);
  if (rs > mid) add(rot << 1 | 1, mid + 1, rt, ls, rs, x);
  update(rot, lt, rt);
}
int find(const int rot, const int lt, const int rt, const long long mx) {
  if (lt == rt) return mx + tree[rot].minp <= k ? lt : 0;
  int mid = (lt + rt) >> 1;
  pushdown(rot);
  if (mx + tree[rot << 1 | 1].minp <= k)
    return find(rot << 1 | 1, mid + 1, rt, mx);
  else
    return find(rot << 1, lt, mid, mx);
}
int query(const int rot, const int lt, const int rt, const long long mx) {
  if (lt == rt) return mx + tree[rot].minp <= k ? lt : 0;
  int mid = (lt + rt) >> 1;
  pushdown(rot);
  if (tree[rot << 1].maxs <= mx) {
    int ans = 0;
    ans = max(ans, query(rot << 1 | 1, mid + 1, rt, mx));
    if (!ans && mx + tree[rot << 1].minp <= k)
      ans = max(ans, find(rot << 1, lt, mid, mx));
    return ans;
  } else {
    if (tree[rot].ans <= k)
      return query(rot << 1 | 1, mid + 1, rt, tree[rot << 1].maxs);
    else
      return query(rot << 1, lt, mid, mx);
  }
}
}  // namespace Segment_Tree
int sta[N], top;
int find(const int u) {
  int l = 0, r = top - 1, ans;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (pre[u - 1] - pre[sta[mid] - 1] <= k)
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  return sta[ans - 1] - 1;
}
void dfs(const int u) {
  using Segment_Tree::add;
  using Segment_Tree::query;
  sta[top++] = u;
  if (nxt[u] <= n) add(1, 1, n, nxt[u] - 1, n, pre[u - 1] - pre[nxt[u] - 1]);
  if (u <= n) {
    int lim = find(u);
    if (u > 1) add(1, 1, n, 1, u - 1, -LINF);
    if (lim < n) add(1, 1, n, lim, n, LINF);
    ans = max(ans, query(1, 1, n, -LINF) - u + 1);
    if (lim < n) add(1, 1, n, lim, n, -LINF);
    if (u > 1) add(1, 1, n, 1, u - 1, LINF);
  }
  for (auto v : s[u]) dfs(v);
  if (nxt[u] <= n) add(1, 1, n, nxt[u] - 1, n, pre[nxt[u] - 1] - pre[u - 1]);
  --top;
}
int work() {
  read(n), read(k);
  for (int i = 1; i < n; i++) read(w[i]);
  w[n] = LINF;
  for (int i = 1; i <= n; i++) read(g[i]);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + g[i] - w[i];
    suf[i] = suf[i - 1] + g[i] - w[i - 1];
    while (top && pre[sta[top - 1] - 1] > pre[i - 1]) nxt[sta[--top]] = i;
    sta[top++] = i;
  }
  while (top) nxt[sta[--top]] = n + 1;
  nxt[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) s[nxt[i]].push_back(i);
  Segment_Tree::build(1, 1, n);
  dfs(n + 1);
  write(ans);
  return 0;
}
}  // namespace zyt
int main() { return zyt::work(); }
