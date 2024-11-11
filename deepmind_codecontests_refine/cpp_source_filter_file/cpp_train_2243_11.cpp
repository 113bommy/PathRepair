#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O2")
#pragma GCC optimization("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int N = 500005;
const long long MOD = 1e6 + 3;
struct Combinatorics {
  long long fac[N], inv[N];
  long long BigMod(long long b, long long p, long long m) {
    long long ret = 1;
    while (p > 0) {
      if (p % 2 == 1) ret = (ret * b) % m;
      p = p >> 1;
      b = (b * b) % m;
    }
    return ret;
  }
  void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = (fac[i - 1] * i) % MOD;
    for (int i = 0; i < N; i++) inv[i] = BigMod(fac[i], MOD - 2, MOD);
  }
  long long com(long long n, long long r) {
    if (n < r) return 0;
    long long u = fac[n];
    long long v = (inv[r] * inv[n - r]) % MOD;
    return (u * v) % MOD;
  }
} combi;
int main() {
  combi.init();
  int n, c;
  cin >> n >> c;
  long long ans = combi.com(n + c, c);
  ans = (ans + MOD - 1) % MOD;
  cout << ans << "\n";
}
