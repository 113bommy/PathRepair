#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e5 + 10;
char ans[101][101];
int f[101][101];
int fx[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int fy[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
int n;
void balsal() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (ans[i][j] != '-') continue;
      for (char c = 'a'; c <= 'z'; c++) {
        int flag = 0;
        for (int k = 0; k < 4; k++) {
          int dx = i + fx[k];
          int dy = j + fy[k];
          if (dx >= 0 && dx < 4 && dy >= 0 && dy < n) {
            if (ans[dx][dy] == c) {
              flag = 1;
              break;
            }
          }
          dx = i + fx[k];
          dy = j + fy[k] + 1;
          if (dx >= 0 && dx < 4 && dy >= 0 && dy < n) {
            if (ans[dx][dy] == c) {
              flag = 1;
              break;
            }
          }
        }
        if (flag == 0) {
          ans[i][j] = ans[i][j + 1] = c;
          break;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  if (n == 1) {
    cout << "a\na\nb\nb\n";
    return 0;
  } else if (n == 2) {
    cout << "aa\nbb\ncc\ndd\n";
    return 0;
  }
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < n; j++) ans[i][j] = '-';
  if (n & 1) {
    ans[0][0] = ans[1][0] = 'a';
    ans[2][n - 1] = ans[3][n - 1] = 'b';
  } else {
    ans[0][0] = ans[1][0] = 'a';
    ans[0][n - 1] = ans[1][n - 1] = 'b';
  }
  balsal();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) cout << ans[i][j];
    cout << '\n';
  }
  return 0;
}
