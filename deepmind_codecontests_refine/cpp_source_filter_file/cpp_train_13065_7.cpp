#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j++) {
      cin >> a[i][j];
    }
  }
  int ctr = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j += 2) {
      ctr += (a[i][j] || a[i][j + 1]);
    }
  }
  cout << ctr << endl;
}
