#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  int cnt = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    cnt = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0)
        cnt++;
      else if (a[i][j] == 1) {
        ans += cnt;
        cnt = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cnt = 0;
    for (int j = m - 1; j >= 0; j--) {
      if (a[i][j] == 0)
        cnt++;
      else if (a[i][j] == 1) {
        ans += cnt;
        cnt = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cnt = 0;
    for (int j = 0; j < m; j++) {
      if (a[j][i] == 0)
        cnt++;
      else if (a[j][i] == 1) {
        ans += cnt;
        cnt = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cnt = 0;
    for (int j = m - 1; j >= 0; j--) {
      if (a[j][i] == 0)
        cnt++;
      else if (a[j][i] == 1) {
        ans += cnt;
        cnt = 0;
      }
    }
  }
  cout << ans;
}
