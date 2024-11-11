#include <bits/stdc++.h>
using namespace std;
int n, m, sum = 0, ans = 0;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = n - 1; i >= 0; i--) {
    ans += arr[i];
    sum += 1;
    if (ans > m) {
      cout << sum << endl;
      return 0;
    }
  }
}
