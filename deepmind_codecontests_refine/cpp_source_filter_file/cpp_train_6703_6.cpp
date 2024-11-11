#include <bits/stdc++.h>
using namespace std;
const int n_max = 1001;
int dig[n_max][n_max][2], way[n_max][n_max][2], i, j, k, x = -1, n, cur;
void print(int ii, int jj) {
  if (ii == 1 && jj == 1) return;
  if (way[ii][jj][k]) {
    print(ii - 1, jj);
    cout << "D";
  } else {
    print(ii, jj - 1);
    cout << "R";
  }
}
int main() {
  cin >> n;
  for (i = 2; i <= n; i++) {
    dig[0][i][0] = dig[0][i][1] = dig[i][0][0] = dig[i][0][1] = 2147483647;
    ;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      cin >> cur;
      if (!cur) {
        x = i;
      } else {
        for (; !(cur & 1); cur >>= 1) {
          dig[i][j][0]++;
        }
        for (; !(cur % 5); cur /= 5) {
          dig[i][j][1]++;
        }
      }
      for (k = 0; k < 2; k++) {
        if (way[i][j][k] = (dig[i - 1][j][k] < dig[i][j - 1][k])) {
          dig[i][j][k] += dig[i - 1][j][k];
        } else {
          dig[i][j][k] += dig[i][j - 1][k];
        }
      }
    }
  }
  k = dig[n][n][0] > dig[n][n][1];
  if (x != -1 && dig[n][n][k] > 1) {
    cout << 1 << endl;
    for (i = 1; i < x; i++) cout << "D";
    for (i = 1; i <= n; i++) cout << "R";
    for (i = x; i < n; i++) cout << "D";
  } else {
    cout << dig[n][n][k] << endl;
    print(n, n);
  }
  return 0;
}
