#include <bits/stdc++.h>
using namespace std;
int arr[3][3];
int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cin >> arr[i][j];
  }
  long long int sum =
      (arr[0][1] + arr[0][2] + arr[1][2] + arr[1][0] + arr[2][0] + arr[2][1]) /
      2;
  arr[0][0] = sum - (arr[0][1] + arr[0][2]);
  arr[1][1] = sum - (arr[1][0] + arr[1][2]);
  arr[2][2] = sum - (arr[2][0] + arr[2][1]);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
