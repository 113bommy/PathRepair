#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int b[200][200];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      bool f = true;
      for (int pp = 1; pp <= m; pp++) {
        if (a[i][pp] != 1) {
          f = false;
        }
      }
      for (int pp = 1; pp <= n; pp++) {
        if (a[pp][j] != 1) {
          f = false;
        }
      }
      if (f) {
        b[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      bool f = false;
      for (int pp = 1; pp <= m; pp++) {
        if (b[i][pp] == 1) {
          f = true;
        }
      }
      for (int pp = 1; pp <= n; pp++) {
        if (b[pp][j] == 1) {
          f = true;
        }
      }
      if (f) {
        if (!a[i][j]) {
          cout << "NO" << endl;
          return 0;
        }
      } else {
        if (a[i][j]) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << b[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
