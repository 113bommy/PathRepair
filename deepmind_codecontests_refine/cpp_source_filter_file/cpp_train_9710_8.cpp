#include <bits/stdc++.h>
using namespace std;
struct keycompare {
  bool operator()(const pair<long long, long long>& v, const long long& k) {
    return (v.first < k);
  }
  bool operator()(const long long& k, const pair<long long, long long>& v) {
    return (k < v.first);
  }
};
long long mod1 = 998244353, mod2 = 1000000007, limit = 9223372036854775807;
long double pi = 3.1415926535897932;
long long modpow(long long x, long long n, long long m) {
  if (x > m) {
    x %= m;
  }
  if (n == 0) return 1 % m;
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isprime(long long n) {
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long power(long long x, long long n) {
  long long x_n = 1;
  for (long long i = 0; i < n; i++) {
    x_n *= x;
  }
  return x_n;
}
long long arr[1000006] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> robber(n), ligts(m);
  for (long long i = 0; i < n; i++) {
    cin >> robber[i].first >> robber[i].second;
  }
  for (long long i = 0; i < n; i++) {
    cin >> ligts[i].first >> ligts[i].second;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long temp1 = ligts[j].first - robber[i].first;
      long long temp2 = ligts[j].second - robber[i].second;
      if (temp1 >= 0) {
        arr[temp1] = max(arr[temp1], temp2 + 1);
      }
    }
  }
  long long ans = 10000000000;
  for (long long i = 1000003; i >= 0; i--) {
    arr[i] = max(arr[i], arr[i + 1]);
    ans = min(ans, arr[i] + i);
  }
  cout << ans;
}
