#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[5][5];
  int r, c, cnt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) {
        r = i;
        c = j;
      }
    }
  }
  if (r != 3) {
    int tmp;
    cnt += abs(r - 3);
    tmp = arr[r][c];
    arr[r][c] = arr[3][c];
    arr[3][c] = tmp;
  }
  if (c != 3) {
    int tmp;
    cnt += abs(c - 3);
    tmp = arr[r][c];
    arr[r][c] = arr[r][3];
    arr[r][3] = tmp;
  }
  cout << cnt;
  return 0;
}
