#include <bits/stdc++.h>
using namespace std;
int inp() {
  int a;
  scanf("%d", &a);
  return a;
}
struct pr {
  int x;
  int y;
};
int grid[2000][2000];
int dist[9][9];
int rowCount[2000][9];
int rowCount2[2000][9];
int colCount[2000][9];
int colCount2[2000][9];
list<pr> col[9];
int n, m, k, s;
int abs(int a) { return ((a < 0) ? -a : a); }
int main() {
  n = inp();
  m = inp();
  k = inp();
  s = inp();
  memset(rowCount, 0, sizeof(rowCount));
  memset(colCount, 0, sizeof(rowCount));
  memset(colCount2, 0, sizeof(rowCount));
  memset(rowCount2, 0, sizeof(rowCount));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = inp() - 1;
      grid[i][j] = x;
      rowCount[i][x]++;
      colCount[j][x]++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = grid[i][j];
      rowCount2[i][x]++;
      colCount2[j][x]++;
      if ((rowCount2[i][x] == 1 || rowCount2[i][x] == rowCount[i][x]) &&
          (colCount2[j][x] == 1 || colCount2[j][x] == colCount[j][x])) {
        pr p;
        p.x = i;
        p.y = j;
        col[x].push_back(p);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      int max = 0;
      for (list<pr>::iterator it1 = col[i].begin(); it1 != col[i].end();
           it1++) {
        for (list<pr>::iterator it2 = col[j].begin(); it2 != col[j].end();
             it2++) {
          int d = abs(it1->x - it2->x) + abs(it1->y - it2->y);
          if (d > max) {
            max = d;
          }
        }
      }
      dist[i][j] = max;
      dist[j][i] = max;
    }
  }
  int prev = inp() - 1;
  int max = 0;
  for (int i = 1; i < s; i++) {
    int nxt = inp() - 1;
    int newdist = dist[nxt][prev];
    if (newdist > max) {
      max = newdist;
    }
    prev = nxt;
  }
  printf("%d\n", max);
  return 0;
}
