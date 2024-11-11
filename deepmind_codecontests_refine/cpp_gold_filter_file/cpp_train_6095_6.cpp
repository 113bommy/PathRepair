#include <bits/stdc++.h>
using namespace std;
const int MAX = 64;
char mat[MAX][MAX];
int n;
int cnt4;
int minx, miny, maxx, maxy;
int get4() {
  int res = 0;
  for (int i = minx; i < maxx + 1; ++i)
    for (int j = miny; j < maxy + 1; ++j) {
      if (mat[i][j] == '4') ++res;
    }
  return res;
}
bool jedan(int x, int y) {
  if (x < 0 || x > n || y < 0 || y >= n) return true;
  return mat[x][y] == '1';
}
bool dva(int x, int y) {
  if (x < 0 || x > n || y < 0 || y >= n) return true;
  return mat[x][y] == '2';
}
bool unutar(int x, int y) {
  return x >= minx && x <= maxx && y >= miny && y <= maxy;
}
bool vani() {
  ++maxx;
  ++maxy;
  --minx;
  --miny;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] != '0' && !unutar(i, j)) return true;
    }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%s", mat[i]);
  minx = miny = 1000;
  maxx = maxy = -1000;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] == '4') {
        minx = min(minx, i);
        maxx = max(maxx, i);
        miny = min(miny, j);
        maxy = max(maxy, j);
      }
    }
  if (get4() != (maxx - minx + 1) * (maxy - miny + 1)) {
    printf("No\n");
    return 0;
  }
  if (!jedan(minx - 1, miny - 1) || !jedan(minx - 1, maxy + 1) ||
      !jedan(maxx + 1, miny - 1) || !jedan(maxx + 1, maxy + 1)) {
    printf("No\n");
    return 0;
  }
  for (int i = minx; i < maxx + 1; ++i) {
    if (!dva(i, miny - 1)) {
      printf("No\n");
      return 0;
    }
    if (!dva(i, maxy + 1)) {
      printf("No\n");
      return 0;
    }
  }
  for (int i = miny; i < maxy + 1; ++i) {
    if (!dva(minx - 1, i)) {
      printf("No\n");
      return 0;
    }
    if (!dva(maxx + 1, i)) {
      printf("No\n");
      return 0;
    }
  }
  if (vani()) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
}
