#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int MOD = 1e9 + 7;
int mult(long long a, long long b) { return (a * b) % MOD; }
int pot(int n, int k) {
  int ret = 1, pot = n;
  for (; k > 0; k >>= 1, pot = mult(pot, pot))
    ret = mult(ret, (k & 1) ? pot : 1);
  return ret;
}
int divide(int a, int b) { return mult(a, pot(b, MOD - 2)); }
int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
int n;
int A[maxn];
int cnt[maxn];
int F[maxn];
int main() {
  F[0] = 1;
  for (int i = 1; i < maxn; i++) F[i] = mult(F[i - 1], i);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", A + i);
  sort(A, A + n);
  int pos = 0;
  for (int i = 1; i < n; i++) {
    if (A[i] > A[i - 1]) pos = i;
    cnt[i] = pos;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (A[i] != A[n - 1])
      ans = add(ans, mult(A[i], divide(F[n], sub(n, cnt[i]))));
  printf("%d\n", ans);
  return 0;
}
