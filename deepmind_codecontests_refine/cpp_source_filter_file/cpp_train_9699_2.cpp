#include <bits/stdc++.h>
using namespace std;
int t[1001][1001], now[1001][1001], ans[1001][1001], n, m;
char le[1001][1001];
int main() {
  scanf("%d %d", &n, &m);
  getchar();
  for (int i = 0; i < n; i++, getchar())
    for (int j = 0; j < m; j++) le[i][j] = getchar();
  for (int i = 0; i < m; i++) {
    int co;
    for (int j = 0; j < n; j++) {
      co = 1;
      if (j != 0 && le[j][i] == le[j - 1][i]) co = t[j - 1][i] + 1;
      t[j][i] = co;
      if (co * 3 <= j + 1) {
        if (t[j - co][i] == co && t[j - co - co][i] == co) {
          now[j][i] = 1;
          if (i > 0) {
            if (le[j][i - 1] == le[j][i] &&
                le[j - co][i - 1] == le[j - co][i] &&
                le[j - co - co][i - 1] == le[j - co - co][i])
              if (t[j][i - 1] == co && t[j - co][i - 1] == co &&
                  t[j - co - co][i - 1] == co)
                now[j][i] += now[j][i - 1];
          }
        }
      }
      ans[j][i] = now[j][i];
      if (j > 0) ans[j][i] += ans[j - 1][i];
      if (i > 0) ans[j][i] += ans[j][i - 1];
      if (i > 0 && j > 0) ans[j][i] -= ans[j - 1][i - 1];
    }
  }
  cout << ans[n - 1][m - 1] << endl;
}
