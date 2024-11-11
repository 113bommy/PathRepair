#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
int R, C;
char pic[maxn][maxn];
bool vis[maxn][maxn];
int sr, sc, er, ec;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
bool ok(int r, int c) { return r >= 1 && r <= R && c >= 1 && c <= C; }
struct Node {
  int r, c;
  Node(int r = 0, int c = 0) : r(r), c(c) {}
};
bool bfs() {
  memset(vis, 0, sizeof(vis));
  queue<Node> Q;
  Q.push(Node(sr, sc));
  while (!Q.empty()) {
    Node now = Q.front();
    Q.pop();
    int r = now.r, c = now.c;
    pic[r][c] = 'X';
    for (int i = 0; i < 4; ++i) {
      int tr = r + dr[i];
      int tc = c + dc[i];
      if (tr == er && tc == ec) {
        if (pic[tr][tc] == 'X') return true;
        for (int i = 0; i < 4; ++i) {
          int ttr = tr + dr[i], ttc = tc + dc[i];
          if (ok(ttr, ttc) && pic[ttr][ttc] == '.') return true;
        }
      }
      if (ok(tr, tc) && !vis[tr][tc] && pic[tr][tc] == '.') {
        vis[tr][tc] = 1;
        Q.push(Node(tr, tc));
      }
    }
  }
  return false;
}
int main() {
  scanf("%d %d", &R, &C);
  for (int i = 1; i <= R; ++i) scanf("%s", pic[i] + 1);
  scanf("%d %d %d %d", &sr, &sc, &er, &ec);
  if (bfs())
    puts("YES");
  else
    puts("NO");
  return 0;
}
