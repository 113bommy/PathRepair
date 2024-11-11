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
int n, m;
long long b;
vector<tuple<long long, long long, int>> v;
long long dp[1 << 20][2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> b;
  for (int i = 0; i < n; i++) {
    long long aa, bb, cc;
    cin >> aa >> bb >> cc;
    v.push_back({bb, aa, cc});
    int xx = 0;
    for (int j = 0; j < get<2>(v[i]); j++) {
      int temp;
      cin >> temp;
      temp--;
      xx = (xx | (1 << temp));
    }
    get<2>(v[i]) = xx;
  }
  long long ans = 2e18;
  sort(v.begin(), v.end());
  for (int j = 0; j < (1 << 20); j++) {
    dp[j][0] = 2e18, dp[j][1] = 2e18;
  }
  dp[0][0] = 0, dp[0][1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << m); j++) {
      if ((j | get<2>(v[i])) == ((1 << m) - 1)) {
        ans = min(ans, dp[j][0] + get<1>(v[i]) + get<0>(v[i]) * b);
      } else {
        dp[(j | get<2>(v[i]))][1] =
            min(dp[(j | get<2>(v[i]))][1], dp[j][0] + get<1>(v[i]));
      }
    }
    for (int j = 0; j < (1 << m); j++) {
      dp[j][0] = dp[j][1];
    }
    dp[0][0] = 0, dp[0][1] = 0;
  }
  if (ans >= 2e18) {
    cout << -1;
  } else {
    cout << ans;
  }
}
