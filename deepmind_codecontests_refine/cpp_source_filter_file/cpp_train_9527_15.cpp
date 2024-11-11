#include <bits/stdc++.h>
using namespace std;
int k, n, m, x, y, p[11][11][11], answer = 0;
void dfs(int i, int j, int l) {
  if (p[i - 1][j][l] == 0) {
    p[i - 1][j][l] = 2;
    answer++;
    dfs(i - 1, j, l);
  }
  if (p[i + 1][j][l] == 0) {
    p[i + 1][j][l] = 2;
    answer++;
    dfs(i + 1, j, l);
  }
  if (p[i][j - 1][l] == 0) {
    p[i][j - 1][l] = 2;
    answer++;
    dfs(i, j - 1, l);
  }
  if (p[i][j + 1][l] == 0) {
    p[i][j + 1][l] = 2;
    answer++;
    dfs(i, j + 1, l);
  }
  if (p[i][j][l - 1] == 0) {
    p[i][j][l - 1] = 2;
    answer++;
    dfs(i, j, l - 1);
  }
  if (p[i][j][l + 1] == 0) {
    p[i][j][l + 1] = 2;
    answer++;
    dfs(i, j, l + 1);
  }
}
int main() {
  for (int i(0); i < (11); i++) {
    for (int j(0); j < (11); j++) {
      for (int l(0); l < (11); l++) {
        p[i][j][l] = 10;
      }
    }
  }
  cin >> k >> n >> m;
  for (int i(0); i < (k); i++) {
    for (int j(0); j < (n); j++) {
      string s;
      cin >> s;
      for (int l(0); l < (m); l++) {
        if (s[l] == '.') {
          p[i + 1][j + 1][l + 1] = 0;
        } else {
          p[i + 1][j + 1][l + 1] = 1;
        }
      }
    }
  }
  cin >> x >> y;
  p[1][x][y] = 2;
  answer = 1;
  dfs(1, x, y);
  cout << answer;
}
