#include <bits/stdc++.h>
using namespace std;
int data[20][20];
bool ok() {
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 6; j++)
      if (data[i][j] + data[i][j + 1] + data[i][j + 2] + data[i][j + 3] +
              data[i][j + 4] ==
          45)
        return 1;
  for (int i = 1; i <= 6; i++)
    for (int j = 1; j <= 10; j++)
      if (data[i][j] + data[i + 1][j] + data[i + 2][j] + data[i + 3][j] +
              data[i + 4][j] ==
          45)
        return 1;
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 5; j++)
      if (data[i][j] + data[i + 1][j - 1] + data[i + 2][j - 2] +
              data[i + 3][j - 3] + data[i + 4][j - 4] ==
          45)
        return 1;
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
      if (data[i][j] + data[i + 1][j + 1] + data[i + 2][j + 2] +
              data[i + 3][j + 3] + data[i + 4][j + 4] ==
          45)
        return 1;
  return 0;
}
int main() {
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++) {
      char c;
      cin >> c;
      if (c == '.') data[i][j] = 0;
      if (c == 'X') data[i][j] = 9;
      if (c == 'O') data[i][j] = 2;
    }
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
      if (data[i][j] == 0 && data[i - 1][j] + data[i][j - 1] + data[i + 1][j] +
                                     data[i][j + 1] + data[i - 1][j - 1] +
                                     data[i - 1][j + 1] + data[i + 1][j + 1] +
                                     data[i + 1][j - 1] >=
                                 9) {
        data[i][j] = 9;
        if (ok()) {
          cout << "YES" << endl;
          return 0;
        }
        data[i][j] = 0;
      }
  cout << "NO" << endl;
  return 0;
}
