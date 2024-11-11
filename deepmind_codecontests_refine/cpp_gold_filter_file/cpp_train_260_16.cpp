#include <bits/stdc++.h>
using namespace std;
const long long N = 22;
const long long M = 100005;
long long a[1 << N];
long long b[1 << N];
long long tmp[1 << N];
char ss[N][M];
long long n, nn, m;
void FWT(long long *a, long long n, long long o) {
  for (long long u = 1; u <= n; u <<= 1) {
    for (long long i = 0; i <= n; i++) tmp[i] = 0;
    for (long long i = 0; i <= n; i++) {
      if (u & i)
        tmp[i] -= a[i], tmp[i ^ u] += a[i];
      else
        tmp[i] += a[i], tmp[i ^ u] += a[i];
    }
    for (long long i = 0; i <= n; i++) {
      a[i] = tmp[i];
      if (o == -1) a[i] /= 2;
    }
  }
}
int main() {
  scanf("%lld%lld", &n, &m);
  nn = (1 << n);
  nn--;
  for (long long u = 1; u <= n; u++) scanf("%s", ss[u] + 1);
  for (long long u = 1; u <= m; u++) {
    long long now = 0;
    for (long long i = 1; i <= n; i++) now = ((now << 1) + ss[i][u] - '0');
    a[now]++;
  }
  b[0] = 0;
  for (long long u = 1; u <= nn; u++) b[u] = b[u >> 1] + (u & 1);
  for (long long u = 0; u <= nn; u++) b[u] = min(b[u], n - b[u]);
  FWT(a, nn, 1);
  FWT(b, nn, 1);
  for (long long u = 0; u <= nn; u++) a[u] = a[u] * b[u];
  FWT(a, nn, -1);
  long long ans = n * m;
  for (long long u = 0; u <= nn; u++) ans = min(ans, a[u]);
  printf("%lld\n", ans);
  return 0;
}
