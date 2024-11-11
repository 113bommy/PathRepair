#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int field[maxn][maxn];
int n, k;
bool ok(int x, int y) {
  for (int i = 0; i < k; i++) {
    if (i + x >= n || field[i + x][y] == -1) {
      break;
    } else if (i == k - 1) {
      for (int j = 0; j < k; j++) field[j + x][y]++;
    }
  }
  for (int i = 0; i < k; i++) {
    if (y + i >= n || field[x][y + i] == -1) {
      break;
    } else if (i == k - 1) {
      for (int j = 0; j < k; j++) field[x][y + j]++;
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char c;
      scanf(" %c", &c);
      if (c == '#') {
        field[i][j] = -1;
      } else if (c == '.') {
        field[i][j] = 0;
      } else
        ;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      ok(i, j);
    }
  int maxx = 0, maxy = 0;
  int maxno = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (field[i][j] > maxno) {
        maxno = field[i][j];
        maxx = i + 1;
        maxy = j + 1;
      }
    }
  printf("%d %d", maxx, maxy);
  return 0;
}
