#include <bits/stdc++.h>
using namespace std;
int vis[320000], b[320000], a[800][800];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  int smax = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cnt++;
      int nm = m + 1;
      int c;
      for (int r = i; r <= n; r++) {
        if ((nm - j) * (n - i + 1) <= smax) break;
        for (c = j; c < nm; c++) {
          int p = a[r][c];
          if (vis[p] != cnt) {
            vis[p] = cnt;
            b[p] = c;
          } else {
            if (b[p] <= c) {
              nm = c;
              break;
            } else {
              if (nm > b[p]) nm = b[p];
              b[p] = c;
            }
          }
        }
        if (c == j) break;
        smax = max(smax, (r - i + 1) * (c - j));
      }
    }
  }
  cout << smax;
}
