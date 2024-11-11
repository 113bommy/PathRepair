#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  long long int a[n + 5], b[m + 5];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int i = 0; i < m; i++) {
    cin >> b[i];
  }
  if (k >= n || k >= n) {
    cout << -1;
    return 0;
  }
  sort(b, b + m);
  long long int ans = 0;
  for (long long int i = 0; i < k; i++) {
    long long int temp = lower_bound(b, b + m, a[i] + ta) - b + k - i;
    if (temp >= m) {
      cout << -1;
      return 0;
    }
    ans = max(ans, b[temp] + tb);
  }
  cout << ans;
  return 0;
}
