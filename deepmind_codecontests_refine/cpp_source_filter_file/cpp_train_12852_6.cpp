#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, i, j, mx, ans = 0;
  cin >> n >> k;
  long long int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (i = 0; i < n; i++) swap(arr[i], arr[n - 1 - i]);
  for (i = 0; i < n; i++) {
    mx = 0;
    for (j = 0; j < k && i + j < n; j++) {
      mx = max(mx, arr[i + j]);
    }
    ans += (2 * (mx - 1));
    i += k - 1;
  }
  cout << ans << endl;
  return 0;
}
