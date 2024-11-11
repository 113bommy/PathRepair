#include <bits/stdc++.h>
using namespace std;
char a[450][450];
int ur[450][450], r[450][450], l[450][450], ul[450][450], u[450][450];
void solution() {
  int n, m, ans = 0;
  cin >> n >> m;
  memset(a, 1, sizeof(a));
  memset(r, 0, sizeof(r));
  memset(ur, 0, sizeof(ur));
  memset(l, 0, sizeof(l));
  memset(ul, 0, sizeof(ul));
  memset(u, 0, sizeof(u));
  char trash;
  for (int i = 1; i <= n; i++) {
    gets(&trash);
    for (int j = 1; j <= m; j++) {
      char ch;
      scanf("%c", &ch);
      a[i][j] = ch - 48;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        if (a[i - 1][j] == 0) u[i][j] = u[i - 1][j] + 1;
        if (a[i][j - 1] == 0) {
          r[i][j] = r[i][j - 1] - 1;
          l[i][j] = l[i][j - 1] + 1;
        } else {
          int x = j;
          while (a[i][x] == 0) x++;
          r[i][j] = x - j - 1;
        }
        if (a[i - 1][j + 1] == 0) ur[i][j] = ur[i - 1][j + 1] + 1;
        if (a[i - 1][j - 1] == 0) ul[i][j] = ul[i - 1][j - 1] + 1;
      }
      int xx = 1;
      while (l[i][j] >= xx * 2 && ul[i][j] >= xx) {
        if (ur[i][j - 2 * xx] >= xx) ans++;
        xx++;
      }
      xx = 1;
      while (ur[i][j] >= xx && ul[i][j] >= xx) {
        if (r[i - xx][j - xx] >= xx * 2) ans++;
        xx++;
      }
      xx = 1;
      while (u[i][j] >= xx * 2 && ur[i][j] >= xx) {
        if (ul[i - xx][j + xx] >= xx) ans++;
        xx++;
      }
      xx = 1;
      while (u[i][j] >= xx * 2 && ul[i][j] >= xx) {
        if (ur[i - xx][j - xx] >= xx) ans++;
        xx++;
      }
      xx = 1;
      while (ul[i][j] >= xx && l[i][j] >= xx) {
        if (u[i][j - xx] >= xx) ans++;
        xx++;
      }
      xx = 1;
      while (u[i][j] >= xx && l[i][j] >= xx) {
        if (ur[i][j - xx] >= xx) ans++;
        xx++;
      }
      xx = 1;
      while (ur[i][j] >= xx && u[i][j] >= xx) {
        if (r[i - xx][j] >= xx) ans++;
        xx++;
      }
      xx = 1;
      while (u[i][j] >= xx && ul[i][j] >= xx) {
        if (r[i - xx][j - xx] >= xx) ans++;
        xx++;
      }
    }
  }
  cout << ans << '\n';
}
int main() { solution(); }
