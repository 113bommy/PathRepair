#include <bits/stdc++.h>
const int fin = 0, maxn = 100010, maxm = maxn << 1;
int n, m, N;
int fs[maxn], next[maxm], oth[maxm];
int q[maxn], b[maxm], fa[maxn];
int main() {
  if (fin) {
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
  }
  int head, tail, i, u, t, x, y;
  scanf("%d", &n), m = 1;
  for (i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    oth[++m] = y, next[m] = fs[x], fs[x] = m;
    oth[++m] = x, next[m] = fs[y], fs[y] = m;
  }
  printf("%d\n", n - 1);
  for (q[head = tail = 1] = 1; head <= tail;)
    for (u = q[head++], i = fs[u]; i; i = next[i])
      if (t = oth[i], t != fa[u]) {
        fa[t] = u, q[++tail] = t, b[i] = b[i ^ 1] = ++N;
        printf("2 %d %d\n", u, t);
      }
  for (u = 1; u <= n; ++u)
    for (t = 0, i = fs[u]; i; i = next[i]) {
      if (t) printf("%d %d\n", t, b[i]);
      t = b[i];
    }
  return 0;
}
