#include <bits/stdc++.h>
using namespace std;
inline int _Int() {
  char INPUT[15];
  scanf("%s", INPUT);
  return atoi(INPUT);
}
inline long long int _LL() {
  char INPUT[70];
  scanf("%s", INPUT);
  return atoll(INPUT);
}
long long int bigMod(long long int A, long long int P, int M) {
  long long int R = 1;
  for (A %= M; P; P >>= 1) {
    if (P & 1) R = (R * A) % M;
    A = (A * A) % M;
  }
  return R;
}
long long int bigMul(long long int A, long long int B, long long int M) {
  long long int R = 0;
  for (A %= M; B; B >>= 1) {
    if (B & 1) R = (R + A) % M;
    A = (A + A) % M;
  }
  return R;
}
long long int _bigMod(long long int A, long long int P, long long int M) {
  long long int R = 1;
  for (A %= M; P; P >>= 1) {
    if (P & 1) R = bigMul(R, A, M);
    A = bigMul(A, A, M);
  }
  return R;
}
long long int _pow(long long int A, long long int P) {
  long long int R = 1;
  for (; P; P >>= 1) {
    if (P & 1) R = (R * A);
    A = (A * A);
  }
  return R;
}
template <class T>
T GCD(T x, T y) {
  while (x) x ^= y ^= x ^= y %= x;
  return y;
}
int x;
int y;
int dp[2][2][55][55];
int call(bool turn, bool per, int a, int b) {
  if (dp[turn][per][a][b] != -1) return dp[turn][per][a][b];
  int ret = 0;
  if (turn == 0) {
    if (a == 0) return (per);
    ret += call(1, per, max(a - 1, 0), b);
  } else {
    if (b == 0) return (!per);
    ret += call(0, per, a, max((b - 1), 0));
  }
  return dp[turn][per][a][b] = ret;
}
int main() {
  int a = _Int();
  int b = _Int();
  x = _Int();
  y = _Int();
  memset(dp, -1, sizeof(dp));
  int p = call(0, 0, a, b);
  int q = call(0, 1, a, b);
  if (p >= q)
    printf("First");
  else
    printf("Second");
  return 0;
}
