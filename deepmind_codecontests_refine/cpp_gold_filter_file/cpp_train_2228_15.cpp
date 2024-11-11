#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, mx, mn, ans = INT_MAX;
  cin >> n >> m;
  long long a[m];
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a, a + m);
  for (long long i = 0; i <= m - n; i++) {
    mx = a[i + n - 1];
    mn = a[i];
    ans = min(mx - mn, ans);
  }
  cout << ans << '\n';
  return 0;
}
