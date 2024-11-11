#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[211][211];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0, rem = 0;
  for (int j = 1; j <= m; j++) {
    int tmp = 0, cnt = 0, seen = 0, mx = 0;
    for (int i = 1; i <= k; i++) {
      cnt += a[i][j];
    }
    for (int i = 0; i < n; i++) {
      if (i != 0) {
        cnt += -a[i][j] + a[i + k][j];
        seen += a[i][j];
      }
      if (a[i + 1][j]) {
        if (cnt > mx) {
          tmp = seen;
          mx = cnt;
        }
      }
    }
    ans += mx;
    rem += tmp;
  }
  cout << ans << " " << rem << endl;
}
