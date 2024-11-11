#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, u, n, a[100][100], s1, s2, k = 0;
  cin >> n;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) cin >> a[i][j];
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      s1 = 0;
      s2 = 0;
      for (u = 0; u < n; u++) {
        s1 += a[i][u];
        s2 += a[u][j];
      }
      if (s1 < s2) k++;
    }
  cout << k;
}
