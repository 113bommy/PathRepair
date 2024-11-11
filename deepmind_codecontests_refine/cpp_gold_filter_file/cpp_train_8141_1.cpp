#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const long long N = 1e6 + 5;
void pairsort(long long a[], long long b[], long long n) {
  pair<long long, long long> pairt[n];
  for (long long i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (long long i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
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
long long C(long long n, long long r) {
  if (r > n - r) r = n - r;
  long long ans = 1;
  for (long long i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
long long mod = 1e9 + 7;
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % mod;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % mod;
    res %= mod;
  }
  return res;
}
long long t, n, x;
string s;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> s;
    set<long long> ss;
    for (long long i = 0; i + 4 < s.length(); i++)
      if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' &&
          s[i + 3] == 'n' && s[i + 4] == 'e')
        ss.insert(i + 2);
    for (long long i = 0; i + 2 < s.length(); i++)
      if (!ss.count(i) && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
        ss.insert(i + 1);
    for (long long i = 0; i + 2 < s.length(); i++)
      if (!ss.count(i + 2) && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
        ss.insert(i + 1);
    cout << ss.size() << "\n";
    for (auto it = ss.begin(); it != ss.end(); it++) cout << *it + 1 << " ";
    cout << "\n";
  }
  return 0;
}
