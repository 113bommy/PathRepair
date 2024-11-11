#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  double ans = 0;
  cout << fixed;
  cout << setprecision(10);
  for (int i = 0; i <= n - 3; i++) {
    int val = upper_bound(arr + i + 1, arr + n, arr[i] + k) - arr;
    val--;
    if (val - i + 1 < 3) continue;
    ans =
        max(ans, 1 * 1.0 - (1.0 * (arr[i + 1] - arr[i])) / (arr[val] - arr[i]));
  }
  if (ans == 0)
    cout << -1;
  else
    cout << ans;
  return 0;
}
