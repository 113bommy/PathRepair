#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
const int maxs = 1 << 17;
const int md = 998244353;
const int inv2 = (md + 1) >> 1;
const int inv4 = 748683265;
int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x;
}
int qpow(long long a, long long b) {
  long long res = 1;
  b %= (md - 1);
  while (b) {
    if (b & 1) res = res * a % md;
    a = a * a % md;
    b >>= 1;
  }
  return res;
}
void FWT(int *a, int l, int r) {
  if (l == r) return;
  FWT(a, l, ((l + r) >> 1)), FWT(a, ((l + r) >> 1) + 1, r);
  int len = ((l + r) >> 1) - l + 1;
  for (int i = l; i <= ((l + r) >> 1); ++i) {
    int u = a[i], v = a[i + len];
    a[i] = 1ll * (u + v) % md;
    a[i + len] = 1ll * (u - v + md) % md;
  }
}
void IFWT(int *a, int l, int r) {
  if (l == r) return;
  int len = ((l + r) >> 1) - l + 1;
  for (int i = l; i <= ((l + r) >> 1); ++i) {
    int u = a[i], v = a[i + len];
    a[i] = 1ll * (u + v) * inv2 % md;
    a[i + len] = 1ll * (u - v + md) * inv2 % md;
  }
  IFWT(a, l, ((l + r) >> 1)), IFWT(a, ((l + r) >> 1) + 1, r);
}
int n, k, len, X, Y, Z, tot, s1, s2, s3, s4;
int A[maxs], B[maxs], C[maxs], F[maxs];
int main() {
  n = read(), k = read();
  len = 1 << k;
  X = read(), Y = read(), Z = read();
  for (int i = 1; i <= n; ++i) {
    int a = read(), b = read(), c = read();
    tot ^= a;
    A[a ^ b]++, B[c ^ a]++, C[b ^ c]++;
  }
  s1 = ((long long)X + Y + Z) % md;
  s2 = ((long long)X + Y - Z + md) % md;
  s3 = ((long long)X - Y + Z + md) % md;
  s4 = ((long long)X - Y - Z + md + md) % md;
  FWT(A, 0, len - 1), FWT(B, 0, len - 1), FWT(C, 0, len - 1);
  for (int i = 0; i < len; ++i) {
    int x, y, z, w;
    x = 1ll * ((long long)n + A[i] + B[i] + C[i]) % md * inv4 % md;
    y = (1ll * ((long long)n + A[i]) * inv2 % md - x + md) % md;
    z = (1ll * ((long long)n + B[i]) * inv2 % md - x + md) % md;
    w = (1ll * ((long long)n + C[i]) * inv2 % md - x + md) % md;
    F[i] = 1ll * qpow(s1, x) * qpow(s2, y) % md * qpow(s3, z) % md *
           qpow(s4, w) % md;
  }
  IFWT(F, 0, len - 1);
  for (int i = 0; i < len; ++i) printf("%d ", F[i ^ tot]);
  putchar('\n');
  return 0;
}
