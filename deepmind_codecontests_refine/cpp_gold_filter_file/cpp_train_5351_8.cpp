#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100][100];
  int r, c, c1, c2, sum;
  cin >> r >> c;
  c1 = r;
  c2 = c;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) cin >> a[i][j];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j] == 'S') {
        c1--;
        break;
      }
    }
  }
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      if (a[j][i] == 'S') {
        c2--;
        break;
      }
    }
  }
  sum = (c2 * r + c1 * c) - c1 * c2;
  cout << sum << endl;
  return 0;
}
