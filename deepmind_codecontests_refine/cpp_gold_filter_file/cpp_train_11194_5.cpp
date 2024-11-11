#include <bits/stdc++.h>
using namespace std;
const int maxn = 120;
int ans[maxn][maxn];
int main() {
  int n, a, b, o = 1, e = 2;
  cin >> n >> a >> b;
  bool c = true;
  for (int r = 0; r < 2; r++) {
    e = 2;
    o = 1;
    for (int i = 1; i <= a; i++)
      for (int j = 1; j <= b; j++) ans[i][j] = 0;
    for (int i = 1; i <= a; i++)
      for (int j = 1; j <= b; j++)
        if ((i + j) % 2 == r && e <= n) {
          ans[i][j] = e;
          e += 2;
        } else if ((i + j) % 2 == 1 - r && o <= n) {
          ans[i][j] = o;
          o += 2;
        }
    if (n == 1 && ans[1][1] == 0) c = 1;
    if (o <= n || e <= n)
      c = 1;
    else {
      c = 0;
      break;
    }
  }
  if (c)
    cout << -1;
  else
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) cout << ans[i][j] << " ";
      cout << endl;
    }
  return 0;
}
