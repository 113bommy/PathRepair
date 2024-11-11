#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
const int maxq = maxn * maxn;
int n, m;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
const char uc[] = {'>', 'v', '<', '^'};
const char vc[] = {'<', '^', '>', 'v'};
pair<int, int> Q[maxq];
int l, r;
char s[maxn][maxn];
char cnt[maxn][maxn];
void pre() {
  for (int i = 0; i <= n + 1; ++i) s[i][0] = s[i][m + 1] = '*';
  for (int j = 0; j <= m + 1; ++j) s[0][j] = s[n + 1][j] = '*';
}
inline void dec(const int& x, const int& y) {
  int vx, vy;
  for (int i = 0; i < 4; ++i) {
    vx = x + dx[i];
    vy = y + dy[i];
    if (~vx && ~vy && s[vx][vy] == '.') ++cnt[vx][vy];
  }
}
void noans() {
  puts("Not unique");
  exit(0);
}
void expand(const int& x, const int& y) {
  int vx, vy;
  for (int i = 0; i < 4; ++i) {
    vx = x + dx[i];
    vy = y + dy[i];
    if (cnt[vx][vy] == 3) Q[r++] = make_pair(vx, vy);
  }
}
void bfs() {
  l = r = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (cnt[i][j] == 3)
        Q[r++] = make_pair(i, j);
      else if (cnt[i][j] == 4)
        noans();
    }
  while (l != r) {
    int ux = Q[l].first, uy = Q[l].second;
    if (s[ux][uy] == '.') {
      for (int i = 0; i < 4; ++i) {
        int vx = ux + dx[i];
        int vy = uy + dy[i];
        if (s[vx][vy] == '.') {
          s[ux][uy] = uc[i];
          dec(ux, uy);
          s[vx][vy] = vc[i];
          dec(vx, vy);
          expand(ux, uy);
          expand(vx, vy);
          break;
        }
      }
    }
    ++l;
  }
}
void checkans() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (s[i][j] == '.') noans();
}
void output() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%c", s[i][j]);
    printf("\n");
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  pre();
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= m + 1; ++j)
      if (s[i][j] == '*') dec(i, j);
  bfs();
  checkans();
  output();
  return 0;
}
