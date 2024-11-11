#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
const int p = 998244353;
long long f[N], dp[N][N], C[N][N];
long long fpow(register long long a, register long long b) {
  register long long res = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) res = res * a % p;
  return res;
}
int main() {
  register int n, m;
  scanf("%d%d", &n, &m);
  printf("%lld\n", fpow(n + 1, m - 1) * fpow(2, m) % p * (n - m + 1) % p);
  return 0;
}
