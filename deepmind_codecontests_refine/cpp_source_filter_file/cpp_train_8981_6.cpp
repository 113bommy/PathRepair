#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int m;
  cin >> n;
  int arr[n][m];
  int sum = 0;
  int neg = 0;
  int maxed = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] < 0) neg++;
      sum += abs(arr[i][j]);
      int c = arr[i][j];
      if (c > maxed) maxed = c;
    }
  }
  if (neg % 2 == 0) {
    cout << sum;
    return;
  }
  cout << sum - 2 * maxed;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
