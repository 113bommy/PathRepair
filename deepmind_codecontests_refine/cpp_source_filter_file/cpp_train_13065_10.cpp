#include <bits/stdc++.h>
using namespace std;
int ar[10000];
int main() {
  int n, m, i, j, x = 0;
  cin >> n >> m;
  char a[n][2 * m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < 2 * m; j++) cin >> a[i][j];
  }
  for (i = 0; i < n; i++) {
    for (j = 1; j < 2 * m; j = j + 2) {
      if (a[i][j] == '1' || a[i][j + 1] == '1') x++;
    }
  }
  cout << x << endl;
}
