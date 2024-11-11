#include <bits/stdc++.h>
using namespace std;
int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || '9' < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
const long long Mod = 998244353, g = 3, rg = 332748118;
long long Pow(long long x, int y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % Mod;
    x = (x * x) % Mod;
    y >>= 1;
  }
  return ret;
}
int rev[int(5e6) + 5];
int Len(int n) {
  int len;
  for (len = 1; len < n; len <<= 1)
    ;
  return len;
}
void NTT(long long *A, int len, int sign) {
  for (int i = 0, j = 0; i < len; i++) {
    if (i < j) swap(A[i], A[j]);
    for (int l = (len >> 1); (j ^= l) < l; l >>= 1)
      ;
  }
  for (int k = 1; k < len; k <<= 1) {
    long long w0 = Pow(sign == 1 ? g : rg, (Mod - 1) / (k << 1));
    for (int j = 0, siz = k << 1; j < len; j += siz) {
      long long w = 1;
      for (int i = 0; i < k; i++, w = w * w0 % Mod) {
        long long x = A[i + j], y = w * A[i + j + k] % Mod;
        A[i + j] = (x + y) % Mod, A[i + j + k] = (x - y + Mod) % Mod;
      }
    }
  }
  if (sign == -1) {
    long long Inv = Pow(len, Mod - 2);
    for (int i = 0; i < len; i++) A[i] = (A[i] * Inv % Mod + Mod) % Mod;
  }
  return;
}
long long tmp1[int(5e6) + 5], tmp2[int(5e6) + 5];
void Mul(long long *A, long long *B, long long *C, int n, int m) {
  copy(A, A + n, tmp1), copy(B, B + m, tmp2);
  int len = Len(n + m - 1);
  fill(A + n, A + len, 0), fill(B + m, B + len, 0);
  NTT(tmp1, len, 1), NTT(tmp2, len, 1);
  for (int i = 0; i < len; i++) C[i] = tmp1[i] * tmp2[i] % Mod;
  NTT(C, len, -1);
  return;
}
int a[int(5e6) + 5];
long long A[int(5e6) + 5], B[int(5e6) + 5];
int main() {
  int n = read(), m = read() + 1;
  for (int i = 1; i <= n; i++) a[i] = read(), A[a[i]] = 1;
  Mul(A, A, B, m, m);
  int cnt = 0;
  for (int i = 0; i < m; i++)
    if (B[i] && !A[i]) puts("NO"), exit(0);
  for (int i = 0; i < m; i++)
    if (B[i] && A[i]) cnt++;
  puts("YES");
  printf("%d\n", n - cnt);
  for (int i = 0; i < m; i++)
    if (B[i] && A[i]) printf("%d ", i);
  puts("");
  return 0;
}
