#include <bits/stdc++.h>
using namespace std;
const int MAXN = (50) + 5, MOD = (1e9) + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  char a[12][12];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  if (m == 1) {
    cout << "z\n";
    return;
  }
  if (n == 1) {
    for (int i = 0; i < m; i++) {
      cout << a[0][i];
    }
    cout << '\n';
    return;
  }
  bool q = true;
  int r, t, f1, f2;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int co = 0;
      int ff1, ff2;
      for (int e = 0; e < m; e++) {
        if (a[i][e] != a[j][e]) {
          co++;
          if (co == 1) {
            ff1 = e;
          }
          if (co == 2) {
            ff2 = e;
          }
        }
      }
      if (co > 2) {
        cout << "-1\n";
        return;
      }
      if (co == 2) {
        r = i;
        t = j;
        f1 = ff1;
        f2 = ff2;
        q = false;
      }
    }
  }
  if (q) {
    for (int i = 0; i < m; i++) {
      cout << a[0][i];
    }
    cout << '\n';
    return;
  }
  char rt[12], tr[12];
  rt[f1] = a[r][f1];
  tr[f1] = a[t][f1];
  rt[f2] = a[t][f2];
  tr[f2] = a[r][f2];
  for (int i = 0; i < m; i++) {
    if (i == f1 || i == f2) {
      continue;
    }
    rt[i] = a[r][i];
    tr[i] = a[r][i];
  }
  bool zzz = true;
  bool ttt = true;
  for (int j = 0; j < n; j++) {
    int coco = 0;
    for (int i = 0; i < m; i++) {
      if (rt[i] != a[j][i]) {
        coco++;
      }
    }
    if (coco > 1) {
      zzz = false;
      break;
    }
  }
  if (zzz) {
    for (int i = 0; i < m; i++) {
      cout << rt[i];
    }
    cout << '\n';
    return;
  }
  for (int j = 0; j < n; j++) {
    int coco = 0;
    for (int i = 0; i < m; i++) {
      if (tr[i] != a[j][i]) {
        coco++;
      }
    }
    if (coco > 1) {
      cout << "-1\n";
      return;
    }
  }
  for (int i = 0; i < m; i++) {
    cout << tr[i];
  }
  cout << '\n';
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
