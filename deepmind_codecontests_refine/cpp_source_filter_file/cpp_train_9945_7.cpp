#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 10;
const int pN = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
char a[2][2], b[2][2];
bool judge() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (a[i][j] != b[i][j]) return false;
    }
  }
  return true;
}
bool Check() {
  int sx, sy;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (b[i][j] == 'X') {
        sx = i;
        sy = j;
      }
    }
  }
  if (judge()) return true;
  int nx, ny;
  for (int i = 0; i < 12; i++) {
    if (sx == 0) {
      if (sy == 0) {
        nx = 0;
        ny = 1;
      } else {
        nx = 1;
        ny = 1;
      }
    } else {
      if (sy == 0) {
        nx = ny = 0;
      } else {
        nx = 1;
        ny = 0;
      }
    }
    swap(b[sx][sy], b[nx][ny]);
    sx = nx;
    sy = ny;
    if (judge()) return true;
  }
  return false;
}
int main() {
  for (int i = 0; i < 2; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 2; i++) {
    cin >> b[i];
  }
  bool flag = Check();
  printf(flag ? "YES\n" : "NO\n");
  return 0;
}
