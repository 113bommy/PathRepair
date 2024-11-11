#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[26] = {0};
  char c[305][305];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
      a[c[i][j] - 'a'] = 1;
    }
  }
  int sum = 0;
  for (int i = 0; i < 26; i++) {
    sum += a[i];
  }
  if (sum != 2) {
    cout << "NO" << endl;
    return 0;
  } else {
    char s = c[0][0];
    char o = c[0][1];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j == i || j == (n - i - 1)) {
          if (c[i][j] != s) {
            cout << "NO" << endl;
            return 0;
          }
        } else {
          if (c[i][j] != o) {
            cout << "NO" << endl;
            return 0;
          }
        }
      }
    }
    cout << "YES" << endl;
  }
}
