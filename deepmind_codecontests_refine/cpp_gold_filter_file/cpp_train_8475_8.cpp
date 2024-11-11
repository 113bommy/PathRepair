#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int a, sum = 0, f = 1;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (s[i][j] == '#' && s[i - 1][j] == '#' && s[i][j - 1] == '#' &&
            s[i + 1][j] == '#' && s[i][j + 1] == '#') {
          s[i][j] = '*';
          s[i - 1][j] = '*';
          s[i][j - 1] = '*';
          s[i + 1][j] = '*';
          s[i][j + 1] = '*';
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == '#') {
          f = 0;
          break;
        }
      }
    }
    if (f == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
