#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 100;
long long a[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    long long ans = -2430000000000000000;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (long long i = 0; i <= 5; i++) {
      long long res = 1;
      for (long long j = 1; j <= i; j++) res *= a[j];
      for (long long j = n; j >= n - 4 + i; j--) res *= a[j];
      if (res >= ans) ans = res;
    }
    cout << ans << endl;
  }
}
