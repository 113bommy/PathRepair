#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char c;
  int f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  x = (c & 15);
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}
int n, m, i, j, a, b, c, s[105][105], le[105][105], up[105][105];
char ans[40005];
int id(int x, int y) { return (x - 1) * (2 * m) + y; }
void dfsl(int x, int y, int z) {
  if (x < 1 || x > n || y < 1 || y > m) return;
  if (s[x][y] != 3) return;
  if (le[x][y]) return;
  le[x][y] = z;
  dfsl(x, y - 1, 3 - z);
  dfsl(x, y + 1, 3 - z);
}
void dfsu(int x, int y, int z) {
  if (x < 1 || x > n || y < 1 || y > m) return;
  if (s[x][y] != 3) return;
  if (up[x][y]) return;
  up[x][y] = z;
  dfsu(x - 1, y, 3 - z);
  dfsu(x + 1, y, 3 - z);
}
int main() {
  read(n);
  read(m);
  read(b);
  read(a);
  read(c);
  for ((i) = 1; (i) <= (n); (i)++) {
    for ((j) = 1; (j) <= (m); (j)++) {
      if (c > m) {
        s[i][j] = 3;
        c--;
      } else if (a > 0) {
        s[i][j] = 1;
        a--;
      } else if (c > 0) {
        s[i][j] = 3;
        c--;
      } else if (b > 0) {
        s[i][j] = 2;
        b--;
      }
    }
  }
  for ((i) = 1; (i) <= (n); (i)++)
    for ((j) = 1; (j) <= (m); (j)++) {
      if (s[i][j] != 3 && s[i][j - 1] == 3) {
        dfsl(i, j - 1, 3 - s[i][j]);
      }
      if (s[i][j] != 3 && s[i][j + 1] == 3) {
        dfsl(i, j + 1, s[i][j]);
      }
      if (s[i][j] != 3 && s[i - 1][j] == 3) {
        dfsu(i - 1, j, 3 - s[i][j]);
      }
      if (s[i][j] != 3 && s[i + 1][j] == 3) {
        dfsu(i + 1, j, s[i][j]);
      }
    }
  for ((i) = 1; (i) <= (n); (i)++)
    for ((j) = 1; (j) <= (m); (j)++)
      if (s[i][j] == 3) {
        if (!le[i][j]) {
          dfsl(i, j, 1);
        }
        if (!up[i][j]) {
          dfsu(i, j, 1);
        }
      }
  for ((i) = 1; (i) <= (n); (i)++) {
    for ((j) = 1; (j) <= (m); (j)++) {
      int w = id(i + i - 1, j + j - 1), x = w + 1, y = w + m + m, z = y + 1;
      if (s[i][j] == 1) {
        ans[w] = '.';
        ans[x] = '.';
        ans[y] = '.';
        ans[z] = '.';
        continue;
      }
      if (s[i][j] == 2) {
        ans[w] = '#';
        ans[x] = '#';
        ans[y] = '#';
        ans[z] = '#';
        continue;
      }
      if (le[i][j] == 1 && up[i][j] == 1) {
        ans[w] = '.';
        ans[x] = '/';
        ans[y] = '/';
        ans[z] = '#';
        continue;
      }
      if (le[i][j] == 2 && up[i][j] == 2) {
        ans[w] = '#';
        ans[x] = '/';
        ans[y] = '/';
        ans[z] = '.';
        continue;
      }
      if (le[i][j] == 1 && up[i][j] == 2) {
        ans[w] = '\\';
        ans[x] = '#';
        ans[y] = '.';
        ans[z] = '\\';
        continue;
      }
      if (le[i][j] == 2 && up[i][j] == 1) {
        ans[w] = '\\';
        ans[x] = '.';
        ans[y] = '#';
        ans[z] = '\\';
        continue;
      }
    }
  }
  for ((i) = 1; (i) <= (n + n); (i)++) {
    for ((j) = 1; (j) <= (m + m); (j)++) {
      putchar(ans[id(i, j)]);
    }
    puts("");
  }
  return 0;
}
