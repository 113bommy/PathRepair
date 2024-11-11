#include <bits/stdc++.h>
const int N = 500010;
using namespace std;
int R[N << 2];
long long qpow(long long x, int n, long long P) {
  long long ans = 1;
  for (; n; n >>= 1, x = x * x % P)
    if (n & 1) ans = ans * x % P;
  return ans;
}
void DFT(long long a[], int n, int tp_k, long long P) {
  for (int i = 0; i < n; i++)
    if (i < R[i]) swap(a[i], a[R[i]]);
  for (int d = 1; d < n; d <<= 1) {
    long long wn = qpow(3, (P - 1) / (d << 1), P);
    if (tp_k == -1) wn = qpow(wn, P - 2, P);
    for (int i = 0; i < n; i += (d << 1)) {
      long long wt = 1;
      for (int k = 0; k < d; k++, wt = wt * wn % P) {
        long long A0 = a[i + k], A1 = wt * a[i + k + d] % P;
        a[i + k] = A0 + A1;
        a[i + k + d] = A0 + P - A1;
        if (a[i + k] >= P) a[i + k] -= P;
        if (a[i + k + d] >= P) a[i + k + d] -= P;
      }
    }
  }
  long long inv = qpow(n, P - 2, P);
  if (tp_k == -1)
    for (int i = 0; i < n; i++) a[i] = a[i] * inv % P;
}
long long A[N << 2], B[N << 2];
int main() {
  int n, K;
  cin >> n >> K;
  int L = 0, tot;
  while ((1 << L) < 1000 * K) L++;
  tot = (1 << L);
  for (int i = 1; i < tot; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
  for (int i = 1, x; i <= n; i++) scanf("%d", &x), A[x] = 1, B[x] = 1;
  DFT(A, tot, 1, 998244353LL);
  for (int i = 0; i < tot; i++) A[i] = qpow(A[i], K, 998244353LL);
  DFT(A, tot, -1, 998244353LL);
  DFT(B, tot, 1, 469762049LL);
  for (int i = 0; i < tot; i++) B[i] = qpow(B[i], K, 469762049LL);
  DFT(B, tot, -1, 469762049LL);
  for (int i = 0; i < tot; i++)
    if (A[i] || B[i]) printf("%d ", i);
  printf("\n");
  return 0;
}
