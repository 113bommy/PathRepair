#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  char c[n][m];
  int a[n][m];
  memset(a, 0, sizeof a);
  int sn, sm, tn, tm;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'S') {
        sn = i;
        sm = j;
      }
      if (c[i][j] == 'T') {
        tn = i;
        tm = j;
      }
    }
  }
  a[sn][sm] = 1;
  bool ans = false;
  vector<int> vn, vm;
  for (int i = sn - 1; i >= 0; i--) {
    if (c[i][sm] == '*') {
      break;
    } else {
      if (c[i][sm] == 'T') {
        ans = true;
      }
      a[i][sm] = 1;
      vn.push_back(i);
      vm.push_back(sm);
    }
  }
  for (int i = sn + 1; i < n; i++) {
    if (c[i][sm] == '*') {
      break;
    } else {
      if (c[i][sm] == 'T') {
        ans = true;
      }
      a[i][sm] = 1;
      vn.push_back(i);
      vm.push_back(sm);
    }
  }
  for (int i = sm - 1; i >= 0; i--) {
    if (c[sn][i] == '*') {
      break;
    } else {
      if (c[sn][i] == 'T') {
        ans = true;
      }
      a[sn][i] = 1;
      vn.push_back(sn);
      vm.push_back(i);
    }
  }
  for (int i = sm + 1; i < m; i++) {
    if (c[sn][i] == '*') {
      break;
    } else {
      if (c[sn][i] == 'T') {
        ans = true;
      }
      a[sn][i] = 1;
      vn.push_back(sn);
      vm.push_back(i);
    }
  }
  vector<int> xn, xm;
  for (int i = 0; i < vn.size(); i++) {
    sn = vn[i];
    sm = vm[i];
    for (int i = sn - 1; i >= 0; i--) {
      if (c[i][sm] == '*' || (a[i][sm] != 0 && a[i][sm] < 2)) {
        break;
      } else {
        if (c[i][sm] == 'T') {
          ans = true;
        }
        a[i][sm] = 2;
        xn.push_back(i);
        xm.push_back(sm);
      }
    }
    for (int i = sn + 1; i < n; i++) {
      if (c[i][sm] == '*' || (a[i][sm] != 0 && a[i][sm] < 2)) {
        break;
      } else {
        if (c[i][sm] == 'T') {
          ans = true;
        }
        a[i][sm] = 2;
        xn.push_back(i);
        xm.push_back(sm);
      }
    }
    for (int i = sm - 1; i >= 0; i--) {
      if (c[sn][i] == '*' || (a[sn][i] != 0 && a[sn][i] < 2)) {
        break;
      } else {
        if (c[sn][i] == 'T') {
          ans = true;
        }
        a[sn][i] = 2;
        xn.push_back(sn);
        xm.push_back(i);
      }
    }
    for (int i = sm + 1; i < m; i++) {
      if (c[sn][i] == '*' || (a[sn][i] != 0 && a[sn][i] < 2)) {
        break;
      } else {
        if (c[sn][i] == 'T') {
          ans = true;
        }
        a[sn][i] = 2;
        xn.push_back(sn);
        xm.push_back(i);
      }
    }
  }
  for (int i = 0; i < xn.size(); i++) {
    sn = xn[i];
    sm = xm[i];
    for (int i = sn - 1; i >= 0; i--) {
      if (c[i][sm] == '*' || (a[i][sm] != 0 && a[i][sm] < 3)) {
        break;
      } else {
        if (c[i][sm] == 'T') {
          ans = true;
        }
        a[i][sm] = 3;
      }
    }
    for (int i = sn + 1; i < n; i++) {
      if (c[i][sm] == '*' || (a[i][sm] != 0 && a[i][sm] < 3)) {
        break;
      } else {
        if (c[i][sm] == 'T') {
          ans = true;
        }
        a[i][sm] = 3;
      }
    }
    for (int i = sm - 1; i >= 0; i--) {
      if (c[sn][i] == '*' || (a[sn][i] != 0 && a[sn][i] < 3)) {
        break;
      } else {
        if (c[sn][i] == 'T') {
          ans = true;
        }
        a[sn][i] = 3;
      }
    }
    for (int i = sm + 1; i < m; i++) {
      if (c[sn][i] == '*' || (a[sn][i] != 0 && a[sn][i] < 3)) {
        break;
      } else {
        if (c[sn][i] == 'T') {
          ans = true;
        }
        a[sn][i] = 3;
      }
    }
  }
  if (ans) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
