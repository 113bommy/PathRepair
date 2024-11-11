#include <bits/stdc++.h>
using namespace std;
int n, a[1005][1005];
int main() {
  scanf("%d", &n);
  n--;
  for (register int i = 0; i < n; ++i)
    for (register int j = 0; j < n; ++j) a[i][j] = (i + j) % n + 1;
  for (register int i = 0; i < n; ++i) a[i][n] = a[n][i] = a[i][i], a[i][i] = 0;
  for (register int i = 0; i <= n; ++i) {
    for (register int j = 0; j <= n; ++j) cout << a[i][j] << ' ';
    cout << "\n";
  }
  return 0;
}
