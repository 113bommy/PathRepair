#include <bits/stdc++.h>
using namespace std;
int n;
int a[3000][3000];
bool used[3000][3000];
int s, per, maxx, maxy, minx;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
inline bool check(int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= n) return 0;
  return 1;
}
void dfs(int i, int j) {
  if (!check(i, j)) return;
  if (used[i][j]) return;
  if (a[i][j] == 0) return;
  used[i][j] = 1;
  if (i > maxx) maxx = i;
  if (i < minx) minx = i;
  if (j > maxy) maxy = j;
  s++;
  int toadd = 1;
  for (int k = 0; k < 4; k++) {
    dfs(i + dx[k], j + dy[k]);
    if (!check(i + dx[k], j + dy[k]) || a[i + dx[k]][j + dy[k]] == 0)
      per += toadd, toadd = 0;
  }
}
int main(void) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d ", &a[i][j]);
    }
  }
  int c = 0, sq = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) continue;
      if (used[i][j]) continue;
      s = per = maxx = maxy = 0;
      minx = n;
      dfs(i, j);
      double r = (maxx * 1.0 - minx) / 2;
      r = per * 1.0 / r / 2;
      if (fabs(r - 4.0) > 0.1) {
        c++;
      } else {
        sq++;
      }
    }
  }
  cout << c << " " << sq;
}
