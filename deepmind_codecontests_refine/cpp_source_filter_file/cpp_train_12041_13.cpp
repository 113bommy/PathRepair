#include <bits/stdc++.h>
using namespace std;
int const level = 500005;
int const limit = 1000006;
long long int fact[level];
long long int dp[level];
long long int a[limit];
long long int modInverse(long long int a, long long int m) {
  long long int mom = m, y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int top = m;
    m = a % m;
    a = top;
    top = y;
    y = x - q * y;
    x = top;
  }
  if (x < 0) x += mom;
  return x % 1000000007;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res % p;
}
vector<long long int> getAllFactors(long long int n) {
  vector<long long int> v;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        v.push_back(i);
      else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  return v;
}
inline bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
      c == 'E' || c == 'I' || c == 'O' || c == 'U')
    return true;
  else
    return false;
}
inline bool isPowerOfTwo(long long int x) { return x && (!(x & (x - 1))); }
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
inline void preComputeFactorial() {
  fact[0] = 1;
  for (long long int i = 1; i <= level; i++)
    fact[i] = (fact[i - 1] % 1000000007 * i % 1000000007) % 1000000007;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    if (n <= 5)
      cout << "-1" << endl;
    else {
      for (long long int i = 2; i <= 3; i++) cout << "1 " << i << endl;
      for (long long int i = 4; i <= n; i++) cout << "2 " << i << endl;
    }
    for (long long int i = 2; i <= n; i++) cout << "1 " << i << endl;
  }
  return 0;
}
