#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[1001];
int a = 0;
int b = 0;
int d = 0;
int main() {
  memset(c, 1, sizeof(c));
  cin >> n >> m;
  string s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s;
      if (s == "11")
        a++;
      else if (s == "01" || s == "10")
        b++;
      else
        d++;
    }
  }
  string mat[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; (j <= m) && (a); j++) {
      mat[i][j] = "11";
      a--;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; (j <= m) && d; j++) {
      mat[i][j] = "00";
      d--;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mat[i][j].length() != 0) continue;
      if (c[j] == 1) {
        mat[i][j] = "10";
        c[j] = 0;
      } else {
        mat[i][j] = "01";
        c[j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
