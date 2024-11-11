#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n][2], b[m][2];
  set<int> ps;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i][0] >> b[i][1];
  }
  bool fl = 0;
  for (int i = 0; i < n; i++) {
    bool ff[2] = {0, 0};
    for (int j = 0; j < m; j++) {
      int cc = 0, n = 0, ft = 0;
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          if (a[i][k] == b[j][l]) {
            cc++, n = a[i][k];
            ft = k;
          }
        }
      }
      if (cc == 1) {
        ps.insert(n);
        ff[ft] = 1;
      }
    }
    fl |= ff[0] & ff[1];
  }
  for (int j = 0; j < m; j++) {
    bool ff[2] = {0, 0};
    for (int i = 0; i < n; i++) {
      int cc = 0, ft = 0;
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          if (a[i][k] == b[j][l]) {
            cc++, ft = k;
          }
        }
      }
      if (cc == 1) {
        ff[ft] = 1;
      }
    }
    fl |= ff[0] & ff[1];
  }
  if (ps.size() == 1) {
    cout << *ps.begin() << "\n";
  } else if (!fl) {
    cout << "0\n";
  } else {
    cout << "-1\n";
  }
}
