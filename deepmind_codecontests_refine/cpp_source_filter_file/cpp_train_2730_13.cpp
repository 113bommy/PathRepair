#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int fl = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') fl = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  x *= fl;
}
template <typename T, typename... Args>
inline void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
const int N = 1000005;
int n, k, ans[N], a[N];
bool mark[N];
struct Node {
  char ch;
  int id;
  Node(char ch, int id) : ch(ch), id(id) {}
  bool operator<(const Node &A) const { return ch < A.ch; }
};
vector<Node> trie[N];
struct segTree {
  int l, r, mn, lazy;
} tr[N << 2];
inline void pushup(int id) {
  tr[id].mn = min(tr[id << 1].mn, tr[id << 1 | 1].mn);
}
inline void pushdown(int id) {
  if (tr[id].l == tr[id].r) return;
  if (tr[id].lazy) {
    tr[id << 1].lazy += tr[id].lazy;
    tr[id << 1].mn += tr[id].lazy;
    tr[id << 1 | 1].lazy += tr[id].lazy;
    tr[id << 1 | 1].mn += tr[id].lazy;
    tr[id].lazy = 0;
  }
}
void build(int id, int l, int r) {
  tr[id].l = l, tr[id].r = r;
  tr[id].mn = 1;
  if (tr[id].l == tr[id].r) return;
  build(id << 1, l, ((tr[id].l + tr[id].r) >> 1));
  build(id << 1 | 1, ((tr[id].l + tr[id].r) >> 1) + 1, r);
  pushup(id);
}
void add(int id, int l, int r, int val) {
  pushdown(id);
  if (tr[id].l == l && tr[id].r == r) {
    tr[id].lazy += val;
    tr[id].mn += val;
    return;
  }
  if (r <= ((tr[id].l + tr[id].r) >> 1))
    add(id << 1, l, r, val);
  else if (l > ((tr[id].l + tr[id].r) >> 1))
    add(id << 1 | 1, l, r, val);
  else
    add(id << 1, l, ((tr[id].l + tr[id].r) >> 1), val),
        add(id << 1 | 1, ((tr[id].l + tr[id].r) >> 1) + 1, r, val);
  pushup(id);
}
int query(int id, int l, int r) {
  pushdown(id);
  if (tr[id].l == l && tr[id].r == r) return tr[id].mn;
  if (r <= ((tr[id].l + tr[id].r) >> 1))
    return query(id << 1, l, r);
  else if (l > ((tr[id].l + tr[id].r) >> 1))
    return query(id << 1 | 1, l, r);
  else
    return min(query(id << 1, l, ((tr[id].l + tr[id].r) >> 1)),
               query(id << 1 | 1, ((tr[id].l + tr[id].r) >> 1) + 1, r));
}
void setVal(int id, int l, int r, int val) {
  pushdown(id);
  if (tr[id].l == l && tr[id].r == r) {
    tr[id].mn = val;
    tr[id].lazy = 0;
    return;
  }
  if (r <= ((tr[id].l + tr[id].r) >> 1))
    setVal(id << 1, l, r, val);
  else if (l > ((tr[id].l + tr[id].r) >> 1))
    setVal(id << 1 | 1, l, r, val);
  else
    setVal(id << 1, l, ((tr[id].l + tr[id].r) >> 1), val),
        setVal(id << 1 | 1, ((tr[id].l + tr[id].r) >> 1) + 1, r, val);
  pushup(id);
}
int st[N], ed[N], dfsClock;
void dfs(int x, int f) {
  st[x] = ++dfsClock;
  if (x) {
    ans[x] = ans[f] + 1;
    if (mark[x]) ans[x] = min(ans[x], query(1, 1, st[f]));
    add(1, st[x], st[x], ans[x]);
  }
  if (mark[x]) add(1, 1, st[x], 1);
  for (auto to : trie[x]) dfs(to.id, x);
  ed[x] = dfsClock;
  setVal(1, st[x], ed[x], 1e8);
}
int main() {
  read(n);
  build(1, 1, n + 1);
  for (int i = 1; i <= n; i++) {
    int p;
    char ch[2];
    read(p);
    scanf("%s", ch);
    trie[p].push_back(Node(ch[0], i));
  }
  for (int i = 1; i <= n; i++) sort(trie[i].begin(), trie[i].end());
  read(k);
  for (int i = 1; i <= k; i++) {
    read(a[i]);
    mark[a[i]] = true;
  }
  dfs(0, -1);
  for (int i = 1; i <= k; i++) printf("%d ", ans[a[i]]);
  return 0;
}
