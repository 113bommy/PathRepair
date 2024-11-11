#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e6 + 5;
const int MOD = 998244353;
long long inv[MAXN] = {0, 1};
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
int main() {
  int n = read(), m = read();
  int mx = max(n, m) + 1;
  for (int i = 2; i <= mx; i++) inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
  long long ans = n * inv[m + 1] % MOD + 1;
  long long tmp = 0;
  for (int i = 1; i <= n; i++) (tmp += inv[i]) %= MOD;
  tmp *= m, tmp = (tmp + 1) % MOD;
  printf("%lld\n", ans * tmp % MOD);
}
