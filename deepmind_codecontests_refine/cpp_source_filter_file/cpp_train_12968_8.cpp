#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int indl, indr, indu, inddl, inddr;
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != '.') {
        indu = i;
        indl = j;
        for (int k = i + 1; k < n; j++) {
          if (a[k][j] == '.') {
            inddl = k;
            break;
          }
          if (k == n - 1) {
            inddl = n;
            break;
          }
        }
        if (i == n - 1) {
          inddl = n;
        }
        for (int k = j + 1; k < m; k++) {
          if (a[i][k] == '.') {
            indr = k - 1;
            for (int s = i + 1; s < n; s++) {
              if (a[s][k - 1] == '.') {
                inddr = s;
                break;
              }
              if (s == n - 1) {
                inddr = n;
                break;
              }
            }
            if (i == n - 1) inddr = n;
            break;
          }
          if (k == m - 1) {
            indr = m - 1;
            for (int s = i + 1; s < n; s++) {
              if (a[s][k] == '.') {
                inddr = s;
                break;
              }
              if (s == n - 1) {
                inddr = n;
                break;
              }
            }
            if (i == n - 1) inddr = n;
            break;
          }
        }
        if (j == m - 1) {
          indr = m - 1;
          for (int s = i + 1; s < n; s++) {
            if (a[s][j] == '.') {
              inddr = s;
              break;
            }
            if (s == n - 1) {
              inddr = n;
              break;
            }
          }
          if (i == n - 1) inddr = n;
        }
        flag = 1;
        break;
      }
    }
    if (flag) break;
  }
  if (inddr != inddl) {
    cout << "NO" << endl;
    return 0;
  }
  vector<string> b(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i >= indu && i < inddl && j >= indl && j <= indr) {
        b[i] += 'X';
      } else
        b[i] += '.';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != b[i][j]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
