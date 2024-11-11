#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
int n, m;
char mp[N][N];
typedef struct point {
  int i, j;
  inline void put(const int& ii, const int& jj) { i = ii, j = jj; }
};
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
int d[4][N][N];
bool safe[30];
point dir[100005];
int k;
void Init() {
  int i, j;
  memset(d, 0, sizeof(d));
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (mp[i][j] == '#') {
        d[2][i][j] = d[3][i][j] = 0;
      } else {
        d[0][i + 1][j] = d[0][i][j] + 1;
        d[1][i][j + 1] = d[1][i][j] + 1;
      }
    }
  }
  for (i = n - 1; i >= 0; --i) {
    for (j = m - 1; j >= 0; --j) {
      if (mp[i][j] == '#') {
        d[0][i][j] = d[1][i][j] = 0;
      } else {
        d[2][i - 1][j] = d[2][i][j] + 1;
        d[3][i][j - 1] = d[3][i][j] + 1;
      }
    }
  }
}
bool bfs(int ii, int jj) {
  point pt;
  pt.put(ii, jj);
  int i;
  for (i = 0; i < k; ++i) {
    if (d[dir[i].i][pt.i][pt.j] < dir[i].j) {
      return false;
    } else {
      pt.i += dir[i].j * di[dir[i].i];
      pt.j += dir[i].j * dj[dir[i].i];
    }
  }
  return true;
}
int main() {
  int i, j;
  char ss[6];
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; ++i) scanf("%s", mp[i]);
  scanf("%d", &k);
  for (i = 0; i < k; ++i) {
    scanf(" %s %d", ss, &dir[i].j);
    if (ss[0] == 'N') {
      dir[i].i = 0;
    } else if (ss[0] == 'W') {
      dir[i].i = 1;
    } else if (ss[0] == 'S') {
      dir[i].i = 2;
    } else if (ss[0] == 'E') {
      dir[i].i = 3;
    }
  }
  Init();
  memset(safe, false, sizeof(safe));
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (mp[i][j] >= 'A' && mp[i][j] <= 'Z' && !safe[mp[i][j] - 'A']) {
        safe[mp[i][j] - 'A'] = bfs(i, j);
      }
    }
  }
  bool flag = false;
  for (i = 0; i < 27; ++i) {
    if (safe[i]) {
      printf("%c", i + 'A');
      flag = true;
    }
  }
  if (flag) {
    puts("");
  } else {
    puts("no solution");
  }
  return 0;
}
