#include <bits/stdc++.h>
using namespace std;
const int N = 18;
int n, Q;
int b[N][N];
int popc[1 << N];
long long f[N][1 << N], g[N][1 << N];
long long A[1 << N], h[1 << N];
namespace FWT {
void fwt(long long *a, int len) {
  for (int mid = 1; mid < len; mid <<= 1)
    for (int i = 0; i < len; i += mid << 1)
      for (int j = 0; j < mid; ++j) a[i + mid + j] += a[i + j];
}
void ifwt(long long *a, int len) {
  for (int mid = 1; mid < len; mid <<= 1)
    for (int i = 0; i < len; i += mid << 1)
      for (int j = 0; j < mid; ++j) a[i + mid + j] -= a[i + j];
}
}  // namespace FWT
int cnt[N];
int trans(int sta) {
  int clen = 0, res = 0;
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n - 1; ++i) {
    if (sta >> i & 1) {
      ++clen;
    } else {
      ++cnt[clen];
      clen = 0;
    }
  }
  ++cnt[clen];
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= cnt[i]; ++j) {
      res = res << 1;
      for (int k = 1; k <= i; ++k) res = res << 1 | 1;
    }
  }
  return res;
}
long long solve() {
  memset(h, 0, sizeof h), h[0] = 1;
  FWT::fwt(h, 1 << n);
  for (int i = 0; i < n; ++i)
    for (int j = 1; j <= cnt[i]; ++j)
      for (int sta = 0; sta < (1 << n); ++sta) h[sta] *= g[i][sta];
  FWT::ifwt(h, 1 << n);
  return h[(1 << n) - 1];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < (1 << n); ++i) popc[i] = popc[i >> 1] + (i & 1);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%1d", &b[i][j]);
  for (int i = 0; i < n; ++i) f[i][1 << i] = 1;
  for (int sta = 0; sta < (1 << n); ++sta) {
    for (int u = 0; u < n; ++u)
      if (f[u][sta]) {
        for (int v = 0; v < n; ++v)
          if (~sta >> v & 1) {
            if (b[u][v] != 1) continue;
            f[v][sta | 1 << v] += f[u][sta];
          }
      }
  }
  for (int u = 0; u < n; ++u)
    for (int sta = 1; sta < (1 << n); ++sta) g[popc[sta] - 1][sta] += f[u][sta];
  for (int len = 0; len < n; ++len) FWT::fwt(g[len], 1 << n);
  memset(A, -1, sizeof A);
  for (int sta = 0; sta < (1 << (n - 1)); ++sta) {
    int vsta = trans(sta);
    if (A[vsta] == -1) A[vsta] = solve();
    A[sta] = A[vsta];
  }
  for (int d = 0; d < n - 1; ++d)
    for (int i = (1 << (n - 1)); ~i; --i)
      if (i >> d & 1) A[i ^ 1 << d] -= A[i];
  printf("%lld", A[0]);
  for (int i = 0; i < (1 << (n - 1)); ++i) printf(" %lld", A[i]);
  putchar('\n');
  return 0;
}
