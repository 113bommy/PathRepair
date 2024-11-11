#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long fast_expo(long long x, long long p) {
  if (p == 0)
    return 1;
  else if (p % 2 == 0) {
    long long t = fast_expo(x, p / 2) % MOD;
    return (t * t) % MOD;
  } else
    return (x * (fast_expo(x, p - 1)) % MOD) % MOD;
}
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0)
    return a + b;
  else
    return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
vector<long long> v;
void primeFactors(long long n) {
  while (n % 2 == 0) {
    v.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      v.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) v.push_back(n);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  map<long long, long long> mp;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  long long pref[n];
  pref[0] = a[0];
  for (long long i = 1; i < n; i++) {
    pref[i] = min(pref[i - 1], a[i]);
  }
  long long suff[n];
  suff[n - 1] = a[n - 1];
  for (long long i = n - 2 - 1; i >= 0; i--) {
    suff[i] = min(suff[i + 1], a[i]);
  }
  for (long long i = 1; i < n - 1; i++) {
    if (a[i] > pref[i - 1] && a[i] > suff[i + 1]) {
      cout << "YES"
              "\n";
      cout << mp[pref[i - 1]] + 1 << " " << mp[a[i]] + 1 << " "
           << mp[suff[i + 1]] + 1;
      return;
    }
  }
  cout << "NO";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
    cout << endl;
  }
  return 0;
}
