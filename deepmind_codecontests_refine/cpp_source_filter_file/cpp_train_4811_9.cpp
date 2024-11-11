#include <bits/stdc++.h>
using namespace std;
long long prime[1000000];
long long mulmod(long long a, long long b, long long m) {
  long long res = 0;
  a = a % m;
  while (b > 0) {
    if (b % 2 == 1) res = (res + a) % m;
    a = (a * 2) % m;
    b /= 2;
  }
  return res % m;
}
long long modInverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void sieve() {
  for (long long i = 0; i < 1000000; i++) prime[i] = 1;
  prime[0] = 0;
  prime[1] = 0;
  for (long long i = 2; i * i < 1000000; i++) {
    if (prime[i] == 0) continue;
    for (long long j = i * i; j < 1000000; j += i) {
      prime[j] = 0;
    }
  }
  for (long long i = 1; i < 1000000; i++) prime[i] += prime[i - 1];
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string temp = s;
  for (long long i = 0; i < n - k; i++) {
    s[i + k] = s[i];
  }
  if (s >= temp) {
    cout << n << '\n';
    cout << s << '\n';
    return 0;
  }
  long long c;
  for (long long i = k - 1; i >= 0; i--) {
    if (s[i] - '0' != 9) {
      c = i;
      break;
    }
  }
  long long tmp = s[c] - '0';
  tmp++;
  s[c] = tmp + '0';
  for (long long i = c + 1; i < k; i++) s[i] = 0;
  for (long long i = 0; i < n - k; i++) {
    s[i + k] = s[i];
  }
  cout << n << '\n';
  cout << s << '\n';
  return 0;
}
