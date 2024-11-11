#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) a[i] = -a[i];
  }
  sort(a, a + n);
  long long int ans = 0;
  for (i = 0; i < n - 1; i++) {
    ans += upper_bound(a, a + n, 2 * a[i]) - a;
    ans -= i;
  }
  cout << ans;
  return 0;
}
