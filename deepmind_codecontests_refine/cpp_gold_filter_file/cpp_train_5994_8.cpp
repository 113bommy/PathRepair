#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, i, x = 0, k, j, t = 0, n;
  char a[51][51], b[51];
  cin >> a[0];
  s = strlen(a[0]);
  for (i = 1; i < s; i++) {
    a[i][0] = a[i - 1][s - 1];
    b[0] = a[i][0];
    for (j = 1; j < s; j++) {
      a[i][j] = a[i - 1][j - 1];
      b[j] = a[i][j];
    }
    for (k = 0; k < i; k++) {
      for (j = 0; j < s; j++)
        if (a[i][j] != a[k][j]) break;
      if (j == s) {
        t = 1;
        break;
      }
    }
    if (t != 1) x++;
  }
  cout << x + 1;
  return 0;
}
