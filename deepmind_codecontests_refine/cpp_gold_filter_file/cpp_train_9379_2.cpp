#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(4));
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
  }
  vector<vector<int>> arr_l(n, vector<int>(4));
  vector<vector<int>> arr_r(n, vector<int>(4));
  arr_l[0] = arr[0];
  for (int i = 1; i < n; i++) {
    arr_l[i][0] = max(arr_l[i - 1][0], arr[i][0]);
    arr_l[i][1] = max(arr_l[i - 1][1], arr[i][1]);
    arr_l[i][2] = min(arr_l[i - 1][2], arr[i][2]);
    arr_l[i][3] = min(arr_l[i - 1][3], arr[i][3]);
  }
  arr_r[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    arr_r[i][0] = max(arr_r[i + 1][0], arr[i][0]);
    arr_r[i][1] = max(arr_r[i + 1][1], arr[i][1]);
    arr_r[i][2] = min(arr_r[i + 1][2], arr[i][2]);
    arr_r[i][3] = min(arr_r[i + 1][3], arr[i][3]);
  }
  int a1, b1, a2, b2;
  for (int i = 0; i < n - 2; i++) {
    a1 = max(arr_l[i][0], arr_r[i + 2][0]);
    b1 = max(arr_l[i][1], arr_r[i + 2][1]);
    a2 = min(arr_l[i][2], arr_r[i + 2][2]);
    b2 = min(arr_l[i][3], arr_r[i + 2][3]);
    if (a1 <= a2 && b1 <= b2) {
      cout << a1 << " " << b1 << endl;
      return 0;
    }
  }
  if (arr_l[n - 2][0] <= arr_l[n - 2][2] &&
      arr_l[n - 2][1] <= arr_l[n - 2][3]) {
    cout << arr_l[n - 2][0] << " " << arr_l[n - 2][1] << endl;
    return 0;
  }
  if (arr_r[1][0] <= arr_r[1][2] && arr_r[1][1] <= arr_r[1][3]) {
    cout << arr_r[1][0] << " " << arr_r[1][1] << endl;
    return 0;
  }
  return 0;
}
