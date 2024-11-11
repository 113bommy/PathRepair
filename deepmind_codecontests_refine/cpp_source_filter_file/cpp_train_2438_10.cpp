#include <bits/stdc++.h>
using namespace std;
int a[107][107];
int temp[107];
int main() {
  int n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m;
    a[i][0] = m;
    temp[i] = m;
    for (int j = 1; j <= m; j++) {
      int t;
      cin >> t;
      a[i][t]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] != 0) {
        for (int k = 1; k <= n; k++) {
          if (a[k][j] != 0) temp[k]--;
        }
      }
    }
    bool f = true;
    for (int I = 1; I <= n; I++) {
      if (temp[I] == 0 && (I != i)) {
        f = false;
        break;
      }
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    for (int I = 1; I <= n; I++) {
      temp[I] = a[I][0];
    }
  }
  return 0;
}
