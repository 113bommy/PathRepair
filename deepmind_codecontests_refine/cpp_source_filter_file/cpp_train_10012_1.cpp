#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  int tt = 1;
  while (t--) {
    int n, i, ans = 0;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    if (n >= 3 and arr[n - 2] > 1) {
      ans = min(n - 2, arr[n - 2]);
    }
    cout << ans << "\n";
  }
  return 0;
}
