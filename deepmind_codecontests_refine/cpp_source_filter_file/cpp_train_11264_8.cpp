#include <bits/stdc++.h>
using namespace std;
long long _gcd(long long x, long long y) { return (!y ? x : _gcd(y, x % y)); }
long long _lcm(long long x, long long y) { return x / _gcd(x, y) * y; }
int main() {
  std::ios_base::sync_with_stdio(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  if (n == 1 && k) return cout << 0, 0;
  if (s[0] != '1') s[0] = '1', k--;
  for (int i = 1; i < n; i++) {
    if (s[i] != '0' && k) s[i] = '0', k--;
  }
  cout << s << "\n";
}
