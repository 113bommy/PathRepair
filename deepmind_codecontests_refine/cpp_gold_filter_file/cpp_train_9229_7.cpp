#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j;
  string s[4];
  cin >> n >> k;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < n; j++) s[i] += '.';
  }
  if (k & 1) {
    s[1][n / 2] = '#';
    k--;
  } else if (k) {
    s[2][n / 2] = '#';
    s[1][n / 2] = '#';
    k -= 2;
  }
  while (k) {
    if (k == 1) {
      s[2][n / 2] = '#';
      k--;
    } else {
      for (i = 1; i < 3; i++) {
        for (j = 1; j < n - 1; j++) {
          if (s[i][j] == '.') {
            s[i][j] = '#';
            s[i][n - j - 1] = '#';
            k -= 2;
            if (k < 2) goto aa;
          }
        }
      }
    }
  aa:;
  }
  puts("YES");
  for (i = 0; i < 4; i++) cout << s[i] << endl;
  return 0;
}
