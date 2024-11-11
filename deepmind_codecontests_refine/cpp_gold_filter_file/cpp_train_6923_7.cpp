#include <bits/stdc++.h>
using namespace std;
long long fuck;
long long bigg = 1100000000000000000;
const int MAXN = 500010;
struct Edge {
  int to, next;
} edge[MAXN * 2];
int head[MAXN], tot;
int top[MAXN];
int fa[MAXN];
int deep[MAXN];
int num[MAXN];
int p[MAXN];
int fp[MAXN];
int son[MAXN];
int pos;
void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
  pos = 0;
  memset(son, -1, sizeof(son));
}
void addedge(int u, int v) {
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
void dfs1(int u, int pre, int d) {
  deep[u] = d;
  fa[u] = pre;
  num[u] = 1;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (v != pre) {
      dfs1(v, u, d + 1);
      num[u] += num[v];
      if (son[u] == -1 || num[v] > num[son[u]]) son[u] = v;
    }
  }
}
void getpos(int u, int sp) {
  top[u] = sp;
  if (son[u] != -1) {
    p[u] = pos++;
    fp[p[u]] = u;
    getpos(son[u], sp);
  } else {
    p[u] = pos++;
    fp[p[u]] = u;
    return;
  }
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (v != son[u] && v != fa[u]) getpos(v, v);
  }
}
struct Node {
  int l, r;
  long long Max;
} segTree[MAXN * 4];
void build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  segTree[i].Max = 1;
  if (l == r) return;
  int mid = (l + r) / 2;
  build(i << 1, l, mid);
  build((i << 1) | 1, mid + 1, r);
}
void push_up(int i) {
  if ((segTree[i << 1].Max < 0) || segTree[(i << 1) | 1].Max < 0 ||
      bigg / segTree[i << 1].Max < segTree[(i << 1) | 1].Max) {
    segTree[i].Max = -1;
  } else
    segTree[i].Max = segTree[i << 1].Max * segTree[(i << 1) | 1].Max;
}
void update(int i, int k, long long val) {
  if (segTree[i].l == k && segTree[i].r == k) {
    segTree[i].Max = val;
    return;
  }
  int mid = (segTree[i].l + segTree[i].r) / 2;
  if (k <= mid)
    update(i << 1, k, val);
  else
    update((i << 1) | 1, k, val);
  push_up(i);
}
long long query(int i, int l, int r) {
  long long holy, holy1, holy2;
  if (segTree[i].l == l && segTree[i].r == r) {
    return segTree[i].Max;
  }
  int mid = (segTree[i].l + segTree[i].r) / 2;
  if (r <= mid)
    return query(i << 1, l, r);
  else if (l > mid)
    return query((i << 1) | 1, l, r);
  else {
    holy1 = query(i << 1, l, mid);
    holy2 = query((i << 1) | 1, mid + 1, r);
    if (holy1 <= 0 || holy2 < 0 || bigg / holy1 < holy2)
      holy = -1;
    else
      holy = holy1 * holy2;
    if (holy == 0) printf("****\n");
    return holy;
  }
}
long long find(int u, int v) {
  long long holy;
  int f1 = top[u], f2 = top[v];
  long long tmp = 1;
  while (f1 != f2) {
    if (deep[f1] < deep[f2]) {
      swap(f1, f2);
      swap(u, v);
    }
    holy = query(1, p[f1], p[u]);
    if (holy < 0 || bigg / tmp < holy) {
      tmp = -1;
    } else
      tmp = tmp * holy;
    u = fa[f1];
    f1 = top[u];
  }
  if (u == v) return tmp;
  if (deep[u] > deep[v]) swap(u, v);
  holy = query(1, p[son[u]], p[v]);
  if (tmp == 0)
    printf(".....\n");
  else if (tmp < 0 || bigg / tmp < holy || holy < 0)
    return -1;
  return tmp * holy;
}
long long e[MAXN][3];
int main() {
  int wtff;
  int T;
  int opp;
  int n;
  long long cao;
  init();
  scanf("%d%d", &n, &wtff);
  for (int i = 0; i < n - 1; i++) {
    scanf("%I64d%I64d%I64d", &e[i][0], &e[i][1], &e[i][2]);
    addedge(e[i][0], e[i][1]);
    addedge(e[i][1], e[i][0]);
  }
  dfs1(1, 0, 0);
  getpos(1, 1);
  build(1, 0, pos - 1);
  for (int i = 0; i < n - 1; i++) {
    if (deep[e[i][0]] > deep[e[i][1]]) swap(e[i][0], e[i][1]);
    update(1, p[e[i][1]], e[i][2]);
  }
  char op[10];
  int u, v;
  while (wtff--) {
    scanf("%d", &opp);
    if (opp == 1) {
      scanf("%d%d%I64d", &u, &v, &fuck);
      if (u == v)
        printf("%I64d\n", fuck);
      else {
        cao = find(u, v);
        if (cao == 0)
          printf(".............");
        else if (cao < 0)
          printf("0\n");
        else
          printf("%I64d\n", fuck / cao);
      }
    } else {
      scanf("%d%I64d", &u, &fuck);
      update(1, p[e[u - 1][1]], fuck);
    }
  }
  return 0;
}
