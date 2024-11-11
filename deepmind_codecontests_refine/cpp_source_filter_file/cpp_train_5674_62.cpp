#include <bits/stdc++.h>
using namespace std;
long a[100][100], b[100], c[100];
int main() {
  long n, m, i, j, ma, x;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    ma = 0;
    for (j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] > ma) {
        ma = a[i][j];
        x = j;
      }
    }
    b[x]++;
  }
  ma = b[1];
  for (i = 2; i <= m; i++)
    if (b[i] > ma) ma = b[i];
  for (i = 1;; i++) {
    if (b[i] == ma) {
      cout << i;
      break;
    }
  }
}
