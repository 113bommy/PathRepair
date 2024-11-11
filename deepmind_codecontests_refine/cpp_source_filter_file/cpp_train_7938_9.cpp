#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n;
int m;
bool visited[maxn][maxn];
int unvisited_row(int c) {
  for (int r = 0; r < n; ++r)
    if (!visited[r][c]) return r;
  return -1;
}
int unvisited_col(int r) {
  for (int c = 0; c < m; ++c)
    if (!visited[r][c]) return c;
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int r, c;
  scanf("%d%d", &n, &m);
  scanf("%d%d", &r, &c);
  --r;
  --c;
  int cnt = 0;
  visited[r][c] = true;
  while (true) {
    printf("%d %d\n", r + 1, c + 1);
    ++cnt;
    if (int r2 = unvisited_row(c); r2 != -1) {
      r = r2;
    } else if (int c2 = unvisited_col(c); c2 != -1) {
      c = c2;
    } else {
      break;
    }
    visited[r][c] = true;
  }
}
