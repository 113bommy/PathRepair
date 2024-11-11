#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int h[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      h[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = i, l = j + 1; l < m; l++) {
        if (s[i][j] == s[k][l]) {
          h[i][j] = 1;
          h[k][l] = 1;
        }
      }
      for (int k = i + 1, l = j; k < n; k++) {
        if (s[i][j] == s[k][l]) {
          h[i][j] = 1;
          h[k][l] = 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (h[i][j] != 1) cout << s[i][j];
    }
  }
}
