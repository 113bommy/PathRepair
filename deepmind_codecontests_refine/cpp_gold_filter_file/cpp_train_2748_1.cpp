#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[1024][1024];
bool row[1024], col[1024];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (m); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    a[x][y] = 1;
  }
  for (int i = 0; i < (n); i++) {
    row[i] = col[i] = true;
    for (int j = 0; j < (n); j++) row[i] &= !a[i][j], col[i] &= !a[j][i];
  }
  int ans = 0;
  for (int i = 0; i < (n / 2); i++)
    if (i) {
      int a1 = row[i], a2 = col[i], a3 = row[n - i - 1], a4 = col[n - i - 1];
      ans += a1 + a2 + a3 + a4;
    }
  if (n & 1) {
    if (row[n / 2] || col[n / 2]) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
