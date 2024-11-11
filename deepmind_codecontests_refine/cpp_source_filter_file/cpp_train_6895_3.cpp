#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e5 + 5;
const long long INF = 1e18;
const long long MOD = 998244353;
int fact[maxN], inv[maxN];
long long D;
vector<long long> vec;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
int modP(int a, int b = MOD - 2) {
  if (!b) return 1;
  int c = modP(a, b >> 1);
  c = (1ll * c * c) % MOD;
  if (b & 1) c = (1ll * c * a) % MOD;
  return c;
}
int ans(long long x) {
  int sum = 0;
  int res = 1;
  for (int d : vec) {
    int cnt = 0;
    while (x % d == 0) {
      x /= d;
      cnt++;
    }
    res = (1ll * res * inv[cnt]) % MOD;
    sum += cnt;
  }
  res = (1ll * res * fact[sum]) % MOD;
  return res;
}
int main() {
  time_t START = clock();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  for (int i = 1; i < maxN; i++) fact[i] = (1ll * i * fact[i - 1]) % MOD;
  inv[maxN - 1] = modP(fact[maxN - 1]);
  for (int i = maxN - 1; i > 0; i--) inv[i - 1] = (1ll * i * inv[i]) % MOD;
  int q;
  scanf("%lld%d", &D, &q);
  for (int i = 2; 1ll * i * i <= D; i++)
    if (!(D % i)) {
      vec.push_back(i);
      while (D % i == 0) D /= i;
    }
  if (D > 1) vec.push_back(D);
  while (q--) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    long long g = gcd(u, v);
    u /= g;
    v /= g;
    printf("%lld\n", 1ll * ans(u) * ans(v) % MOD);
  }
  time_t FINISH = clock();
  cerr << "Execution time: "
       << (long double)(FINISH - START) / CLOCKS_PER_SEC * 1000.0
       << " milliseconds.\n";
  return 0;
}
