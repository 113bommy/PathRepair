#include <bits/stdc++.h>
using namespace std;
const int SIZE = 101;
char board[SIZE][SIZE] = {
    0,
};
int countOfBoard[SIZE][SIZE] = {
    0,
};
void solve(int n, int k) {
  int ans, i, j, s, a, b;
  bool flag;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - k + 1; j++) {
      if (board[i][j] == '#') continue;
      flag = true;
      for (s = 0; s < k; s++) {
        if (board[i][j + s] == '#') {
          flag = false;
          break;
        }
      }
      if (flag) {
        for (s = 0; s < k; s++) {
          countOfBoard[i][j + s]++;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - k + 1; j++) {
      if (board[j][i] == '#') continue;
      flag = true;
      for (s = 0; s < k; s++) {
        if (board[j + s][i] == '#') {
          flag = false;
          break;
        }
      }
      if (flag) {
        for (s = 0; s < k; s++) {
          countOfBoard[j + s][i]++;
        }
      }
    }
  }
  s = 0;
  a = 1;
  b = 1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (countOfBoard[i][j] > s) {
        s = countOfBoard[i][j];
        a = i + 1;
        b = j + 1;
      }
    }
  }
  printf("%d %d\n", a, b);
}
int main(int argc, char** argv) {
  int n, k, i;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%s", board[i]);
  }
  solve(n, k);
  return 0;
}
