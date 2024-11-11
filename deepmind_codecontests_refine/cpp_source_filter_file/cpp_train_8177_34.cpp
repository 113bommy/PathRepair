#include <bits/stdc++.h>
using namespace std;
int n, m, a[2100][2];
bitset<2100 * 2> b[2100];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i][0] = x, a[i][1] = y;
    b[x][y] = 1;
  }
  for (int i = 1; i <= n; i++) b[i][i + n] = 1;
  for (int i = 1; i <= n; i++) {
    int t;
    for (int j = i; j <= n; j++)
      if (b[j][i]) {
        t = j;
        break;
      }
    if (t ^ i) swap(b[i], b[t]);
    for (int j = i + 1; j <= n; j++)
      if (b[j][i]) b[j] ^= b[i];
  }
  for (int i = n; i; i--)
    for (int j = n; j > i; j--)
      if (b[i][j]) b[i] ^= b[j];
  for (int i = 1; i <= m; i++) {
    if (b[a[i][1]][a[i][0] + n])
      puts("NO");
    else
      puts("YES");
  }
}
