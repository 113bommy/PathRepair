#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int a[N], b[N], t[N], v[3 * N], p[N], x[N];
int ad[N * 10], tree[N * 10];
int n, m, q, sum;
long long rd() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void init() {
  n = rd();
  m = rd();
  sum = 0;
  for (int i = 1; i <= n; i++) a[i] = rd(), v[++sum] = a[i];
  for (int i = 1; i <= m; i++) b[i] = rd(), v[++sum] = b[i];
  q = rd();
  for (int i = 1; i <= q; i++) {
    t[i] = rd();
    if (t[i] <= 2) {
      p[i] = rd(), x[i] = rd(), v[++sum] = x[i];
    }
  }
  sort(v + 1, v + 1 + sum);
  sum = unique(v + 1, v + sum + 1) - v - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(v + 1, v + sum + 1, a[i]) - v;
  for (int i = 1; i <= m; i++) b[i] = lower_bound(v + 1, v + sum + 1, b[i]) - v;
  for (int i = 1; i <= q; i++)
    if (t[i] <= 2) x[i] = lower_bound(v + 1, v + sum + 1, x[i]) - v;
}
void down(int rt) {
  ad[rt * 2] += ad[rt];
  ad[rt * 2 + 1] += ad[rt];
  tree[rt * 2] += ad[rt];
  tree[rt * 2 + 1] += ad[rt];
  ad[rt] = 0;
}
void upd(int rt, int L, int R, int l, int r, int x) {
  if (l > R || r < L) return;
  if (l <= L && R <= r) {
    tree[rt] += x;
    ad[rt] += x;
    return;
  }
  int mid = (L + R) / 2;
  down(rt);
  upd(rt * 2, L, mid, l, r, x);
  upd(rt * 2 + 1, mid + 1, R, l, r, x);
  tree[rt] = max(tree[rt * 2], tree[rt * 2 + 1]);
}
void add(int x) { upd(1, 1, sum, 0, x, 1); }
void del(int x) { upd(1, 1, sum, 0, x, -1); }
int getit(int rt, int l, int r) {
  if (l == r) return l;
  int m = (l + r) / 2;
  down(rt);
  if (tree[2 * rt + 1] > 0)
    return getit(2 * rt + 1, m + 1, r);
  else
    return getit(2 * rt, l, m);
}
int get() {
  if (tree[1] >= 1)
    return v[getit(1, 1, sum)];
  else
    return -1;
}
void work() {
  for (int i = 1; i <= n; i++) add(a[i]);
  for (int i = 1; i <= m; i++) del(b[i]);
  for (int i = 1; i <= q; i++) {
    if (t[i] == 1) {
      del(a[p[i]]);
      a[p[i]] = x[i];
      add(x[i]);
    }
    if (t[i] == 2) {
      add(b[p[i]]);
      b[p[i]] = x[i];
      del(x[i]);
    }
    printf("%d\n", get());
  }
}
int main() {
  init();
  work();
}
