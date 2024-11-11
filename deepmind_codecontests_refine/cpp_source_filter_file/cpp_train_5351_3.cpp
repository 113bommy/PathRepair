#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c;
  cin >> r >> c;
  int s = r * c;
  char ar[r][c];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> ar[i][j];
    }
  }
  int r_1 = 0, c_1 = 0;
  for (int i = 0; i < r; i++) {
    int n = 0;
    for (int j = 0; j < c; j++) {
      if (ar[i][j] == 'S')
        break;
      else
        n++;
    }
    if (n == c) r_1++;
  }
  for (int i = 0; i < c; i++) {
    int n = 0;
    for (int j = 0; j < r; j++) {
      if (ar[i][j] == 'S')
        break;
      else
        n++;
    }
    if (n == r) c_1++;
  }
  int s_1 = r_1 * c + c_1 * r - r_1 * c_1;
  cout << s_1;
}
