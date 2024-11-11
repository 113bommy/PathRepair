#include <bits/stdc++.h>
using namespace std;
int n, m, tot;
int a[505][505], b[505][505], s[505];
char ch[505];
int main() {
  scanf("%d%d%d", &n, &m, &tot);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", ch + 1);
    for (int j = 1; j <= m; ++j) {
      a[i][j] = ch[j] == '1';
    }
  }
  for (int i = 2; i < n; ++i) {
    for (int j = 2; j < m; ++j) {
      b[i][j] = a[i][j] & a[i - 1][j] & a[i + 1][j] & a[i][j - 1] & a[i][j + 1];
      b[i][j] += b[i - 1][j];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 2; j <= n; ++j) {
      for (int k = 1; k <= m; ++k) {
        s[k] = b[j - 1][k - 1] - b[i][k - 1] + s[k - 1];
      }
      int r = 1, now = 0;
      for (int l = 1; l <= n; ++l) {
        for (; r <= m; ++r) {
          if (s[r] - s[l + 1] >= tot) {
            break;
          }
        }
        if (s[r] - s[l + 1] < tot) break;
        ans += m - r + 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
