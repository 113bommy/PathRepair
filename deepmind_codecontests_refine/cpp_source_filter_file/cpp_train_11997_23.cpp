#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T re() {
  T N = 0;
  char c = getchar();
  bool neg = 0;
  for (; c < '0' || c > '9'; c = getchar()) neg |= c == '-';
  for (; c >= '0' && c <= '9'; c = getchar()) N = (N << 3) + (N << 1) + c - '0';
  return neg ? -N : N;
}
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
int n, m;
int moves;
char g[55][55];
int col[55][55];
bool vis[55][55];
struct bound {
  pair<int, int> mx, mn;
  bound() : mx(0, 0), mn(100, 100) {}
  void set(int r, int c) {
    mx.first = max(mx.first, r);
    mx.second = max(mx.second, c);
    mn.first = min(mn.first, r);
    mn.second = min(mn.second, c);
  }
} lims[3000];
pair<int, int> mov[3000];
pair<pair<int, int>, int> get(pair<int, int> curpos, int movetype) {
  int dp = movetype / 2;
  int cp = movetype % 2;
  int color = col[curpos.first][curpos.second];
  pair<int, int> nx;
  if (dp == 0) {
    nx.second = lims[color].mx.second;
    if (cp)
      nx.first = lims[color].mx.first;
    else
      nx.first = lims[color].mn.first;
  } else if (dp == 1) {
    nx.first = lims[color].mx.first;
    if (cp)
      nx.second = lims[color].mn.second;
    else
      nx.second = lims[color].mx.second;
  } else if (dp == 2) {
    nx.second = lims[color].mn.second;
    if (cp)
      nx.first = lims[color].mn.first;
    else
      nx.first = lims[color].mx.first;
  } else {
    nx.first = lims[color].mx.first;
    if (cp)
      nx.second = lims[color].mx.second;
    else
      nx.second = lims[color].mn.second;
  }
  pair<int, int> tmp = {nx.first + dr[dp], nx.second + dc[dp]};
  if (1 <= tmp.first && tmp.first <= n && 1 <= tmp.second && tmp.second <= m &&
      col[tmp.first][tmp.second]) {
    return {tmp, movetype};
  } else {
    return {nx, (movetype + 1) % 8};
  }
}
void ff(int r, int c, int COL, char hd) {
  vis[r][c] = 1;
  lims[COL].set(r, c);
  col[r][c] = COL;
  for (int i = 0, rr, cc; i < 4; i++) {
    rr = r + dr[i];
    cc = c + dc[i];
    if (1 <= rr && rr <= n && 1 <= cc && cc <= m && !vis[rr][cc]) {
      if (g[rr][cc] == hd) {
        ff(rr, cc, COL, hd);
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &moves);
  for (int i = 1; i <= n; i++) {
    scanf("%s", g[i] + 1);
    if (i == 1) m = strlen(g[i] + 1);
  }
  int numCol = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j] && g[i][j] != '0') ff(i, j, ++numCol, g[i][j]);
    }
  }
  pair<pair<int, int>, int> cur = {{1, 1}, 0};
  for (int i = 1; i <= moves; i++) {
    cur = get(cur.first, cur.second);
  }
  printf("%c\n", g[cur.first.first][cur.first.second]);
  return 0;
}
