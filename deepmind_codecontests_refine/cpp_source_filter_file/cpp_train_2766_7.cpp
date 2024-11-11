#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void print(int x) {
  write(x);
  printf(" ");
}
long long pow_mod(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % 998244353;
    a = a * a % 998244353;
    b >>= 1;
  }
  return ret;
}
int R[50005 * 4], L;
void NTT(long long *y, int len, int on) {
  for (int i = 0; i < len; i++)
    if (i < R[i]) swap(y[i], y[R[i]]);
  for (int i = 1; i < len; i <<= 1) {
    long long wn = pow_mod(3, (998244353 - 1) / (i << 1));
    if (on == -1) wn = pow_mod(wn, 998244353 - 2);
    for (int j = 0; j < len; j += (i << 1)) {
      long long w = 1;
      for (int k = 0; k < i; k++) {
        long long u = y[j + k];
        long long v = y[j + k + i] * w % 998244353;
        y[j + k] = (u + v) % 998244353;
        y[j + k + i] = (u - v + 998244353) % 998244353;
        w = w * wn % 998244353;
      }
    }
  }
  if (on == -1) {
    long long tmp = pow_mod(len, 998244353 - 2);
    for (int i = 0; i < len; i++) y[i] = y[i] * tmp % 998244353;
  }
}
long long A[50005 * 4], B[50005 * 4], C[50005 * 4];
long long n1[50005 * 4], n2[50005 * 4], n3[50005 * 4];
long long s1[50005 * 4], s2[50005 * 4], s3[50005 * 4], s4[50005 * 4],
    s5[50005 * 4];
int n, K;
void update(int len) {
  memcpy(n1, A, sizeof(n1));
  memcpy(n2, B, sizeof(n2));
  memcpy(n3, C, sizeof(n3));
  NTT(n1, len, 1);
  NTT(n2, len, 1);
  NTT(n3, len, 1);
  for (int i = 0; i < len; i++) s1[i] = n1[i] * n1[i] % 998244353;
  for (int i = 0; i < len; i++) s2[i] = n2[i] * n2[i] % 998244353;
  for (int i = 0; i < len; i++) s3[i] = n1[i] * n2[i] % 998244353;
  for (int i = 0; i < len; i++) s4[i] = n2[i] * n3[i] % 998244353;
  for (int i = 0; i < len; i++) s5[i] = n3[i] * n3[i] % 998244353;
  NTT(s1, len, -1);
  NTT(s2, len, -1);
  NTT(s3, len, -1);
  NTT(s4, len, -1);
  NTT(s5, len, -1);
  for (int i = 1; i <= K; i++) A[i] = (s1[i] + s2[i - 1]) % 998244353;
  A[0] = s1[0];
  for (int i = 1; i <= K; i++) B[i] = (s3[i] + s4[i - 1]) % 998244353;
  B[0] = s3[0];
  for (int i = 1; i <= K; i++) C[i] = (s2[i] + s5[i - 1]) % 998244353;
  C[0] = s2[0];
}
long long tmp[50005 * 4], t1[50005 * 4];
void vio(int ok) {
  memcpy(tmp, A, sizeof(tmp));
  for (int i = 1; i <= min(K, ok); i++)
    A[i] = (A[i] + tmp[i - 1] + B[i - 1]) % 998244353;
  memcpy(t1, B, sizeof(t1));
  memcpy(B, tmp, sizeof(B));
  memcpy(C, t1, sizeof(C));
}
int gets(int u) {
  int ret = 0;
  for (; u; u >>= 1) ret++;
  return ret;
}
int main() {
  n = read();
  K = read();
  int ln = 1;
  for (ln = 1; ln <= 2 * K; ln <<= 1) L++;
  for (int i = 0; i < ln; i++) R[i] = (R[i >> 1] >> 1) | (i & 1) << (L - 1);
  A[0] = 1;
  int lg = gets(n);
  int sum = 0;
  for (int i = lg - 1; i >= 0; i--) {
    update(ln);
    sum <<= 1;
    if (sum == 2) C[1] = 0;
    if (n & (1 << i)) sum |= 1, vio(sum);
  }
  for (int i = 1; i <= sum; i++) printf("%lld ", A[i]);
  puts("");
  return 0;
}
