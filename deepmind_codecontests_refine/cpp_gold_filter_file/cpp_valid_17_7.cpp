#include <bits/stdc++.h>
using namespace std;
int a[50012][7];
int main() {
  int t, n, i, j, f;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++)
      for (j = 1; j <= 5; j++) cin >> a[i][j];
    int x = 0;
    for (i = 1; i < n; i++) {
      f = 0;
      for (j = 1; j <= 5; j++)
        if (a[i][j] < a[x][j]) f++;
      if (f >= 3) x = i;
    }
    int g = 0;
    for (i = 0; i < n; i++) {
      f = 0;
      for (j = 1; j <= 5; j++)
        if (a[i][j] > a[x][j]) f++;
      if (f >= 3) g++;
    }
    if (g == n - 1)
      cout << x + 1 << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
