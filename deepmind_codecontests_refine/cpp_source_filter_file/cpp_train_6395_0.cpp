#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int n_ = 1e5 + 1000;
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
int t, n, p, cnt;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cnt = 0;
    cin >> n >> p;
    for (int i = 0; i < n && cnt < 2 * n + p; i++) {
      for (int j = i + 1; j < n; j++) {
        if (cnt > 2 * n + p) break;
        cnt++;
        cout << i + 1 << " " << j + 1 << endl;
      }
    }
  }
  return 0;
}
