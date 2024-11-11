#include <bits/stdc++.h>
using namespace std;
long long read(long long x = 0) {
  long long c, f = 1;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  return f * x;
}
long long rankc[1010][1010], rankr[1010][1010], a[1010][1010], cntr[1010],
    cntc[1010], N, M, tmp[1010], v[1010];
void process(long long *rank, long long &cnt, long long len) {
  long long i;
  for (i = 1; i <= len; i++) v[i] = tmp[i];
  sort(v + 1, v + len + 1);
  cnt = 1;
  for (i = 2; i <= len; i++)
    if (v[i] != v[i - 1]) v[++cnt] = v[i];
  for (i = 1; i <= len; i++)
    rank[i] = lower_bound(v + 1, v + len + 1, tmp[i]) - v;
}
void init() {
  long long i, j;
  N = read(), M = read();
  for (i = 1; i <= N; i++)
    for (j = 1; j <= M; j++) a[i][j] = read();
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= M; j++) tmp[j] = a[i][j];
    process(rankr[i], cntr[i], M);
  }
  for (j = 1; j <= M; j++) {
    for (i = 1; i <= N; i++) tmp[i] = a[i][j];
    process(rankc[j], cntc[j], N);
  }
}
void work() {
  long long i, j, a, b, rk;
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= M; j++) {
      a = rankr[i][j], b = rankc[j][i];
      rk = max(a, b);
      printf("%lld ", max(cntr[i] + rk - a, cntc[j] + rk - b));
    }
    putchar(10);
  }
}
int main() {
  init();
  work();
  return 0;
}
