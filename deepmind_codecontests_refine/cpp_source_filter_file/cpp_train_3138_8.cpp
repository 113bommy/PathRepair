#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int n, i, j, x = 0, sum = 0;
    cin >> n;
    long long int a[n + 10];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    long long int ans = INT32_MAX, idx = -1;
    for (i = n - 1; i >= 0; i--) {
      for (j = 2; j * j <= a[i]; j++) {
        if (a[i] % j == 0) {
          x = j;
          long long int tmp = sum - a[i] - a[0] + (a[i] / x) + (a[0] * x);
          if (ans > tmp) {
            ans = tmp;
            idx = i;
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
