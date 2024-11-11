#include <bits/stdc++.h>
struct case1 {
  long x, y, in;
} p[1001] = {{0, 0, 0}};
struct case2 {
  long r, x, y, in;
} c[1001] = {{0, 0, 0, 0}};
long link[1001][1001] = {0}, f[1001] = {0}, f2[1001] = {0}, h[1001] = {0},
     head[1001] = {0}, ans[1001][1001] = {0}, next[1001] = {0}, e[1001] = {0};
long totm = 0, m, n;
void add(long a, long b) {
  e[++totm] = b;
  next[totm] = head[a];
  head[a] = totm;
}
long getf(long now, long t[]) {
  if (t[now] == now) return now;
  return t[now] = getf(t[now], t);
}
void work(long now, long dis) {
  long i, j;
  h[now] = dis;
  for (i = head[now]; i; i = next[i])
    for (j = 1; j <= n; j++)
      if (h[p[j].in]) {
        if (getf(p[j].in, f) != getf(now, f))
          ans[e[i]][j] = ans[j][e[i]] = h[now] + h[p[j].in];
        else
          ans[e[i]][j] = ans[j][e[i]] =
              h[now] + h[p[j].in] - 2 * h[getf(p[j].in, f2)];
      }
  for (i = 1; i <= m; i++)
    if (link[now][i]) {
      work(i, dis + 1);
      f2[getf(i, f2)] = getf(now, f2);
    }
}
int main() {
  long i, j, q, t, a, b;
  scanf("%ld%ld%ld", &n, &m, &q);
  for (i = 1; i <= n; i++) scanf("%ld%ld", &p[i].x, &p[i].y);
  for (i = 1; i <= m; i++) scanf("%ld%ld%ld", &c[i].r, &c[i].x, &c[i].y);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++)
      if (((long long)((c[j].x) - (p[i].x)) * ((c[j].x) - (p[i].x)) +
           (long long)((c[j].y) - (p[i].y)) * ((c[j].y) - (p[i].y))) <
              (long long)c[j].r * c[j].r &&
          (p[i].in == 0 || c[p[i].in].r > c[j].r))
        p[i].in = j;
    if (p[i].in) add(p[i].in, i);
  }
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= m; j++)
      if (c[i].r < c[j].r &&
          ((long long)((c[j].x) - (c[i].x)) * ((c[j].x) - (c[i].x)) +
           (long long)((c[j].y) - (c[i].y)) * ((c[j].y) - (c[i].y))) <=
              (long long)(c[i].r - c[j].r) * (c[i].r - c[j].r) &&
          (c[i].in == 0 || c[c[i].in].r > c[j].r))
        c[i].in = j;
    f[i] = f2[i] = i;
  }
  for (i = 1; i <= m; i++)
    if (c[i].in) {
      link[c[i].in][i] = 1;
      f[getf(i, f)] = getf(c[i].in, f);
    }
  for (i = 1; i <= m; i++)
    if (c[i].in == 0) work(i, 1);
  while (q--) {
    scanf("%ld%ld", &a, &b);
    if (p[a].in && p[b].in)
      printf("%ld\n", ans[a][b]);
    else
      printf("%ld\n", h[p[a].in] + h[p[b].in]);
  }
  return 0;
}
