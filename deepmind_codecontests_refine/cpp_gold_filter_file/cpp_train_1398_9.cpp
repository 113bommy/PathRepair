#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
bool u[100][100];
char s1, s2, s3, s4;
int main() {
  cin >> s1 >> s2 >> s3 >> s4;
  memset(u, 0, sizeof(u));
  int x = s1 - 'a', xx = s2 - '1';
  int y = s3 - 'a', yy = s4 - '1';
  int i = 0;
  u[x][xx] = 1;
  while (i < x) {
    u[i][xx] = 1;
    i++;
  }
  i = 7;
  while (i > x) {
    u[i][xx] = 1;
    i--;
  }
  i = 0;
  while (i < xx) {
    u[x][i] = 1;
    i++;
  }
  i = 7;
  while (i > xx) {
    u[x][i] = 1;
    i--;
  }
  u[y][yy] = 1;
  if (y - 2 >= 0 && yy - 1 >= 0) u[y - 2][yy - 1] = 1;
  if (y - 2 >= 0 && yy + 1 < 8) u[y - 2][yy + 1] = 1;
  if (y - 1 >= 0 && yy - 2 >= 0) u[y - 1][yy - 2] = 1;
  if (y + 1 < 8 && yy - 2 >= 0) u[y + 1][yy - 2] = 1;
  if (y - 1 >= 0 && yy + 2 < 8) u[y - 1][yy + 2] = 1;
  if (y + 1 < 8 && yy + 2 < 8) u[y + 1][yy + 2] = 1;
  if (y + 2 < 8 && yy - 1 >= 0) u[y + 2][yy - 1] = 1;
  if (y + 2 < 8 && yy + 1 < 8) u[y + 2][yy + 1] = 1;
  int ans = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      if (u[i][j] == 0) {
        if (i - 2 == x && j - 1 == xx) continue;
        if (i - 2 == x && j + 1 == xx) continue;
        if (i - 1 == x && j - 2 == xx) continue;
        if (i + 1 == x && j - 2 == xx) continue;
        if (i - 1 == x && j + 2 == xx) continue;
        if (i + 1 == x && j + 2 == xx) continue;
        if (i + 2 == x && j - 1 == xx) continue;
        if (i + 2 == x && j + 1 == xx) continue;
        ans++;
      }
    }
  cout << ans;
  return 0;
}
