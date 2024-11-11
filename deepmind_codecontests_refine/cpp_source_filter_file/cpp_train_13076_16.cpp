#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
long long lcm(long long a, long long b) { return (a * b) / (gcd(a, b)); }
long long mpow(long long base, long long exp) {
  base %= 1000000007;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % 1000000007;
    base = (base * base) % 1000000007;
    exp >>= 1;
  }
  return result;
}
void solve() {}
long long flip(bool a, bool b, bool c, long long val) { return 0; }
int32_t main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n;
  cin >> n;
  long long ans = 1;
  long long z[7];
  for (long long i = 0; i < 7; i++) {
    z[i] = 0;
  }
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long j = 0; j < 7; j++) {
      if (s[j] == '1') {
        z[j]++;
      }
    }
  }
  for (long long i = 0; i < 7; i++) {
    if (z[i] > ans) {
      ans = z[i];
    }
  }
  cout << ans;
  return 0;
}
