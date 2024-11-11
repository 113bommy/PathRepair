#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
bool sortbysec(const pair<long long, long long>& a,
               const pair<long long, long long>& b) {
  if (a.second == b.second) return a.first < b.first;
  return (a.second < b.second);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long isPrime(long long n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n % 2 == 0 or n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 or n % (i + 2) == 0) return 0;
  return 1;
}
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    long long ot = 0, os = 0;
    for (long long i = 0; i < n; ++i) {
      if (s1[i] == '1') os++;
      if (s2[i] == '1') ot++;
    }
    if (ot != os) {
      cout << -1;
      return 0;
    }
    vector<long long> v;
    for (long long i = 0; i < n; ++i) {
      if (s1[i] == s2[i])
        v.push_back(0);
      else if (s1[i] == '1') {
        v.push_back(1);
      } else
        v.push_back(-1);
    }
    long long ans = 0, m1 = 0;
    for (long long i = 0; i < n; ++i) {
      m1 += v[i];
      if (m1 < 0) m1 = 0;
      ans = (ans > m1 ? ans : m1);
    }
    long long m2 = 0;
    for (long long i = 0; i < n; ++i) {
      m2 += v[i];
      if (m2 > 0) m2 = 0;
      ans = (ans > -m2 ? ans : -m2);
    }
    cout << ans;
    cout << "\n";
  }
}
