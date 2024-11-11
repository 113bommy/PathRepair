#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    char a[n][m];
    bool ok = 1, zero = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'A') {
          ok = 0;
        } else {
          zero = 0;
        }
      }
    }
    if (zero) {
      cout << "0\n";
      continue;
    }
    if (ok) {
      cout << "MORTAL\n";
      continue;
    }
    bool one = 1, two = 0, three = 0;
    for (int i = 0; i < n; i++) {
      if (a[i][0] == 'P') {
        one = 0;
      } else {
        three = 1;
      }
    }
    if (one) {
      cout << "1\n";
      continue;
    }
    one = 1;
    for (int i = 0; i < m; i++) {
      if (a[0][i] == 'P') {
        one = 0;
      } else {
        three = 1;
      }
    }
    if (one) {
      cout << "1\n";
      continue;
    }
    one = 1;
    for (int i = 0; i < m; i++) {
      if (a[n - 1][i] == 'P') {
        one = 0;
      } else {
        three = 1;
      }
    }
    if (one) {
      cout << "1\n";
      continue;
    }
    one = 1;
    for (int i = 0; i < n; i++) {
      if (a[i][m - 1] == 'P') {
        one = 0;
      } else {
        three = 1;
      }
    }
    if (one) {
      cout << "1\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      long long cnt = 0;
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'A') {
          cnt++;
        }
      }
      if (cnt == m) {
        two = 1;
        break;
      }
    }
    for (int i = 0; i < m; i++) {
      long long cnt = 0;
      for (int j = 0; j < n; j++) {
        if (a[j][i] == 'A') {
          cnt++;
        }
      }
      if (cnt == n) {
        two = 1;
        break;
      }
    }
    if (two == 1 || a[0][0] == 'A' || a[0][m - 1] == 'A' ||
        a[n - 1][0] == 'A' || a[n - 1][m - 1] == 'A') {
      cout << "2\n";
      continue;
    }
    if (three == 1) {
      cout << "3\n";
    } else {
      cout << "4\n";
    }
  }
}
