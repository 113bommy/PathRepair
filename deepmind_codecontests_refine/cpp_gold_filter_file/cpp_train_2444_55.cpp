#include <bits/stdc++.h>
using namespace std;
int v[50][50];
char c[50][50];
int r, col;
int dfs(int i, int j, int p) {
  if (v[i][j] == 1) return 1;
  v[i][j] = 1;
  char ch = c[i][j];
  int f = 0;
  if (p != 4 && i < r - 1 && c[i + 1][j] == ch) f = f || dfs(i + 1, j, 1);
  if (p != 1 && i > 0 && c[i - 1][j] == ch) f = f || dfs(i - 1, j, 4);
  if (p != 2 && j > 0 && c[i][j - 1] == ch) f = f || dfs(i, j - 1, 3);
  if (p != 3 && j < col - 1 && c[i][j + 1] == ch) f = f || dfs(i, j + 1, 2);
  return f;
}
int main() {
  int i, j, k, l;
  i = 0;
  while (i < 50) {
    j = 0;
    while (j < 50) v[i][j++] = 0;
    ++i;
  }
  cin >> i >> j;
  r = i;
  col = j;
  k = 0;
  while (k < i) {
    l = 0;
    while (l < j) cin >> c[k][l++];
    ++k;
  }
  k = 0;
  while (k < i) {
    l = 0;
    while (l < j) {
      if (!v[k][l]) {
        if (dfs(k, l, 0) == 1) {
          cout << "Yes";
          return 0;
        }
      }
      ++l;
    }
    ++k;
  }
  cout << "No";
  return 0;
}
