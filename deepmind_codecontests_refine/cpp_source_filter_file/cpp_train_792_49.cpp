#include <bits/stdc++.h>
using namespace std;
char a[105][105];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool isExist = true;
      for (int k = 0; k < n; k++) {
        if (k == j) continue;
        if (a[i][j] == a[i][k]) isExist = false;
      }
      for (int k = 0; k < n; k++) {
        if (k == i) continue;
        if (a[i][j] == a[k][j]) isExist = false;
      }
      if (isExist) cout << a[i][j];
    }
  }
  return 0;
}
