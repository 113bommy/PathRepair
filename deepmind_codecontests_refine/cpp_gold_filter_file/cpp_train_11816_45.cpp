#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int M = 2e5 + 5;
int h, w, n, ans;
int f[M] = {1}, g[M];
int pow(int x, int step) {
  int res = 1;
  while (step) {
    if (step & 1) res = 1ll * res * x % mod;
    step >>= 1, x = 1ll * x * x % mod;
  }
  return res;
}
struct point {
  int x, y, res;
} A[2005];
bool cmp(point a, point b) { return a.x ^ b.x ? a.x < b.x : a.y < b.y; }
int C(int h, int w) { return 1ll * f[h + w] * g[h] % mod * g[w] % mod; }
int main() {
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 1; i < M; ++i) f[i] = 1ll * f[i - 1] * i % mod;
  g[M - 1] = pow(f[M - 1], mod - 2), g[0] = 1;
  for (int i = M - 2; i; --i) g[i] = 1ll * g[i + 1] * (i + 1) % mod;
  for (int i = 1; i <= n; ++i) scanf("%d%d", &A[i].x, &A[i].y);
  A[++n] = {h, w, 0}, sort(A + 1, A + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    A[i].res = C(A[i].x - 1, A[i].y - 1);
    for (int j = 1; j < i; ++j) {
      if (A[i].y >= A[j].y) {
        A[i].res -= 1ll * A[j].res * C(A[i].x - A[j].x, A[i].y - A[j].y) % mod;
        A[i].res = (A[i].res % mod + mod) % mod;
      }
    }
  }
  printf("%d", A[n].res);
  return 0;
}
