#include <bits/stdc++.h>
using namespace std;
int n, m;
int get_num(int i, int j) { return (i)*m + j + 1; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << "YES\n1";
    return 0;
  }
  if (n + m <= 4 || (n == 2 && m == 3) || (n == 3 && m == 2)) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  if (n == 3 && m == 3) {
    cout << "4 9 2 \n3 5 7\n8 1 6";
    return 0;
  }
  int a[4][5];
  a[0][0] = 2;
  a[0][1] = 7;
  a[0][2] = 10;
  a[0][3] = 15;
  a[0][4] = 18;
  a[1][0] = 4;
  a[1][1] = 5;
  a[1][2] = 12;
  a[1][3] = 13;
  a[1][4] = 20;
  a[2][0] = 1;
  a[2][1] = 8;
  a[2][2] = 9;
  a[2][3] = 16;
  a[2][4] = 17;
  a[3][0] = 3;
  a[3][1] = 6;
  a[3][2] = 11;
  a[3][3] = 14;
  a[3][4] = 19;
  if (m == 4 && n <= 5) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << a[j][i] << ' ';
      cout << '\n';
    }
    return 0;
  }
  if (n == 4 && m == 2) {
    cout << "2 5\n7 4\n6 1\n3 8";
    return 0;
  }
  if (n == 4 && m == 3) {
    cout << "5 3 8\n1 7 12\n6 2 4\n10 9 11";
    return 0;
  }
  if (n == 4 && m <= 5) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << a[i][j] << ' ';
      cout << '\n';
    }
    return 0;
  }
  if (n == 5 && m == 5) {
    cout << "11 2 13 4 15\n6 17 8 19 10\n21 12 23 14 25\n 16 9 18 7 20\n5 22 3 "
            "24 1";
    return 0;
  }
  if (n < m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) % 2 == 0)
          cout << get_num(i, j) << ' ';
        else
          cout << get_num(
                      i,
                      (j + 2) % m +
                          (((j == m - 1 || j == m - 3) && m % 2 == 1) ? -1
                                                                      : 0) +
                          (((j == m - 2 || j == m - 4) && m % 2 == 1) ? 1 : 0))
               << ' ';
      }
      cout << '\n';
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) % 2 == 0)
          cout << get_num(i, j) << ' ';
        else
          cout << get_num(
                      (i + 4) % n +
                          (((i == n - 1 || i == n - 3) && n % 2 == 1) ? -1
                                                                      : 0) +
                          (((i == n - 2 || i == n - 4) && n % 2 == 1) ? 1 : 0),
                      j)
               << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
