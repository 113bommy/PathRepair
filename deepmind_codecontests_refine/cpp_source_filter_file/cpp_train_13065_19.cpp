#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110][110];
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * m; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * m; j += 2) {
      if (a[i][j] == 1 || a[i][j + 1] == 1) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
