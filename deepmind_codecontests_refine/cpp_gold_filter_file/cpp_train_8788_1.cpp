#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
long long n, m, k, ans, cnt, tot, flag;
long long c[100005], sum[100005], now, oo;
long long dist[505][505];
long long pre[100005], fa[505];
long long Find(long long x) {
  if (x == pre[x]) return x;
  pre[x] = Find(pre[x]);
  return pre[x];
}
void Merge(long long x, long long y) {
  long long u = Find(x), v = Find(y);
  if (x != y) pre[u] = v;
}
int main() {
  long long i, j, t, u, v;
  while (~scanf("%I64d%I64d%I64d", &n, &m, &k)) {
    sum[0] = 0;
    for (i = 1; i <= k; i++) {
      scanf("%I64d", &c[i]);
      sum[i] = sum[i - 1] + c[i];
    }
    for (i = 1; i <= n; i++) pre[i] = i;
    long long u, v, w;
    memset(dist, 0x3f, sizeof(dist));
    oo = dist[0][0];
    for (i = 1; i <= m; i++) {
      scanf("%I64d%I64d%I64d", &u, &v, &w);
      long long posu = lower_bound(sum + 1, sum + k + 1, u) - sum;
      long long posv = lower_bound(sum + 1, sum + k + 1, v) - sum;
      dist[posu][posv] = dist[posv][posu] = min(dist[posu][posv], w);
      if (w == 0) Merge(u, v);
    }
    memset(fa, 0, sizeof(fa));
    flag = 1;
    for (i = 1; i <= n; i++) {
      long long posu = lower_bound(sum + 1, sum + k + 1, i) - sum;
      u = Find(i);
      if (fa[posu]) {
        if (u != fa[posu]) {
          flag = 0;
          break;
        }
      } else {
        fa[posu] = u;
      }
    }
    if (flag)
      printf("Yes\n");
    else {
      printf("No\n");
      continue;
    }
    for (i = 1; i <= k; i++) dist[i][i] = 0;
    for (long long p = 1; p <= k; p++) {
      for (i = 1; i <= k; i++) {
        for (j = 1; j <= k; j++) {
          if (dist[i][j] > dist[i][p] + dist[p][j])
            dist[i][j] = dist[i][p] + dist[p][j];
        }
      }
    }
    for (i = 1; i <= k; i++) {
      for (j = 1; j <= k; j++) {
        if (dist[i][j] >= oo) dist[i][j] = -1;
        if (j == 1)
          printf("%I64d", dist[i][j]);
        else
          printf(" %I64d", dist[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
