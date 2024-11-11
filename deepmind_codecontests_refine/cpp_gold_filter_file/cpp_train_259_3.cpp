#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 10;
int a[maxn], b[maxn], c[maxn];
int n, m, fib[maxn];
int sum[2][maxn << 2], sz[maxn << 2];
void gather(int p) {
  sz[p] = sz[p << 1] + sz[p << 1 | 1];
  sum[0][p] = (sum[0][p << 1] + fib[sz[p << 1] + 1] * sum[0][p << 1 | 1] +
               fib[sz[p << 1]] * sum[1][p << 1 | 1]) %
              m;
  if (sz[p << 1])
    sum[1][p] = (sum[1][p << 1] + fib[sz[p << 1]] * sum[0][p << 1 | 1] +
                 fib[sz[p << 1] - 1] * sum[1][p << 1 | 1]) %
                m;
  else
    sum[1][p] = sum[1][p << 1 | 1];
}
void modify(int p, int tl, int tr, int x, int v) {
  if (tr < x || x < tl) return;
  if (tl == tr) {
    sz[p] = v;
    sum[0][p] = v ? b[tl] % m : 0;
    return;
  }
  int mid = (tl + tr) >> 1;
  modify(p << 1, tl, mid, x, v);
  modify(p << 1 | 1, mid + 1, tr, x, v);
  gather(p);
}
int ans[maxn];
int block, cnt[maxn];
struct query {
  int id, l, r;
} Q[maxn];
bool cmp(query A, query B) {
  if (A.l / block != B.l / block) return A.l / block < B.l / block;
  return A.r < B.r;
}
int main(void) {
  scanf("%d %d", &n, &m);
  fib[1] = fib[2] = 1 % m;
  for (int i = 3; i <= n; i++) fib[i] = (fib[i - 2] + fib[i - 1]) % m;
  for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = a[i];
  sort(b + 1, b + 1 + n);
  int tot = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; i++) c[i] = lower_bound(b + 1, b + 1 + tot, a[i]) - b;
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) scanf("%d %d", &Q[i].l, &Q[i].r), Q[i].id = i;
  block = sqrt(n), sort(Q, Q + q, cmp);
  int l = 1, r = 0;
  for (int i = 0; i < q; i++) {
    while (r < Q[i].r) {
      r++, cnt[c[r]]++;
      if (cnt[c[r]] == 1) modify(1, 1, n, c[r], 1);
    }
    while (r > Q[i].r) {
      cnt[c[r]]--;
      if (!cnt[c[r]]) modify(1, 1, n, c[r], 0);
      r--;
    }
    while (l < Q[i].l) {
      cnt[c[l]]--;
      if (!cnt[c[l]]) modify(1, 1, n, c[l], 0);
      l++;
    }
    while (l > Q[i].l) {
      l--, cnt[c[l]]++;
      if (cnt[c[l]] == 1) modify(1, 1, n, c[l], 1);
    }
    ans[Q[i].id] = sum[0][1];
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
