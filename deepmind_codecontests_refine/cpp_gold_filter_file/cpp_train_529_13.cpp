#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a > b ? b : a; }
long long __gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return __gcd(b % a, a);
}
vector<long long> v;
int main() {
  long long n, l, a;
  cin >> n >> l >> a;
  long long ans = 0, last = 0;
  for (int i = 0; i < n; i++) {
    long long t, x;
    cin >> t >> x;
    ans += (t - last) / a;
    last = t + x;
  }
  ans += (l - last) / a;
  cout << ans << endl;
  return 0;
}
