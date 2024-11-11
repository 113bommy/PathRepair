#include <bits/stdc++.h>
using namespace std;
int Map[20][20];
int main() {
  int r, c, n, k;
  scanf("%d%d%d%d", &r, &c, &n, &k);
  for (int i = (1), _ed = (n); i <= _ed; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    Map[x][y] = 1;
  }
  int sum, ans = 0;
  for (int i1 = (1), _ed = (r); i1 <= _ed; i1++) {
    for (int j1 = (1), _ed = (c); j1 <= _ed; j1++) {
      for (int i2 = (i1), _ed = (r); i2 <= _ed; i2++) {
        for (int j2 = (j1), _ed = (c); j2 <= _ed; j2++) {
          sum = 0;
          for (int i = (i1), _ed = (i2); i <= _ed; i++) {
            for (int j = (j1), _ed = (j2); j <= _ed; j++) {
              sum += Map[i][j];
            }
          }
          if (sum >= k) ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
