#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, n, m, s, an, sum, tot = 1, S, T, off, d, M, V;
const long long N = 210;
long long oo = 2147483647;
class arr {
 public:
  long long x, k, m, v;
} a[N];
long long f[1 << 20], g[1 << 20];
bool com(const arr &o, const arr &p) { return o.k < p.k; }
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &V);
  M = 1 << m;
  oo = oo * oo;
  long long s = 0;
  for (long long i = 1; i <= n; i++) {
    scanf("%I64d%I64d%I64d", &a[i].x, &a[i].k, &a[i].m);
    long long x;
    for (long long j = 1; j <= a[i].m; j++)
      scanf("%I64d", &x), a[i].v |= (1 << (x - 1));
    s |= a[i].v;
  }
  if (s != M - 1) {
    printf("-1\n");
    return 0;
  }
  sort(&a[1], &a[n + 1], com);
  for (int i = 0; i < M; i++) f[i] = oo;
  f[0] = 0;
  an = oo;
  for (long long i = 1; i <= n; i++) {
    memcpy(g, f, sizeof(g));
    for (long long j = 0; j < M; j++)
      if (f[j] != oo) g[j | a[i].v] = min(g[j | a[i].v], f[j] + a[i].x);
    memcpy(f, g, sizeof(f));
    if (f[M - 1] != oo) an = min(an, f[M - 1] + a[i].k * V);
  }
  printf("%I64d\n", an);
  return 0;
}
