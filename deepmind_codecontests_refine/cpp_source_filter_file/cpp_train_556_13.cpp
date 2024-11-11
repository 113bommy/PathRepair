#include <bits/stdc++.h>
using namespace std;
void lets_hope_its_right() {
  int arr[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> arr[i][j];
  int l1 = arr[0][1] + arr[0][2];
  int l2 = arr[1][0] + arr[1][2];
  int l3 = arr[2][0] + arr[2][1];
  int r1 = arr[1][0] + arr[2][0];
  int r2 = arr[0][1] + arr[2][1];
  int r3 = arr[0][2] + arr[1][2];
  for (int i = 1; i < 1e5; i++) {
    if (l1 + i == r1 + i) {
      arr[0][0] = i;
      int x = i + l1;
      if (x <= 0) continue;
      if (x - r2 == x - l2 && x - r3 == x - l3 && x > r2 && x > r3 &&
          (x - r2) + (x - r3) + (x - r1) == x) {
        arr[1][1] = x - r2;
        arr[2][2] = x - r3;
        break;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cout << arr[i][j] << ' ';
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  while (tt--) lets_hope_its_right();
}
