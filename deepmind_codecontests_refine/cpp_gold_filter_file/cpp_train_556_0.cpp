#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> arr[i][j];
    }
  }
  int t1, t2, t3;
  t1 = arr[0][1] + arr[0][2];
  t2 = arr[1][0] + arr[1][2];
  t3 = arr[2][0] + arr[2][1];
  int xyz = (t1 + t2 + t3) / 2;
  arr[0][0] = xyz - t1;
  arr[1][1] = xyz - t2;
  arr[2][2] = xyz - t3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
