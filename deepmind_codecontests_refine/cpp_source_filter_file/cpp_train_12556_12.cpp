#include <bits/stdc++.h>
const int MOD = 1000000007;
const int Inv2 = 500000004;
inline int mul(int x, int y) { return (long long)x * (long long)y % MOD; }
inline int add(int x, int y) {
  int r = x + y;
  if (r >= MOD) r -= MOD;
  return r;
}
inline int qpow(int a, int p) {
  int x = a, ans = 1;
  while (p) {
    if (p & 1) ans = mul(ans, x);
    x = mul(x, x);
    p >>= 1;
  }
  return ans;
}
using namespace std;
template <typename T>
inline void read(T &x) {
  char ch;
  while ((ch = getchar()), (ch < '0' || ch > '9'))
    ;
  x = ch - '0';
  while ((ch = getchar()), (ch >= '0' && ch <= '9')) x = x * 10 + (ch - '0');
}
inline int readbin(int *str) {
  char ch;
  int len = 1;
  while ((ch = getchar()), (ch < '0' || ch > '1'))
    ;
  *(str++) = ch - '0';
  while ((ch = getchar()), (ch >= '0' && ch <= '1')) *(str++) = ch - '0', len++;
  return len;
}
void fwt(int A[], int n) {
  int i, h, k, A0, A1;
  for (h = 2; h <= n; h <<= 1) {
    for (i = 0; i < n; i += h) {
      for (k = i; k < i + (h / 2); k++) {
        A0 = A[k];
        A1 = A[k + (h / 2)];
        A[k] = (A0 + A1) % MOD;
        A[k + (h / 2)] = (A0 - A1) % MOD;
      }
    }
  }
}
void ifwt(int A[], int n) {
  int i, h, k, A0, A1;
  for (h = 2; h <= n; h <<= 1) {
    for (i = 0; i < n; i += h) {
      for (k = i; k < i + (h / 2); k++) {
        A0 = A[k];
        A1 = A[k + (h / 2)];
        A[k] = mul(Inv2, A0 + A1);
        A[k + (h / 2)] = mul(Inv2, A0 - A1);
      }
    }
  }
}
const int MAXN = 5 + (1 << 20);
int A[MAXN], P[MAXN];
int N, NB;
int main() {
  int i;
  read(NB);
  N = readbin(A);
  fwt(A, N);
  for (i = 0; i < N; i++) P[i] = mul(A[i], A[i]);
  ifwt(P, N);
  int Ans = 0;
  for (i = 0; i < N; i++)
    Ans = add(Ans, mul(P[i], 1 << (NB - __builtin_popcount(i))));
  Ans = mul(Ans, NB);
  printf("%d", Ans);
}
