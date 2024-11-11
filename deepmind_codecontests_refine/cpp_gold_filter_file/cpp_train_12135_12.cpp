#include <bits/stdc++.h>
using namespace std;
int a[21][21], n, m;
bool check() {
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != j) cnt++;
    }
    if (cnt > 2) return 0;
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= n; k++) swap(a[k][i], a[k][j]);
      if (check()) {
        cout << "YES";
        return 0;
      }
      for (int k = 1; k <= n; k++) swap(a[k][i], a[k][j]);
    }
  }
  cout << "NO";
  return 0;
}
