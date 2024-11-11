#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long power(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long min(long long a, long long b) {
  if (a > b)
    return b;
  else
    return a;
}
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<long long> div(long long n) {
  vector<long long> v;
  for (int i = 1; i * i <= n; i++) {
    if ((n % i) == 0) {
      if (i == n / i)
        v.push_back(i);
      else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  return v;
}
long long isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  map<int, int> m;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    vector<long long> v = div(A[i]);
    for (int i = 0; i < v.size(); i++) {
      if (v[i] > 1) m[v[i]]++;
    }
  }
  for (auto it : m) ans = max(ans, (it).second);
  cout << ans << "\n";
}
int main() {
  int T;
  T = 1;
  while (T--) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
}
