#include <bits/stdc++.h>
using namespace std;
int arr[200005];
pair<int, int> store[200005];
vector<pair<int, int> > v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char mat[9][9];
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) cin >> mat[i][j];
  }
  int x, y;
  cin >> x >> y;
  x--;
  y--;
  x = x % 3;
  y = y % 3;
  x = x * 3;
  y = y * 3;
  bool empty = false;
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      if (mat[x][y] == '.') {
        empty = true;
        break;
      }
    }
  }
  if (empty) {
    for (int i = x; i < x + 3; i++) {
      for (int j = y; j < y + 3; j++) {
        if (mat[i][j] == '.') {
          mat[i][j] = '!';
        }
      }
    }
  } else {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (mat[i][j] == '.') {
          mat[i][j] = '!';
        }
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    if (i % 3 == 0 && i != 0) cout << endl;
    for (int j = 0; j < 9; j++) {
      if (j % 3 == 0 && j) cout << " ";
      cout << mat[i][j];
    }
    cout << endl;
  }
  return 0;
}
