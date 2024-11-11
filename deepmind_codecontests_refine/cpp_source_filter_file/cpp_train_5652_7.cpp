#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897923846;
const long long int MOD = 1000000007;
const long long int N = 998244353;
long long int power(long long int x, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}
long long int modinverse(long long int a) { return power(a, MOD - 2); }
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    long long int xo = 0;
    for (long long int i = 0; i < n - 1; i++) xo = (xo ^ a[i]);
    if (a.back() - xo) {
      cout << "NO\n";
      return;
    }
  }
  n -= (1 - n % 2);
  cout << "YES\n";
  cout << n - 2 << endl;
  for (long long int i = 0; i + 2 < n; i += 2) {
    cout << i + 1 << ' ' << i + 2 << ' ' << i + 3 << endl;
  }
  for (long long int i = n - 4; i >= 0; i -= 2) {
    cout << i + 1 << ' ' << i + 2 << ' ' << i + 3 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int test = 1;
  while (test--) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
}
