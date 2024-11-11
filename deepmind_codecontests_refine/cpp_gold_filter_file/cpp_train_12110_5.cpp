#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[102][102], i, j, b[102] = {0}, x, max1 = 0, n, c = 0, m;
  string s;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> s;
    for (j = 0; j < m; j++) a[i][j] = s[j] - 48;
  }
  for (j = 0; j < m; j++) {
    max1 = 0;
    for (i = 0; i < n; i++)
      if (a[i][j] >= max1) {
        x = i;
        max1 = a[i][j];
      }
    for (i = 0; i < n; i++)
      if (a[i][j] >= max1) {
        b[i] = 1;
      }
  }
  for (i = 0; i <= 100; i++)
    if (b[i] == 1) c++;
  cout << c << endl;
  return 0;
}
