#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long double PI = 3.141592653589793;
const long long maxn = 100005;
long long x, y, z, n, k;
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n - i; j++) {
      cout << '(';
    }
    for (long long k = 1; k <= i; k++) {
      cout << "()";
    }
    for (long long j = 1; j <= n - i; j++) {
      cout << ')';
    }
    cout << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(15) << fixed;
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
