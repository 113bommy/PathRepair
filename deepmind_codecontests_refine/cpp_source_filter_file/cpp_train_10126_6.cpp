#include <bits/stdc++.h>
using namespace std;
bool primes[1000001];
vector<long long> prime;
void seive();
long long gcd(long long a, long long b);
long long power(long long x, long long y);
int32_t main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  ;
  while (t--) {
    long long n;
    cin >> n;
    ;
    string s;
    long long arr[26] = {0};
    for (long long i = 0; i < n; i += 1) {
      cin >> s;
      for (long long j = 0; j < s.length(); j += 1) arr[s[j] - 97] += 1;
    }
    bool res = true;
    for (long long i = 0; i < 26; i += 1) {
      if (arr[i] % 2) {
        res = false;
        break;
      }
    }
    if (res)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
void seive() {
  memset(primes, true, sizeof(primes));
  primes[0] = primes[1] = false;
  for (long long i = 2; i * i <= 1000000; i += 1) {
    if (primes[i]) {
      for (long long j = i * i; j <= 1000000; j += i) primes[j] = false;
    }
  }
  for (long long i = 2; i < 1000001; i += 1) {
    if (primes[i]) prime.push_back(i);
  }
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
