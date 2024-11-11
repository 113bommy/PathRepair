#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long power(long long x, unsigned long long y, long long p = 1000000007) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long digit(long long n) {
  long long ans = 0;
  while (n) {
    ans++;
    n /= 10;
  }
  return ans;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
vector<long long> sieve(long long n) {
  long long *arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  map<char, long long> m;
  long long len = s.size();
  if (len % n) {
    cout << -1 << endl;
    return;
  }
  for (auto i : s) {
    m[i]++;
  }
  string ans = "";
  for (auto i : m) {
    if (i.second % n) {
      cout << -1 << endl;
      return;
    }
    for (long long j = 0; j < i.second / n; j++) {
      ans += i.first;
    }
  }
  for (long long i = 0; i < len / ans.size(); i++) {
    cout << ans;
  }
  cout << endl;
}
int32_t main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
