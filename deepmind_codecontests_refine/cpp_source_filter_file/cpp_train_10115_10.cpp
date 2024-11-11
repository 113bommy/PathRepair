#include <bits/stdc++.h>
double const PI = 4 * atan(1);
using namespace std;
int n, m, py[511111][2], px[511111][2];
int main() {
  scanf("%d %d", &n, &m);
  char s[n + 1][m + 1];
  memset(py, 0, sizeof(py));
  memset(px, 0, sizeof(px));
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] != '.') {
        int x = (s[i][j] == '1' || s[i][j] == '4');
        int y = i % 2;
        py[j][x ^ y] = 1;
        x = (s[i][j] <= '2');
        y = j % 2;
        px[i][x ^ y] = 1;
      }
  long long kq = 1;
  for (int i = 0; i < n; i++) kq = (kq * (2 - py[i][1] - py[i][0])) % 1000003;
  for (int i = 0; i < m; i++) kq = (kq * (2 - px[i][1] - px[i][0])) % 1000003;
  printf("%lld\n", kq);
}
