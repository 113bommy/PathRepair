#include <bits/stdc++.h>
using namespace std;
int arr[4][4];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    int x = arr[i][0] + arr[i][2];
    if (x <= n) {
      cout << i + 1 << " " << arr[i][0] << " " << arr[i][0] + (n - x) << '\n';
      return 0;
    }
    x = arr[i][1] + arr[i][3];
    if (x <= n) {
      cout << i + 1 << " " << arr[i][1] << " " << arr[i][3] + (n - x) << '\n';
      return 0;
    }
    x = arr[i][1] + arr[i][2];
    if (x <= n) {
      cout << i + 1 << " " << arr[i][1] << " " << arr[i][2] + (n - x) << '\n';
      return 0;
    }
    x = arr[i][0] + arr[i][3];
    if (x <= n) {
      cout << i + 1 << " " << arr[i][0] << " " << arr[i][3] + (n - x) << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
