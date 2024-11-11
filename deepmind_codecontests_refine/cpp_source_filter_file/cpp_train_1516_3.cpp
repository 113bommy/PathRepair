#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, rt, ans[N];
struct node {
  int c, q;
} a[N];
bool cmp(node x, node y) { return (x.q == y.q) ? (x.c < y.c) : (x.q > y.q); }
struct FHQTreap {
  int val[N], cnt[N], lazy[N][2], dat[N], ch[N][2];
  void pushdown(int x) {
    int lc = ch[x][0], rc = ch[x][1];
    if (lazy[x][0]) {
      cnt[lc] += lazy[x][0];
      lazy[lc][0] += lazy[x][0];
      cnt[rc] += lazy[x][0];
      lazy[rc][0] += lazy[x][0];
      lazy[x][0] = 0;
    }
    if (lazy[x][1]) {
      val[lc] -= lazy[x][1];
      lazy[lc][1] += lazy[x][1];
      val[rc] -= lazy[x][1];
      lazy[rc][1] += lazy[x][1];
      lazy[x][1] = 0;
    }
  }
  void split(int x, int k, int &lc, int &rc) {
    if (!x) return (void)(lc = rc = 0);
    pushdown(x);
    if (val[x] <= k)
      lc = x, split(ch[x][1], k, ch[x][1], rc);
    else
      rc = x, split(ch[x][0], k, lc, ch[x][0]);
  }
  int merge(int x, int y) {
    if (!x || !y) return x + y;
    pushdown(x);
    pushdown(y);
    if (dat[x] < dat[y])
      return ch[x][1] = merge(ch[x][1], y), x;
    else
      return ch[y][0] = merge(x, ch[y][0]), y;
  }
  void ins(int x, int v) {
    int y, z;
    val[x] = v;
    dat[x] = (rand() * 32768 + rand());
    split(rt, v, y, z);
    rt = merge(merge(y, x), z);
  }
  void dfs(int x, int &y, int c, bool flag) {
    pushdown(x);
    if (ch[x][0]) dfs(ch[x][0], y, c, flag);
    if (ch[x][1]) dfs(ch[x][1], y, c, flag);
    if (flag) {
      int z;
      val[x] -= c;
      cnt[x]++;
      ch[x][0] = ch[x][1] = 0;
      split(y, val[x], y, z);
      y = merge(merge(y, x), z);
    }
  }
} fhq;
int main() {
  srand(569034);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].c, &a[i].q);
  scanf("%d", &m);
  for (int i = 1, x; i <= m; i++) {
    scanf("%d", &x);
    fhq.ins(i, x);
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    int x, y, z, c = a[i].c;
    fhq.split(rt, c - 1, x, y);
    fhq.split(y, c * 2, y, z);
    fhq.cnt[z]++;
    fhq.lazy[x][0]++;
    fhq.val[z] -= c;
    fhq.lazy[x][1] += c;
    rt = fhq.merge(x, z);
    fhq.dfs(y, rt, c, 1);
  }
  fhq.dfs(rt, n, 0, 0);
  for (int i = 1; i <= m; i++) printf("%d ", fhq.cnt[i]);
  return 0;
}
