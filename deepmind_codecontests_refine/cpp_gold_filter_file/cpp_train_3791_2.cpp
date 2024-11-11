#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<long long> a(n + 1);
  vector<long long> b(n + 1);
  vector<long long> a2(n + 1);
  vector<vector<long long> > f(m + 1);
  for (int i = 1; i < m + 1; i++) {
    f[i].resize(5);
  }
  for (int i = 1; i < n + 1; i++) {
    a[i] = 1000000000;
  }
  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < 5; j++) {
      cin >> f[i][j];
    }
    if (f[i][1] == 1) {
      for (int k = f[i][2]; k <= f[i][3]; k++) {
        a2[k] = a2[k] + f[i][4];
      }
    } else {
      if (f[i][1] == 2) {
        for (int k = f[i][2]; k <= f[i][3]; k++) {
          if (a[k] > (f[i][4] - a2[k])) {
            a[k] = f[i][4] - a2[k];
          }
        }
      }
    }
  }
  for (int i = 1; i < n + 1; i++) {
    b[i] = a[i];
  }
  int g;
  for (int i = 1; i < m + 1; i++) {
    if (f[i][1] == 1) {
      for (int k = f[i][2]; k <= f[i][3]; k++) {
        b[k] = b[k] + f[i][4];
      }
    } else {
      if (f[i][1] == 2) {
        g = 0;
        for (int k = f[i][2]; k <= f[i][3]; k++) {
          if (b[k] == f[i][4]) {
            g = 1;
          }
        }
        if (g == 0) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i < n + 1; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
