#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  int num = 0;
  int mn[m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    num = 0;
    for (int j = 0; j < n; j++) {
      num = max(num, a[j][i] - '0');
    }
    mn[i] = num;
  }
  int c = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    c = 0;
    for (int j = 0; j < m; j++) {
      if (mn[i] == a[i][j] - '0') {
        c = 3;
      }
    }
    if (c == 3) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
