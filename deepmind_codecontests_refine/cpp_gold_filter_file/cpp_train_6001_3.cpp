#include <bits/stdc++.h>
using namespace std;
const int kk[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
char s[(100 + 10)][(100 + 10)];
int f[(100 + 10)] = {0};
int n, m;
void getStart(int& x, int& y) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == 'S') {
        x = i, y = j;
        return;
      }
}
int b[(100 + 10)];
bool test(int a[], int xx, int yy) {
  for (int i = 1; i <= f[0]; i++) b[i] = a[f[i]];
  int x = xx, y = yy;
  for (int i = 1; i <= f[0]; i++) {
    x += kk[b[i]][0];
    y += kk[b[i]][1];
    if (x < 1 || y < 1 || x > n || y > m) return false;
    if (s[x][y] == '#') return false;
    if (s[x][y] == 'E') return true;
  }
  return false;
}
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = 1; i <= n; i++) cin >> s[i] + 1;
  while (~scanf("%1d", &f[++f[0]]))
    ;
  f[0]--;
  int x, y;
  getStart(x, y);
  int ans = 0, a[4];
  for (a[0] = 0; a[0] < 4; a[0]++) {
    for (a[1] = 0; a[1] < 4; a[1]++) {
      if (a[1] == a[0]) continue;
      for (a[2] = 0; a[2] < 4; a[2]++) {
        if (a[2] == a[0] || a[2] == a[1]) continue;
        for (a[3] = 0; a[3] < 4; a[3]++) {
          if (a[3] == a[0] || a[3] == a[1] || a[3] == a[2]) continue;
          if (test(a, x, y)) ans++;
        }
      }
    }
  }
  printf("%d", ans);
  return 0;
}
