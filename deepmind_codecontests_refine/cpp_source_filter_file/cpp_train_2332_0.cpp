#include <bits/stdc++.h>
using namespace std;
tuple<char, int, int> ans[1000000];
int idx;
inline void add(char c, int x, int y) {
  ans[idx++] = make_tuple(c, y + 1, x + 1);
}
bool visit[1000][1000];
string v[1000];
int dx[] = {0, 1, 0, -1};
int dy[] = {
    -1,
    0,
    1,
    0,
};
int h, w;
void dfs(int x, int y, bool f = true) {
  visit[y][x] = true;
  for (int i = (0); i < (int)(4); ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || nx >= w || ny < 0 || ny >= h || visit[ny][nx]) continue;
    dfs(nx, ny, 0);
  }
  if (!f) {
    add('D', x, y);
    add('R', x, y);
  }
}
int main() {
  cin >> h >> w;
  for (int i = (0); i < (int)(h); ++i) cin >> v[i];
  for (int i = (0); i < (int)(h); ++i)
    for (int j = (0); j < (int)(w); ++j) {
      if (v[i][j] != '.') {
        visit[i][j] = true;
        continue;
      }
      add('B', j, i);
    }
  for (int i = (0); i < (int)(h); ++i)
    for (int j = (0); j < (int)(w); ++j) {
      if (visit[i][j] || v[i][j] != '.') continue;
      dfs(j, i);
    }
  printf("%d\n", idx);
  for (int i = (0); i < (int)(idx); ++i) {
    printf("%c %d %d\n", get<0>(ans[idx]), get<1>(ans[idx]), get<2>(ans[idx]));
  }
  return 0;
}
