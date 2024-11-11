#include <bits/stdc++.h>
const int MAXN = 5e5 + 10;
int n;
char s[MAXN];
namespace sam {
const int SIZE = MAXN << 1;
struct Node {
  int tranc[26];
  std::vector<int> son;
  int fa, dep;
} tree[SIZE];
int tail = 1, cnt = 1, root = 1;
int insert(int x) {
  int p = tail, np = ++cnt;
  tree[np].dep = tree[p].dep + 1;
  for (; p && !tree[p].tranc[x]; p = tree[p].fa) tree[p].tranc[x] = np;
  if (!p) {
    tree[np].fa = root;
  } else {
    int q = tree[p].tranc[x];
    if (tree[p].dep + 1 == tree[q].dep) {
      tree[np].fa = q;
    } else {
      int nq = ++cnt;
      tree[nq] = tree[q];
      tree[nq].dep = tree[p].dep + 1;
      tree[q].fa = tree[np].fa = nq;
      for (; p && tree[p].tranc[x] == q; p = tree[p].fa) tree[p].tranc[x] = nq;
    }
  }
  return tail = np;
}
int dfn[SIZE], en[SIZE], clk;
void dfs(int u) {
  dfn[u] = ++clk;
  for (int v : tree[u].son) {
    dfs(v);
  }
  en[u] = clk;
}
void init() {
  for (int i = 2; i <= cnt; i++) {
    tree[tree[i].fa].son.push_back(i);
  }
  dfs(1);
}
}  // namespace sam
namespace seg_tree {
using sam::dfn;
using sam::en;
const int SIZE = MAXN << 2;
struct Node {
  int ls, rs, max;
} tree[SIZE];
int root, cnt, n;
void build(int &node, int l, int r) {
  node = ++cnt;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(tree[node].ls, l, mid);
  build(tree[node].rs, mid + 1, r);
}
void init() {
  n = sam::cnt;
  build(root, 1, n);
}
int p, v;
void update(int node) {
  Node &u = tree[node];
  u.max = std::max(tree[u.ls].max, tree[u.rs].max);
}
void _modify(int node, int l, int r) {
  if (l == r) {
    tree[node].max = p;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    _modify(tree[node].ls, l, mid);
  else
    _modify(tree[node].rs, mid + 1, r);
  update(node);
}
void insert(int pos, int val) {
  p = dfn[pos], v = val;
  _modify(root, 1, n);
}
int ql, qr, ans;
void _query(int node, int l, int r) {
  if (ql <= l && r <= qr) {
    ans = std::max(ans, tree[node].max);
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) _query(tree[node].ls, l, mid);
  if (qr > mid) _query(tree[node].rs, mid + 1, r);
}
int query(int p) {
  ql = dfn[p], qr = en[p];
  ans = 0;
  _query(root, 1, n);
  return ans;
}
}  // namespace seg_tree
int main() {
  scanf("%d%s", &n, s + 1);
  static int endp[MAXN];
  for (int i = n; i >= 1; i--) {
    endp[i] = sam::insert(s[i] - 'a');
  }
  sam::init();
  seg_tree::init();
  static int f[MAXN];
  int dep = 0, cur = 1;
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    int &res = f[i];
    for (res = f[i + 1] + 1;; res--) {
      using namespace sam;
      if (seg_tree::query(cur) + 1 >= res) {
        dep++;
        cur = tree[cur].tranc[s[i] - 'a'];
        break;
      }
      int tdep = dep, tcur = cur;
      cur = tree[cur].tranc[s[i] - 'a'];
      if (tree[tree[cur].fa].dep == dep) cur = tree[cur].fa;
      if (seg_tree::query(cur) + 1 >= res) {
        cur = tcur;
        dep = tdep;
        dep++;
        cur = tree[cur].tranc[s[i] - 'a'];
        break;
      }
      cur = tcur;
      dep = tdep;
      dep--;
      if (tree[tree[cur].fa].dep == dep) cur = tree[cur].fa;
      seg_tree::insert(endp[i + res - 1], f[i + res - 1]);
    }
    ans = std::max(ans, res);
  }
  printf("%d\n", ans);
}
