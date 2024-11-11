#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9, MOD = INF + 7;
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
long long mod(long long n) {
  while (n < 0) n += MOD;
  return n % MOD;
}
const long long N = 1e4 + 20;
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  cout << n / 2 << "\n";
  if (n % 2) {
    for (long long i = 0; i < (n / 2) - 1; i++) cout << 2 << " ";
    cout << 3 << "\n";
  } else {
    for (long long i = 0; i < n / 2; i++) cout << 2 << " ";
    cout << "\n";
  }
  return 0;
}
