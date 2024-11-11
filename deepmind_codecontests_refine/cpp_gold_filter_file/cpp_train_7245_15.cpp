#include <bits/stdc++.h>
using namespace std;
char mat[50][50];
int work(int i, int j, int ii, int jj, int x, int dot) {
  if (mat[i][j] == '#') {
    return 0;
  }
  if (mat[i][j] == 'O') {
    return 0;
  }
  if (mat[i][j] == 'X') {
    x++;
  } else {
    dot++;
  }
  if (x == 5 || (x == 4 && dot == 1)) {
    return 1;
  }
  return work(i + ii, j + jj, ii, jj, x, dot);
}
int main() {
  memset(mat, '#', sizeof mat);
  for (int i = 10; i < (20); i++) {
    for (int j = 10; j < (20); j++) {
      cin >> mat[i][j];
    }
  }
  bool ok = 0;
  for (int i = 10; i < (20); i++) {
    for (int j = 10; j < (20); j++) {
      ok |= work(i, j, 0, 1, 0, 0);
      ok |= work(i, j, 1, 1, 0, 0);
      ok |= work(i, j, 1, 0, 0, 0);
      ok |= work(i, j, 1, -1, 0, 0);
    }
  }
  if (ok) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}
