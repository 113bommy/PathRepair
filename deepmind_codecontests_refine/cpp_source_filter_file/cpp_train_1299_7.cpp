#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
char field[MAXN][MAXN];
int m, n, c[MAXN], r[MAXN];
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < n; ++i) {
      scanf("%s", field[i]);
      for (int j = 0; j < m; ++j) {
        c[j] += field[i][j] == '*';
        r[i] += field[i][j] == '*';
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (field[i][j] == '*') {
          ans += (r[i] - 1) * (c[j] - 1);
        }
      }
    cout << ans << endl;
  }
  return 0;
}
