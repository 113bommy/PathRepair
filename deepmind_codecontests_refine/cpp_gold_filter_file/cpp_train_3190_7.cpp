#include <bits/stdc++.h>
using namespace std;
char g[9][9];
int main() {
  int n, m;
  string s;
  int a = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j <= 6; j += 3) {
      cin >> s;
      g[i][j] = s[0];
      g[i][j + 1] = s[1];
      g[i][j + 2] = s[2];
    }
  }
  cin >> n >> m;
  n--;
  m--;
  int l = -1, h = -1;
  for (int i = 0; i <= 6; i += 3) {
    for (int j = 0; j <= 6; j += 3) {
      if (n >= i && n <= i + 2 && m >= j && m <= j + 2) {
        l = i;
        h = j;
        break;
      }
    }
    if (l != -1) break;
  }
  bool flag = false;
  int r = 0, k = 0;
  for (int i = l; i <= l + 2; i++) {
    k = 0;
    for (int j = h; j <= h + 2; j++) {
      if (i == n && j == m) {
        flag = true;
        break;
      }
      k += 3;
    }
    if (flag) break;
    if (r != 6) r += 3;
  }
  flag = false;
  for (int i = r; i <= r + 2; i++) {
    for (int j = k; j <= k + 2; j++) {
      if (g[i][j] == '.') {
        flag = true;
      }
    }
    if (flag) break;
  }
  if (flag) {
    for (int i = r; i <= r + 2; i++)
      for (int j = k; j <= k + 2; j++)
        if (g[i][j] == '.') g[i][j] = '!';
  } else {
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (g[i][j] == '.') g[i][j] = '!';
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << g[i][j];
      if (j == 2 || j == 5) cout << " ";
    }
    cout << ((i == 2 || i == 5) ? "\n\n" : "\n");
  }
  return 0;
}
