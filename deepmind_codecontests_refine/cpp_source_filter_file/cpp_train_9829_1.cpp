#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[50][50], x, y, k = 0;
  cin >> y >> x;
  ;
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) {
        if (i == 0 && j > 0 && j < x - 1 || j == 0 && i > 0 && i < x - 1 ||
            j == x - 1 && i > 0 && i < x - 1 ||
            i == x - 1 && j > 0 && j < x - 1)
          k++;
      }
    }
  }
  if (k == 0)
    cout << 4;
  else
    cout << 2;
  return 0;
}
