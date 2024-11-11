#include <bits/stdc++.h>
using namespace std;
long long int counting(long long int a[], long long int k, long long int n,
                       long long int m) {
  long long int ans = 0;
  for (long long int i = k + 1; i < n && a[i] - a[k] <= m; ++i) ++ans;
  return ans;
}
int32_t main() {
  long long int n, m, ans = 0;
  cin >> n >> m;
  long long int a[n];
  for (long long int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  for (long long int i = 0; i < n; ++i) ans += counting(a, i, n, m);
  cout << ans * 2 << '\n';
}
