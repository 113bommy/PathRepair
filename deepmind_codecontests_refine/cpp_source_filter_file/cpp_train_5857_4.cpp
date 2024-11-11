#include <bits/stdc++.h>
using namespace std;
long long Min(long long a, long long b) { return (a < b) ? a : b; }
long long Max(long long a, long long b) { return (a < b) ? b : a; }
long long gcd(long long m, long long n) {
  if (n == 0) return m;
  return gcd(n, m % n);
}
long long lcm(long long m, long long n) { return m * n / gcd(m, n); }
void solve() {
  long long a, b;
  cin >> a >> b;
  if (a < b) {
    cout << a * (a - 1) / 2 + 1 << '\n';
  } else {
    cout << b * (b + 1) / 2 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
