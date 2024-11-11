#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, i, j;
  cin >> n;
  string s[n];
  for (i = 0; i < 2; i++) {
    if (i % 2 == 0) {
      for (j == 0; j < n; j++) {
        if (j % 2 == 0) {
          s[i] = s[i] + 'W';
        } else {
          s[i] = s[i] + 'B';
        }
      }
    } else {
      for (j = 0; j < n; j++) {
        if (j % 2 == 0) {
          s[i] = s[i] + 'B';
        } else {
          s[i] = s[i] + 'W';
        }
      }
    }
  }
  for (i = 2; i < n; i++) {
    if (i % 2 == 0)
      s[i] = s[0];
    else
      s[i] = s[1];
  }
  for (i = 0; i < n; i++) {
    cout << s[i] << endl;
  }
  return 0;
}
