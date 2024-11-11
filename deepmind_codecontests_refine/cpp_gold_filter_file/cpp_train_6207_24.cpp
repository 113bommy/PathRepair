#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-6;
inline int bit(int k) { return 1 << k; }
int a[110][110];
int b[110][110];
int to[1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  memset(b, -1, sizeof(b));
  memset(to, -1, sizeof(to));
  int cnt = 0;
  int n;
  cin >> n;
  if (n & 1) {
    for (int i = 0; i + 1 < n; i += 2) {
      a[i][0] = a[i + 1][0] = cnt++;
      a[i][1] = a[i + 1][1] = cnt++;
    }
    a[n - 1][0] = a[n - 1][1] = cnt++;
    a[0][2] = a[0][3] = cnt++;
    for (int i = 1; i + 1 < n; i += 2) {
      a[i][2] = a[i + 1][2] = cnt++;
      a[i][3] = a[i + 1][3] = cnt++;
    }
  } else {
    for (int i = 0; i + 1 < n; i += 2) {
      a[i][0] = a[i + 1][0] = cnt++;
      a[i][1] = a[i + 1][1] = cnt++;
    }
    a[0][2] = a[0][3] = cnt++;
    a[n - 1][2] = a[n - 1][3] = cnt++;
    for (int i = 1; i + 1 < n - 1; i += 2) {
      a[i][2] = a[i + 1][2] = cnt++;
      a[i][3] = a[i + 1][3] = cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      if (to[a[i][j]] >= 0) {
        b[i][j] = to[a[i][j]];
        continue;
      }
      int ax, ay;
      for (int d = 0; d < 4; d++) {
        ax = j + dx[d];
        ay = i + dy[d];
        if (ax < 0 || ay < 0 || ax >= 4 || ay >= n) continue;
        if (a[ay][ax] == a[i][j]) {
          break;
        }
      }
      int zz = 0;
      for (; zz < 25;) {
        bool good = true;
        for (int d = 0; d < 4; d++) {
          int zx = j + dx[d];
          int zy = i + dy[d];
          if (zx < 0 || zy < 0 || zx >= 4 || zy >= n) continue;
          int q = a[zy][zx];
          if (to[q] < 0) continue;
          if (to[q] == zz) {
            good = false;
            break;
          }
        }
        for (int d = 0; d < 4; d++) {
          int zx = ax + dx[d];
          int zy = ay + dy[d];
          if (zx < 0 || zy < 0 || zx >= 4 || zy >= n) continue;
          int q = a[zy][zx];
          if (to[q] < 0) continue;
          if (to[q] == zz) {
            good = false;
            break;
          }
        }
        if (good) break;
        zz++;
      }
      to[a[i][j]] = zz;
      b[i][j] = zz;
    }
  }
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < n; i++) {
      printf("%c", char('a' + b[i][j]));
    }
    puts("");
  }
  return 0;
}
