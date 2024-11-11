#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, a[105][105];
  string s;
  cin >> n;
  cin >> s;
  for (i = 0; i < n; ++i)
    if (s[i] == '*') {
      for (j = 1; j <= i; ++j) {
        if (s[i - j] == '*') {
          a[i][j] = a[i - j][j] + 1;
          if (a[i][j] == 4) {
            cout << "yes";
            return 0;
          }
        }
      }
    }
  cout << "no";
  return 0;
}
