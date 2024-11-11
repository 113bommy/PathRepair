#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char s[n][m];
  int a[n][m], t = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) a[i][j] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> s[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        if (k == j) continue;
        if (s[i][j] == s[i][k]) {
          a[i][k]++;
          t++;
        }
      }
      for (int k = 0; k < n; k++) {
        if (k == i) continue;
        if (s[i][j] == s[k][j]) {
          a[k][j]++;
          t++;
        }
      }
      if (t > 0) a[i][j]++;
      t = 0;
    }
  }
  string ans = "";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) cout << s[i][j];
    }
  }
}
