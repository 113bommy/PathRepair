#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct E {
  int v, next;
} e[maxn << 1];
int n, q, a[maxn], in[maxn], out[maxn], len = 1, head[maxn], v, sum[maxn],
                                        flag[maxn << 2], idd[maxn];
char code[4];
void add(int u, int v) {
  e[len].v = v;
  e[len].next = head[u];
  head[u] = len++;
}
int cnt;
void dfs(int u, int fa) {
  in[u] = ++cnt;
  idd[cnt] = u;
  for (int j = head[u]; j; j = e[j].next) {
    int v = e[j].v;
    if (v == fa) continue;
    dfs(v, u);
  }
  out[u] = cnt;
}
void build(int id, int l, int r) {
  if (l == r) {
    sum[id] = a[idd[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  sum[id] = sum[id << 1] + sum[id << 1 | 1];
}
void pushdown(int id, int l, int r) {
  if (flag[id] == 0) return;
  int mid = (l + r) >> 1;
  sum[id << 1] = mid - l + 1 - sum[id << 1];
  sum[id << 1 | 1] = r - mid - sum[id << 1 | 1];
  flag[id << 1] ^= 1;
  flag[id << 1 | 1] ^= 1;
  flag[id] = 0;
}
void update(int id, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    flag[id] ^= 1;
    sum[id] = r - l + 1 - sum[id];
    return;
  }
  pushdown(id, l, r);
  int mid = (l + r) >> 1;
  if (x <= mid) update(id << 1, l, mid, x, y);
  if (y > mid) update(id << 1 | 1, mid + 1, r, x, y);
  sum[id] = sum[id << 1] + sum[id << 1 | 1];
}
int query(int id, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return sum[id];
  }
  int mid = (l + r) >> 1;
  pushdown(id, l, r);
  int ans = 0;
  if (x <= mid) ans += query(id << 1, l, mid, x, y);
  if (y > mid) ans += query(id << 1 | 1, mid + 1, r, x, y);
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &v);
    add(i, v);
    add(v, i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  dfs(1, 0);
  build(1, 1, n);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%s%d", code, &v);
    if (code[0] == 'g') {
      printf("%d\n", query(1, 1, n, in[v], out[v]));
    } else {
      update(1, 1, n, in[v], out[v]);
    }
  }
  return 0;
}
