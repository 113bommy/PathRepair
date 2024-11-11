#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
int n, fa[MAXN];
struct Node {
  int x, y1, y2;
  int h, id, tp;
} a[MAXN];
long long Len[MAXN];
vector<int> ve;
int getid(int x) {
  return lower_bound(ve.begin(), ve.end(), x) - ve.begin() + 1;
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void Union(int u, int v) {
  if (find(u) != find(v)) {
    fa[find(u)] = find(v);
  }
}
bool cmp(Node a, Node b) {
  if (a.x != b.x)
    return a.x < b.x;
  else
    return a.tp < b.tp;
}
int sum[MAXN << 2], id[MAXN << 2];
bool vis[MAXN << 2];
void PushUp(int rt) {
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
  id[rt] = max(id[rt << 1], id[rt << 1 | 1]);
}
void Add(int pos, int i, int l, int r, int rt) {
  vis[rt] = false;
  if (l == r) {
    sum[rt] = 1;
    id[rt] = i;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    Add(pos, i, l, mid, rt << 1);
  else
    Add(pos, i, mid + 1, r, rt << 1 | 1);
  PushUp(rt);
}
void Del(int pos, int i, int l, int r, int rt) {
  vis[rt] = false;
  if (l == r) {
    sum[rt] = 0;
    id[rt] = 0;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    Del(pos, i, l, mid, rt << 1);
  else
    Del(pos, i, mid + 1, r, rt << 1 | 1);
  PushUp(rt);
}
void dfs(int l, int r, int rt) {
  if (l == r || vis[rt]) return;
  vis[rt] = true;
  if (id[rt << 1] && id[rt << 1 | 1]) {
    Union(id[rt << 1], id[rt << 1 | 1]);
  }
  int mid = l + r >> 1;
  dfs(l, mid, rt << 1);
  dfs(mid + 1, r, rt << 1 | 1);
}
int Query(int L, int R, int i, int l, int r, int rt) {
  if (L <= l && r <= R) {
    if (id[rt]) {
      Union(id[rt], i);
      dfs(l, r, rt);
    }
    return sum[rt];
  }
  int mid = l + r >> 1, ret = 0;
  if (L <= mid) ret += Query(L, R, i, l, mid, rt << 1);
  if (R > mid) ret += Query(L, R, i, mid + 1, r, rt << 1 | 1);
  return ret;
}
int main() {
  scanf("%d", &n);
  int x1, x2, y1, y2, tot = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == x2) {
      tot++;
      a[tot].x = x1, a[tot].y1 = y1, a[tot].y2 = y2;
      a[tot].h = y2 - y1 + 1, a[tot].id = i, a[tot].tp = 2;
      ve.push_back(y1);
      ve.push_back(y2);
    } else {
      tot++;
      a[tot].x = x1, a[tot].y1 = a[tot].y2 = y1;
      a[tot].h = 0, a[tot].id = i, a[tot].tp = 1;
      tot++;
      a[tot].x = x2, a[tot].y1 = a[tot].y2 = y2;
      a[tot].h = 0, a[tot].id = i, a[tot].tp = 3;
      Len[i] = x2 - x1 + 1;
      ve.push_back(y1);
    }
  }
  sort(ve.begin(), ve.end());
  ve.erase(unique(ve.begin(), ve.end()), ve.end());
  int N = ve.size();
  for (int i = 1; i <= tot; i++) {
    a[i].y1 = getid(a[i].y1);
    a[i].y2 = getid(a[i].y2);
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  sort(a + 1, a + 1 + tot, cmp);
  for (int i = 1; i <= tot; i++) {
    if (a[i].tp == 2) {
      Len[a[i].id] = a[i].h - Query(a[i].y1, a[i].y2, a[i].id, 1, N, 1);
    } else if (a[i].tp == 1) {
      Add(a[i].y1, a[i].id, 1, N, 1);
    } else {
      Del(a[i].y1, a[i].id, 1, N, 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (find(i) != i) Len[find(i)] += Len[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, Len[i]);
  }
  printf("%I64d\n", ans - 1);
}
