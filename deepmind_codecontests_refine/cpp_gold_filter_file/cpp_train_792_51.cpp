#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char word[101][101];
  int x[101][101];
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      x[i][j] = 1;
      word[i][j] = s[(j - 1)];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      for (int k = (j + 1); k <= m; k++) {
        if (word[i][j] == word[i][k]) {
          x[i][j] = 0;
          x[i][k] = 0;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j < n; j++) {
      for (int k = (j + 1); k <= n; k++) {
        if (word[k][i] == word[j][i]) {
          x[j][i] = 0;
          x[k][i] = 0;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (x[i][j] == 1) cout << word[i][j];
    }
  }
}
