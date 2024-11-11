#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[2][n];
    int sum[2][n];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
        if (j == 0)
          sum[i][j] = arr[i][j];
        else
          sum[i][j] = sum[i][j - 1] + arr[i][j];
      }
    }
    int move1 = sum[0][n - 1];
    int move2 = sum[1][n - 1];
    int ans = max(move1 - arr[0][1], move2 - arr[1][n - 1]);
    for (int i = 1; i < n; i++) {
      int temp1 = move1 - sum[0][i];
      int temp2 = sum[1][i - 1];
      ans = min(ans, max(temp1, temp2));
    }
    cout << ans << endl;
  }
}
