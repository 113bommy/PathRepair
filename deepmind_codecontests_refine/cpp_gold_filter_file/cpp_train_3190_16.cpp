#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  char arr[11][11];
  for (long long i = 1; i <= 9; i++) {
    for (long long j = 1; j <= 9; j++) cin >> arr[i][j];
  }
  long long x, y;
  cin >> x >> y;
  while ((x - 3) > 0) x -= 3;
  while ((y - 3) > 0) y -= 3;
  long long row = 0, column = 0;
  if (x == 1)
    row = 1;
  else if (x == 2)
    row = 4;
  else
    row = 7;
  if (y == 1)
    column = 1;
  else if (y == 2)
    column = 4;
  else
    column = 7;
  bool dotfound = false;
  for (long long a = row; a < row + 3; a++) {
    for (long long b = column; b < column + 3; b++) {
      if (arr[a][b] == '.') dotfound = true;
    }
  }
  if (dotfound) {
    for (long long a = row; a < row + 3; a++) {
      for (long long b = column; b < column + 3; b++) {
        if (arr[a][b] == '.') arr[a][b] = '!';
      }
    }
  } else {
    for (long long i = 1; i <= 9; i++) {
      for (long long j = 1; j <= 9; j++) {
        if (arr[i][j] == '.')
          cout << '!';
        else
          cout << arr[i][j];
        if (j % 3 == 0) cout << " ";
      }
      if (i % 3 == 0) cout << endl;
      cout << endl;
    }
    return 0;
  }
  for (long long i = 1; i <= 9; i++) {
    for (long long j = 1; j <= 9; j++) {
      cout << arr[i][j];
      if (j % 3 == 0) cout << " ";
    }
    if (i % 3 == 0) cout << endl;
    cout << endl;
  }
}
