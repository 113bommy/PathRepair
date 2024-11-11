#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long add(long long a, long long b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long sub(long long a, long long b) {
  return (((a % mod) - (b % mod)) % mod + mod) % mod;
}
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long Sum(long long i) {
  if (i & 1ll)
    return mul(i, (i + 1) / 2);
  else
    return mul(i / 2, i + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long sum = mul(n, m);
  for (long long i = 1; i * i <= n && i <= m; i++) {
    long long cur = mul(i, n / i);
    sum = sub(sum, cur);
    if (i != n / i) {
      long long v = i;
      cur = mul(v, sub(Sum(min(m, n / v)), Sum(min(m, n / (v + 1)))));
      sum = sub(sum, cur);
    }
  }
  cout << sum << endl;
  return 0;
}
