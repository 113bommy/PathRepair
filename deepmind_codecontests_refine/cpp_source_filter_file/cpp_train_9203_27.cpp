#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int i, j, arr[5][5];
  cin >> n;
  for (i = 1; i <= 4; i++) {
    for (j = 1; j <= 4; j++) cin >> arr[i][j];
  }
  for (i = 1; i <= 4; i++) {
    if (arr[i][1] + arr[i][3] <= n) {
      cout << i << " " << arr[i][1] << " " << n - arr[i][3];
      return 0;
    }
    if (arr[i][1] + arr[i][4] <= n) {
      cout << i << " " << arr[i][1] << " " << n - arr[i][4];
      return 0;
    }
    if (arr[i][2] + arr[i][3] <= n) {
      cout << i << " " << arr[i][2] << " " << n - arr[i][3];
      return 0;
    }
    if (arr[i][2] + arr[i][4] <= n) {
      cout << i << " " << arr[i][2] << " " << n - arr[i][4];
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
