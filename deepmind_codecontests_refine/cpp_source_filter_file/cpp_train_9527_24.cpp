#include <bits/stdc++.h>
using namespace std;
bool cr[10000];
int pr[10000], prc;
struct point {
  int x;
  int y;
  int z;
};
void criba() {
  prc = 0;
  for (int i = 0; i < 10000; i++) cr[i] = false;
  cr[0] = true;
  cr[1] = true;
  pr[prc++] = 2;
  pr[prc++] = 3;
  for (int i = 4; i < 10000; i += 2) cr[i] = true;
  for (int i = 9; i < 10000; i += 6) cr[i] = true;
  for (int i = 6; i < 10000; i += 6) {
    if (!cr[i - 1]) {
      pr[prc++] = i - 1;
      for (int j = (i - 1) * (i - 1); j < 10000; j += 2 * (i - 1)) cr[j] = true;
    }
    if (!cr[i + 1]) {
      pr[prc++] = i + 1;
      for (int j = (i + 1) * (i + 1); j < 10000; j += 2 * (i + 1)) cr[j] = true;
    }
  }
}
bool vm(int x, int y, int z, int k, int m, int n) {
  return (x >= 0 && x < k) && (y >= 0 && y < m) && (z >= 0 && z < n);
}
int main() {
  int k, n, m, x, y;
  bool g[11][11][11];
  char t[11];
  scanf("%d%d%d", &k, &n, &m);
  for (int i = 0; i < k; i += 1)
    for (int j = 0; j < n; j += 1)
      for (int l = 0; l < m; l += 1) g[i][j][l] = true;
  for (int i = 0; i < k; i += 1) {
    for (int j = 0; j < n; j += 1) {
      scanf("%s", &t);
      for (int l = 0; l < m; l += 1) g[i][j][l] = (t[l] == '.');
    }
  }
  int mx[6] = {1, -1, 0, 0, 0, 0};
  int my[6] = {0, 0, 1, -1, 0, 0};
  int mz[6] = {0, 0, 0, 0, 1, -1};
  scanf("%d%d", &x, &y);
  x--;
  y--;
  point in;
  int r = 0;
  in.x = 0;
  in.y = x;
  in.z = y;
  queue<point> q;
  q.push(in);
  g[in.x][in.y][in.z] = false;
  while (!q.empty()) {
    r++;
    in = q.front();
    q.pop();
    for (int i = 0; i < 6; i += 1) {
      if (vm(in.x + mx[i], in.y + my[i], in.z + mz[i], k, m, n) &&
          g[in.x + mx[i]][in.y + my[i]][in.z + mz[i]]) {
        point tmp;
        tmp.x = in.x + mx[i];
        tmp.y = in.y + my[i];
        tmp.z = in.z + mz[i];
        g[in.x + mx[i]][in.y + my[i]][in.z + mz[i]] = false;
        q.push(tmp);
      }
    }
  }
  printf("%d\n", r);
  return 0;
}
