#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l;
  int n;
  cin >> n;
  int arr[n][n];
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) cin >> arr[i][j];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (arr[i][j] == 1) continue;
      int flag = 0;
      for (k = 0; k < n; k++) {
        for (l = 0; l < n; l++) {
          if (arr[i][l] + arr[k][j] == arr[i][j]) flag = 1;
        }
      }
      if (!flag) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
