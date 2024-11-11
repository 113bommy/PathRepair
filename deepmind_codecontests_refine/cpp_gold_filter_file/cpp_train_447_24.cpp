#include <bits/stdc++.h>
using namespace std;
int main() {
  int mass[101][101];
  int i, n, j, k, count;
  cin >> n;
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) cin >> mass[i][j];
  count = 0;
  int a, b, s1, s2;
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) {
      s1 = 0;
      s2 = 0;
      for (int m = 0; m < n; ++m) {
        s1 = s1 + mass[i][m] - mass[m][j];
      }
      if (s1 < 0) count++;
    }
  cout << count;
  return 0;
}
