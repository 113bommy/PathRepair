#include <bits/stdc++.h>
using namespace std;
char s[15][15];
int main() {
  int r, c, n, k, i, ans = 0, cnt, a, b;
  cin >> r >> c >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> a >> b;
    s[a][b] = '#';
  }
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= r; j++)
      for (int k1 = 1; k1 <= c; k1++)
        for (int k2 = 1; k2 <= c; k2++) {
          cnt = 0;
          for (int r1 = i; r1 <= j; r1++)
            for (int r2 = k1; r2 <= k2; r2++)
              if (s[r1][r2] == '#') cnt++;
          if (cnt >= k) ans++;
        }
  cout << ans << endl;
  return 0;
}
