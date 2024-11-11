#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) {
  long long x = (a / gcd(a, b)) * b;
  return x;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, x = 0, y, k, z, m;
  cin >> t;
  long long a[t + 1], b[t + 1];
  for (long long i = 0; i < t; i++) cin >> a[i] >> b[i];
  for (long long i = 0; i < t; i++) {
    for (long long j = 0; j < t; j++) {
      if (i == j) continue;
      if (a[i] == b[j]) {
        x++;
        break;
      }
    }
  }
  cout << t - x << '\n';
  return 0;
}
