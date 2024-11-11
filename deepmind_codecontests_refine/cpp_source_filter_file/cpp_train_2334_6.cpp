#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  char a[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a[i][j];
    }
  }
  int arr[9] = {0};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i][j] >= '1' && a[i][j] <= '9') {
        arr[a[i][j] - '0']++;
      }
    }
  }
  bool check = true;
  for (int i = 0; i < 9; i++) {
    if (arr[i] > 2 * k) {
      check = false;
      break;
    }
  }
  if (check) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
