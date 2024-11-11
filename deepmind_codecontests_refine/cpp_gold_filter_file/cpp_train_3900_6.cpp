#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long int arr[n][n], x[2 * n + 1], y[2 * n + 1];
  long long int sum[2], pt[2][2];
  for (int i = 0; i <= 2 * n; i++) {
    x[i] = y[i] = 0;
  }
  sum[0] = sum[1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      x[i + j] += arr[i][j];
      y[i - j + n] += arr[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      long long int t = (i + j) & 1;
      long long int cur = x[i + j] + y[i - j + n] - arr[i][j];
      if (cur >= sum[t]) {
        pt[t][0] = i + 1;
        pt[t][1] = j + 1;
        sum[t] = cur;
      }
    }
  }
  cout << sum[0] + sum[1] << '\n';
  cout << pt[0][0] << " " << pt[0][1] << " " << pt[1][0] << " " << pt[1][1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
