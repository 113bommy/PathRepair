#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
double eps = 1e-12;
long long hcf(long long p, long long q) {
  if (p > q) return hcf(q, p);
  if (!p) return q;
  return hcf(q % p, p);
}
long long lcm(long long p, long long q) { return p * q / hcf(p, q); }
long long power(long long a, long long n, long long mod) {
  long long ans = 1;
  while (n) {
    if (n % 2) ans *= a;
    a *= a;
    n /= 2;
    a %= mod;
    ans %= mod;
  }
  return ans;
}
long long fac(long long k, long long mod) {
  long long ans = 1;
  for (long long i = 1; i < k + 1; i++) {
    ans *= i;
    ans %= mod;
  }
  return ans;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(m);
  for (long long i = 0; i < m; i++) cin >> a[i];
  long long ans = 0, v = k;
  for (long long i = 0; i < m; i++) {
    long long j = i;
    while (a[j] <= v) {
      j++;
      if (j >= m) break;
    }
    j--;
    if (j < i) {
      long long v1 = a[i] - v;
      v += v1 / k * k;
      if (v < a[i]) v += k;
      i--;
      continue;
    }
    ans++;
    v += j - i + 1;
    i = j;
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
