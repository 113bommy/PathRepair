#include <bits/stdc++.h>
using namespace std;
int rev(int ans) {
  if (ans == 1)
    return 0;
  else
    return 1;
}
int main() {
  int arr[3][3], ans[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> arr[i][j];
      ans[i][j] = 1;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (arr[i][j] % 2 != 0) {
        if (i - 1 >= 0) {
          ans[i - 1][j] = rev(ans[i - 1][j]);
        }
        if (i + 1 < 3) {
          ans[i + 1][j] = rev(ans[i + 1][j]);
        }
        if (j + 1 < 3) {
          ans[i][j + 1] = rev(ans[i][j + 1]);
        }
        if (j - 1 >= 0) {
          ans[i][j - 1] = rev(ans[i][j - 1]);
        }
        ans[i][j] = rev(ans[i][j]);
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
