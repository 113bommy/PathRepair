#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char a[N][N];
int main() {
  int n, m, i, j, k;
  cin >> n >> m;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) cin >> a[i][j];
  string ans;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) {
      bool f = 0;
      for (k = 0; k < n && !f; ++k)
        if (k != i && a[k][j] == a[i][j]) f = 1;
      for (k = 0; k < m && !f; ++k)
        if (k != j && a[i][k] == a[i][j]) f = 1;
      if (!f) ans += a[i][j];
    }
  cout << ans << '\n';
}
