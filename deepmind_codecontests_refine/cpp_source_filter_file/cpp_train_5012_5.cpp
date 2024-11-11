#include <bits/stdc++.h>
using namespace std;
int n;
struct Node {
  int fa, ch[2], sz, col, tag, rev;
} tree[322222];
int tr[644444], fir[622222];
vector<int> s[322222];
int isroot(int x) {
  if (tree[tree[x].fa].ch[0] == x || tree[tree[x].fa].ch[1] == x) return 0;
  return 1;
}
void pushup(int x) {
  tree[x].sz = tree[tree[x].ch[0]].sz + tree[tree[x].ch[1]].sz + 1;
}
void rotate(int x) {
  int w, fa, gr, rc;
  w = (tree[tree[x].fa].ch[1] == x);
  fa = tree[x].fa, gr = tree[fa].fa, rc = tree[x].ch[1 ^ w];
  if (!isroot(fa)) tree[gr].ch[tree[gr].ch[1] == fa] = x;
  tree[x].fa = gr;
  tree[fa].fa = x, tree[x].ch[1 ^ w] = fa;
  if (rc) tree[rc].fa = fa;
  tree[fa].ch[w] = rc;
  pushup(fa), pushup(x);
}
void pushdown(int x) {
  if (tree[x].rev) {
    if (tree[x].ch[0]) tree[tree[x].ch[0]].rev ^= 1;
    if (tree[x].ch[1]) tree[tree[x].ch[1]].rev ^= 1;
    tree[x].rev = 0;
    swap(tree[x].ch[0], tree[x].ch[1]);
  }
  if (tree[x].tag) {
    if (tree[x].ch[0])
      tree[tree[x].ch[0]].tag = tree[x].tag,
      tree[tree[x].ch[0]].col = tree[x].tag;
    if (tree[x].ch[1])
      tree[tree[x].ch[1]].tag = tree[x].tag,
      tree[tree[x].ch[1]].col = tree[x].tag;
    tree[x].tag = 0;
  }
}
void push(int x) {
  if (isroot(x)) {
    pushdown(x);
    return;
  }
  push(tree[x].fa);
  pushdown(x);
}
void splay(int x) {
  int fa, gr;
  push(x);
  while (!isroot(x)) {
    fa = tree[x].fa, gr = tree[fa].fa;
    if (isroot(fa)) rotate(x);
    if ((tree[gr].ch[1] == fa) == (tree[fa].ch[1] == x))
      rotate(fa), rotate(x);
    else
      rotate(x), rotate(x);
  }
}
int query(int x) {
  int i, ans = 0;
  for (i = x; i; i -= i & -i) ans += tr[i];
  return ans;
}
void modify(int x, int w) {
  int i;
  for (i = x; i <= n + n + n; i += i & -i) tr[i] += w;
}
void access2(int x, int col) {
  int y = 0;
  while (x) {
    splay(x);
    if (y) tree[y].fa = x;
    tree[x].ch[1] = 0;
    pushup(x);
    modify(tree[x].col, -tree[x].sz);
    tree[x].tag = col;
    tree[x].col = col;
    pushdown(x);
    modify(tree[x].col, tree[x].sz);
    tree[x].ch[1] = y;
    pushup(x);
    y = x;
    x = tree[x].fa;
  }
}
void dfs(int x) {
  modify(x, 1);
  tree[x].col = x;
  int c, i, y;
  c = s[x].size();
  for (i = 0; i < c; i++) {
    y = s[x][i];
    if (tree[x].fa == y) continue;
    tree[y].fa = x;
    dfs(y);
  }
}
void upd(int lst, int x, int col) {
  access2(x, col);
  splay(x);
  tree[x].rev ^= 1;
}
int qry(int x) {
  int ans = 0, col;
  splay(x);
  col = tree[x].col;
  ans += query(col - 1);
  ans += tree[tree[x].ch[1]].sz + 1;
  return ans;
}
char ca[10];
int main() {
  int q, x, y, i, lst, cnt, ans1, ans2, ans;
  scanf("%d%d", &n, &q);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    s[x].push_back(y);
    s[y].push_back(x);
    fir[i] = i;
  }
  dfs(1);
  lst = 1;
  cnt = n;
  for (i = 1; i <= n; i++) {
    cnt++;
    upd(lst, i, cnt);
    lst = i;
  }
  for (i = 1; i <= q; i++) {
    scanf("%s", ca + 1);
    if (ca[1] == 'u') {
      scanf("%d", &x);
      cnt++;
      upd(lst, x, cnt);
      lst = x;
    } else if (ca[1] == 'w') {
      scanf("%d", &x);
      ans = qry(x);
      printf("%d\n", ans);
    } else {
      scanf("%d%d", &x, &y);
      ans1 = qry(x), ans2 = qry(y);
      if (ans1 < ans2)
        printf("%d\n", x);
      else
        printf("%d\n", y);
    }
  }
  return 0;
}
