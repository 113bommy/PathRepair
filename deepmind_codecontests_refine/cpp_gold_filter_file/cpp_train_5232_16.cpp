#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 69;
const int OO = 0x3f3f3f3f;
const int mod = 1000000007;
int t, n;
int arr[3069];
int arr2[3069];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      arr2[i] = arr[i];
    }
    sort(arr2, arr2 + n);
    int ans = OO;
    for (int i = 0; i < n; i++) {
      int idx = upper_bound(arr2, arr2 + n, arr[i]) - arr2 - 1;
      int good = 0;
      for (int j = idx, k = i; j < n && k < n; k++) {
        if (arr[k] == arr2[j]) {
          good++;
          j++;
        }
      }
      ans = min(ans, n - good);
    }
    cout << ans << "\n";
  }
  return 0;
}
