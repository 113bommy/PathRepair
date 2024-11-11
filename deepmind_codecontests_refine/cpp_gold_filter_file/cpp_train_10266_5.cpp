#include <bits/stdc++.h>
using namespace std;
struct Node {
  int v, num, next;
} edge[200010];
int cnt, head[200010];
void add(int x, int y, int v) {
  edge[cnt].num = y;
  edge[cnt].next = head[x];
  edge[cnt].v = v;
  head[x] = cnt++;
}
struct Node1 {
  int x, y, v;
} a[400200];
int now;
int f[200100], st[200100], ed[200100];
long long v[200100];
long long t[200100 << 3], fl[200100 << 3];
void dfs(int x, long long d) {
  v[now] = d;
  st[x] = now;
  f[x] = now++;
  for (int i = head[x]; i != -1; i = edge[i].next) {
    int v = edge[i].num;
    dfs(v, d + edge[i].v);
  }
  ed[x] = now - 1;
}
void build(int rt, int l, int r) {
  if (l == r) {
    fl[rt] = 0;
    t[rt] = v[l];
    return;
  }
  int ls = rt << 1, rs = ls | 1, mid = l + r >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  t[rt] = min(t[ls], t[rs]);
  fl[rt] = 0;
}
void add(int L, int R, int rt, int l, int r, long long v) {
  if (l == L && r == R) {
    fl[rt] += v;
    t[rt] += v;
    return;
  }
  int ls = rt << 1, rs = ls | 1, mid = l + r >> 1;
  if (fl[rt]) {
    t[ls] += fl[rt];
    t[rs] += fl[rt];
    fl[ls] += fl[rt];
    fl[rs] += fl[rt];
    fl[rt] = 0;
  }
  if (R <= mid)
    add(L, R, ls, l, mid, v);
  else if (L > mid)
    add(L, R, rs, mid + 1, r, v);
  else
    add(L, mid, ls, l, mid, v), add(mid + 1, R, rs, mid + 1, r, v);
  t[rt] = min(t[ls], t[rs]);
}
long long query(int L, int R, int rt, int l, int r) {
  if (L == l && R == r) {
    return t[rt];
  }
  int ls = rt << 1, rs = ls | 1, mid = l + r >> 1;
  if (fl[rt]) {
    t[ls] += fl[rt];
    t[rs] += fl[rt];
    fl[ls] += fl[rt];
    fl[rs] += fl[rt];
    fl[rt] = 0;
  }
  if (R <= mid)
    return query(L, R, ls, l, mid);
  else if (L > mid)
    return query(L, R, rs, mid + 1, r);
  else
    return min(query(L, mid, ls, l, mid), query(mid + 1, R, rs, mid + 1, r));
}
int sav[200100];
int main() {
  int n, q;
  int op, x, y;
  while (~scanf("%d%d", &n, &q)) {
    cnt = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++) {
      scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
      add(a[i].x, a[i].y, a[i].v);
    }
    for (int i = n; i < n + n - 1; i++) {
      scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
      sav[a[i].x] = a[i].v;
    }
    now = 1;
    dfs(1, 0);
    for (int i = n; i < n + n - 1; i++) {
      v[f[a[i].x]] += a[i].v;
    }
    build(1, 1, n);
    sav[0] = 0;
    for (int i = 0; i < q; i++) {
      scanf("%d%d%d", &op, &x, &y);
      if (op == 1) {
        if (x < n) {
          add(st[a[x].y], ed[a[x].y], 1, 1, n, y - a[x].v);
          a[x].v = y;
        } else {
          add(f[a[x].x], f[a[x].x], 1, 1, n, y - a[x].v);
          a[x].v = y;
          sav[a[x].x] = y;
        }
      } else {
        long long ans;
        ans = query(f[x], f[x], 1, 1, n) - query(f[y], f[y], 1, 1, n) - sav[x] +
              sav[y];
        ans = -ans;
        if (f[y] >= st[x] && f[y] <= ed[x])
          ;
        else {
          ans += query(st[x], ed[x], 1, 1, n);
        }
        printf("%I64d\n", ans);
      }
    }
  }
}
