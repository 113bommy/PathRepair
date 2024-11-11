#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
long long powermod(long long x, long long y) {
  if (y == 0) return 1;
  long long z = powermod(x, y / 2) % 1000000007;
  if (y & 1)
    return (z * z) % 1000000007 * x % 1000000007;
  else
    return (z * z) % 1000000007;
}
long long cal() {
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1') sum = (sum + powermod(2, n - 1)) % 1000000007;
  }
  return sum % 1000000007;
}
signed main() {
  cin >> s;
  n = s.length();
  cout << (cal() * powermod(2, n - 1)) % 1000000007;
}
