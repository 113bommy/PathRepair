#include <bits/stdc++.h>
using namespace std;
char a[103][103];
int n;
int main() {
  cin >> n;
  int i, m, j;
  m = n / 2;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) a[i][j] = '*';
  }
  for (i = 1; i <= m; i++)
    for (j = m + 1 - (i - 1); j <= m + 1 + (i - 1); j++)
      a[i][j] = a[n - i + 1][j] = 'D';
  for (i = 1; i <= n; i++) a[m + 1][i] = 'D';
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) cout << a[i][j];
    cout << "\n";
  }
  return 0;
}
