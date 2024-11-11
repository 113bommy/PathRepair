#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
long long ln, lk, lm;
int a[1605][1605], cp[1605][1605], C, sz[1605], cp1[1605][1605],
    ray[1605][1605];
double xsum[1605], ysum[1605];
bool bd[1605][1605], use[1605][1605];
int ans[1605];
bool in(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }
void dfs(int i, int j, int c) {
  if (!in(i, j) || !a[i][j] || cp[i][j] != -1) return;
  cp[i][j] = c;
  for (int(k) = 0; (k) < (int)(4); (k)++) dfs(i + dx[k], j + dy[k], c);
}
void dfs1(int i, int j, int c) {
  if (!in(i, j) || !a[i][j] || cp1[i][j] != -1 || bd[i][j]) return;
  cp1[i][j] = c;
  for (int(k) = 0; (k) < (int)(4); (k)++) dfs1(i + dx[k], j + dy[k], c);
}
void dfs2(int i, int j) {
  if (!in(i, j) || !ray[i][j] || use[i][j]) return;
  use[i][j] = 1;
  for (int(k) = 0; (k) < (int)(4); (k)++) dfs2(i + dx[k], j + dy[k]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(m); (j)++) scanf("%d", &a[i][j]);
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(m); (j)++) {
      cp[i][j] = -1;
      cp1[i][j] = -1;
    }
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(m); (j)++)
      if (cp[i][j] == -1) {
        if (a[i][j]) {
          dfs(i, j, C);
          C++;
        }
      }
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(m); (j)++)
      if (cp[i][j] != -1) {
        int c = cp[i][j];
        sz[c]++;
        xsum[c] += i;
        ysum[c] += j;
      }
  for (int(i) = 0; (i) < (int)(C); (i)++) {
    xsum[i] /= sz[i];
    ysum[i] /= sz[i];
  }
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(m); (j)++)
      if (!a[i][j]) {
        int xmin = max(i - 2, 0), xmax = min(i + 2, n - 1);
        int ymin = max(j - 2, 0), ymax = min(j + 2, m - 1);
        for (int x = xmin; x <= xmax; x++)
          for (int y = ymin; y <= ymax; y++) bd[x][y] = 1;
      }
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(m); (j)++)
      if (!a[i][j]) bd[i][j] = 0;
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(m); (j)++) dfs1((int)xsum[i], (int)ysum[i], i);
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(m); (j)++)
      if (bd[i][j]) {
        ray[i][j] = 1;
        int c = cp[i][j];
        int xmin = max(i - 4, 0), xmax = min(i + 4, n - 1);
        int ymin = max(j - 4, 0), ymax = min(j + 4, m - 1);
        for (int x = xmin; x <= xmax; x++)
          for (int y = ymin; y <= ymax; y++)
            if (cp1[x][y] == c) ray[i][j] = 0;
      }
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(m); (j)++)
      if (ray[i][j] && !use[i][j]) {
        ans[cp[i][j]]++;
        dfs2(i, j);
      }
  sort(ans, ans + C);
  printf("%d\n", C);
  for (int(i) = 0; (i) < (int)(C); (i)++) printf("%d ", ans[i]);
  return 0;
}
