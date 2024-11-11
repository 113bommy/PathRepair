#include <bits/stdc++.h>
using namespace std;
template <typename X>
inline X abs(const X& a) {
  return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X& a) {
  return a * a;
}
long long combine(long long n, int k) {
  long long ans = 1;
  for (int i = 0; i < k; i++) ans = (ans * (n - i)) / (i + 1);
  return ans;
}
long long pw(long long a, long long p) {
  if (p == 0) return 1;
  if (p == 1) return a;
  long long half = pw(a, p / 2);
  if (p % 2 == 0) return half * half;
  return half * half * a;
}
long long dis(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
int main() {
  int n, r[20], m[20];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> m[i];
  for (int i = 0; i < n; i++) cin >> r[i];
  int ma = 1;
  for (int i = 0; i < n; i++) ma = lcm(ma, m[i]);
  double ans = 0;
  for (int i = 1; i <= ma; i++) {
    bool yep = false;
    for (int j = 0; j < n; j++) {
      if (i % m[j] == r[j]) {
        yep = true;
        break;
      }
    }
    if (yep) ans++;
  }
  cout << fixed << setprecision(6) << ans / ((double)ma) << endl;
  return 0;
}
