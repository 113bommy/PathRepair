#include <bits/stdc++.h>
using namespace std;
int n;
int arr[155][155];
int lebih1 = false;
int main() {
  memset(arr, 0, sizeof(arr));
  arr[0][0] = -1;
  arr[1][0] = 0;
  arr[1][1] = 1;
  for (int i = 2; i <= 150; i++) {
    lebih1 = false;
    for (int j = 0; j <= i - 1; j++) {
      arr[i][j + 1] = arr[i - 1][j];
    }
    for (int j = 0; j <= i; j++) {
      if (abs(arr[i][j] + arr[i - 2][j]) > 1) {
        lebih1 = true;
      }
    }
    if (!lebih1) {
      for (int j = 0; j <= i; j++) {
        arr[i][j] += arr[i - 2][j];
      }
    } else {
      for (int j = 0; j <= i; j++) {
        arr[i][j] -= arr[i - 2][j];
      }
    }
  }
  cin >> n;
  if (n == 1) {
    cout << "1\n0 1\n0\n1\n";
    return 0;
  }
  cout << n << '\n';
  for (int i = 0; i <= n; i++) {
    cout << arr[n][i] << " ";
  }
  cout << "\n";
  cout << n - 1 << '\n';
  for (int i = 0; i <= n - 1; i++) {
    cout << arr[n - 1][i] << " ";
  }
}
