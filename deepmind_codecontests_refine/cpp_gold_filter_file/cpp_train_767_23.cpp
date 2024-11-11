#include <bits/stdc++.h>
using namespace std;
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int R, C, n;
int ans;
pair<int, int> p[3010][2 * 3010];
bool b[3010][2 * 3010];
pair<int, int> find(pair<int, int> x) {
  if (p[x.first][x.second] == x) return x;
  return p[x.first][x.second] = find(p[x.first][x.second]);
}
void merge(pair<int, int> x, pair<int, int> y) {
  x = find(x);
  y = find(y);
  p[y.first][y.second] = x;
}
bool good(int r, int c) {
  if (C == 1) return 0;
  for (int i = 0; i < 8; i++) {
    int r1 = r + dr[i];
    int c1 = c + dc[i];
    if (c1 < 1) c1 = C + C;
    if (!b[r1][c1]) continue;
    for (int j = 0; j < 8; j++) {
      int r2 = r + dr[j];
      int c2 = c + C + dc[j];
      if (c2 > C + C) c2 = 1;
      if (!b[r2][c2]) continue;
      if (find(make_pair(r1, c1)) == find(make_pair(r2, c2))) return 0;
    }
  }
  return 1;
}
void add(int r, int c) {
  b[r][c] = 1;
  for (int i = 0; i < 8; i++) {
    int rr = r + dr[i];
    int cc = c + dc[i];
    if (cc < 1) cc = C + C;
    if (cc > C + C) cc = 1;
    if (b[rr][cc]) merge(make_pair(r, c), make_pair(rr, cc));
  }
}
int main() {
  cin >> R >> C >> n;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C + C; j++) {
      p[i][j] = make_pair(i, j);
    }
  }
  while (n--) {
    int r, c;
    cin >> r >> c;
    if (good(r, c)) {
      ans++;
      add(r, c);
      add(r, c + C);
    }
  }
  cout << ans << '\n';
}
