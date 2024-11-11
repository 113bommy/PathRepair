#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int p[maxn];
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    long long tmp = sum * (100 - p[i]) + 100;
    tmp = tmp * qpow(p[i], mod - 2) % mod;
    sum = (sum + tmp) % mod;
  }
  printf("%lld\n", sum);
  return 0;
}
