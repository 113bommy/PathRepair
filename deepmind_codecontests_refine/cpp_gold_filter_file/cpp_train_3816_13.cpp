#include <bits/stdc++.h>
using namespace std;
int main() {
  int R, C;
  cin >> R >> C;
  char arr[R][C];
  bool possible = true;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) cin >> arr[i][j];
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      if (arr[i][j] == '.') arr[i][j] = 'D';
      if (arr[i][j] == 'S' &&
          ((i > 0 && arr[i - 1][j] == 'W') || (j > 0 && arr[i][j - 1] == 'W') ||
           (i < R - 1 && arr[i + 1][j] == 'W') ||
           (j < C - 1 && arr[i][j + 1] == 'W')))
        possible = false;
    }
  if (possible) {
    cout << "YES" << endl;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) cout << arr[i][j];
      cout << endl;
    }
  } else
    cout << "NO" << endl;
}
