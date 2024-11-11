#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000 + 10;
const int INF = 0x7f7f7f7f;
const double eps = 1e-8;
const double pi = 3.1415926535897932384626433832795;
int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};
int l[] = {0, 1, 1, 1, 2, 3};
int r[] = {0, 3, 4, 5, 5, 5};
int f[1 << 20];
char s[10][10];
bool solve() {
  int val = 0;
  for (int i = 1; i <= 5; i++)
    for (int j = l[i]; j <= r[i]; j++) {
      val <<= 1;
      if (s[i][j] == 'O') val ^= 1;
    }
  if (f[val]) return f[val] > 0;
  int& res = f[val] = -1;
  for (int i = 1; i <= 5 && res < 0; i++)
    for (int j = l[i]; j <= r[i] && res < 0; j++)
      if (s[i][j] == 'O')
        for (int k = 0; k < 3 && res < 0; k++) {
          int x = i, y = j;
          while (s[x][y] == 'O') {
            s[x][y] = 'X';
            x += dx[k];
            y += dy[k];
            if (!solve()) {
              res = 1;
              break;
            }
          }
          while (x != i && y != j) {
            x -= dx[k];
            y -= dy[k];
            s[x][y] = 'O';
          }
        }
  return res > 0;
}
int main() {
  for (int i = 1; i <= 5; i++)
    for (int j = l[i]; j <= r[i]; j++) scanf(" %c", &s[i][j]);
  puts(solve() ? "Karlsson" : "Lillebror");
  return 0;
}
