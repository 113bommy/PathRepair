#include <bits/stdc++.h>
using namespace std;
int ans, N, mod;
int pow(int a, int b) {
  int p = 1;
  for (int i = 0; (1 << i) <= b; i++) {
    if (b & (1 << i)) p = (1LL * p * a) % mod;
    a = (1LL * a * a) % mod;
  }
  return p;
}
int fac(int N) {
  int p = 1;
  for (int i = 1; i <= N; i++) p = (1LL * p * i) % mod;
  return p;
}
int main() {
  scanf("%d", &N), N++;
  mod = 1000000007;
  int ans = (1LL * 2 * fac(2 * N - 1)) % mod;
  ans = (1LL * ans * pow(fac(N - 1), mod - 2)) % mod;
  ans = (1LL * ans * pow(fac(N), mod - 2)) % mod;
  ans = ((long long)ans + mod - 1) % mod;
  printf("%d\n", ans);
  return 0;
}
