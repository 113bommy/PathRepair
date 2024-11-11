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
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  multiset<long long> b;
  for (long long i = 0; i < n; i++) {
    long long k = m - a[i];
    long long count = 0, sum = 0;
    for (auto j : b) {
      if (sum + j <= k) {
        sum += j;
        count++;
      } else
        break;
    }
    cout << i - count << " ";
    b.insert(a[i]);
  }
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
