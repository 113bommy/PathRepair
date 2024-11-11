#include <bits/stdc++.h>
using namespace std;
bool num[256];
bool cnt[4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  char grid[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> grid[i][j];
  }
  if (n % 3 == 0) {
    bool good = true;
    char c = grid[0][0];
    if (num[c]) good = false;
    num[c] = true;
    for (int i = 0; i < n / 3 && good; i++) {
      for (int j = 0; j < m && good; j++)
        if (grid[i][j] != c) good = false;
    }
    c = grid[n / 3][0];
    if (num[c]) good = false;
    num[c] = true;
    for (int i = n / 3; i < 2 * n / 3 && good; i++) {
      for (int j = 0; j < m && good; j++)
        if (grid[i][j] != c) good = false;
    }
    c = grid[2 * n / 3][0];
    if (num[c]) good = false;
    num[c] = true;
    for (int i = 2 * n / 3; i < n && good; i++) {
      for (int j = 0; j < m && good; j++)
        if (grid[i][j] != c) good = false;
    }
    if (good) {
      cout << "YES";
      return 0;
    }
  }
  for (int i = 0; i < 256; i++) num[i] = false;
  if (m % 3 == 0) {
    bool good = true;
    char c = grid[0][0];
    if (num[c]) good = false;
    num[c] = true;
    for (int i = 0; i < m / 3 && good; i++) {
      for (int j = 0; j < n && good; j++)
        if (grid[j][i] != c) good = false;
    }
    c = grid[0][m / 3];
    if (num[c]) good = false;
    num[c] = true;
    for (int i = m / 3; i < 2 * m / 3 && good; i++) {
      for (int j = 0; j < n && good; j++)
        if (grid[j][i] != c) good = false;
    }
    c = grid[0][2 * m / 3];
    if (num[c]) good = false;
    num[c] = true;
    for (int i = 2 * m / 3; i < m && good; i++) {
      for (int j = 0; j < n && good; j++)
        if (grid[j][i] != c) good = false;
    }
    if (good) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
