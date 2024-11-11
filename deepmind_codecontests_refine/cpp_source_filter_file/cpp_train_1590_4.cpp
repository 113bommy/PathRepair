#include <bits/stdc++.h>
using namespace std;
const long long infl = 1LL << 60;
int mod = 998244353;
long long exp(int n, int m) {
  if (m == 0) return 1;
  long long x = 1;
  x = x * exp(n, m / 2) * exp(n, m / 2);
  x %= mod;
  if (m % 2 == 1) x = x * n;
  x %= mod;
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long len = pow(1e11, 1.0 / (n - 1));
  long long ans = INT_MAX;
  for (long long j = 1; j <= len; j++) {
    long long bei = 1, sum = 0;
    for (long long k = 0; k < n; k++) {
      sum += abs(bei - a[k]);
      bei *= j;
    }
    ans = min(sum, ans);
  }
  cout << ans << endl;
  return 0;
}
