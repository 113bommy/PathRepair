#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, z;
    cin >> n >> k >> z;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i <= z; i++) {
      int l = i * 2;
      int p = k - l;
      if (p < 0) break;
      int sum = 0;
      int twosum = 0;
      for (int j = 0; j < p + 1; j++) {
        sum += arr[j];
        if (j != n - 1) twosum = max(twosum, arr[j] + arr[j + 1]);
      }
      ans = max(ans, sum + twosum * i);
    }
    cout << ans << "\n";
  }
}
