#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2500000000;
const int inf = 0x3f3f3f3f;
const double EPS = 1e-9;
const double PII = 2 * asin(1.0);
const long long mod = 1e9 + 7;
int double_cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
int n, m;
int trans[300][4];
int loop[1010][1010][4];
string mapa[1010];
int mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};
bool ins(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void bfs(int X, int Y) {
  queue<pair<pair<int, int>, int> > fila;
  fila.push(make_pair(make_pair(X, Y), 0));
  loop[X][Y][0] = 0;
  while (!fila.empty()) {
    int x = fila.front().first.first;
    int y = fila.front().first.second;
    int t = fila.front().second;
    int nt = (t + 1) % 4;
    int d = loop[x][y][t];
    fila.pop();
    for (int i = 0; i < 4; ++i) {
      if (trans[mapa[x][y]][t] & (1 << i)) {
        int nx = x + mx[i];
        int ny = y + my[i];
        if (ins(nx, ny) && mapa[nx][ny] != '*') {
          if (i == 0) {
            if (trans[mapa[nx][ny]][t] & 2) {
              if (d + 1 < loop[nx][ny][t]) {
                loop[nx][ny][t] = d + 1;
                fila.push(make_pair(make_pair(nx, ny), t));
              }
            }
          } else if (i == 1) {
            if (trans[mapa[nx][ny]][t] & 1) {
              if (d + 1 < loop[nx][ny][t]) {
                loop[nx][ny][t] = d + 1;
                fila.push(make_pair(make_pair(nx, ny), t));
              }
            }
          } else if (i == 2) {
            if (trans[mapa[nx][ny]][t] & 8) {
              if (d + 1 < loop[nx][ny][t]) {
                loop[nx][ny][t] = d + 1;
                fila.push(make_pair(make_pair(nx, ny), t));
              }
            }
          } else {
            if (trans[mapa[nx][ny]][t] & 4) {
              if (d + 1 < loop[nx][ny][t]) {
                loop[nx][ny][t] = d + 1;
                fila.push(make_pair(make_pair(nx, ny), t));
              }
            }
          }
        }
      }
    }
    if (d + 1 < loop[x][y][nt]) {
      loop[x][y][nt] = d + 1;
      fila.push(make_pair(make_pair(x, y), nt));
    }
  }
}
int main() {
  trans['+'][0] = 15;
  trans['+'][1] = 15;
  trans['+'][2] = 15;
  trans['+'][3] = 15;
  trans['-'][0] = 12;
  trans['-'][1] = 3;
  trans['-'][2] = 12;
  trans['-'][3] = 3;
  trans['|'][0] = 3;
  trans['|'][1] = 12;
  trans['|'][2] = 3;
  trans['|'][3] = 12;
  trans['^'][0] = 2;
  trans['^'][1] = 4;
  trans['^'][2] = 1;
  trans['^'][3] = 8;
  trans['>'][0] = 4;
  trans['>'][1] = 1;
  trans['>'][2] = 8;
  trans['>'][3] = 2;
  trans['<'][0] = 8;
  trans['<'][1] = 2;
  trans['<'][2] = 4;
  trans['<'][3] = 1;
  trans['v'][0] = 1;
  trans['v'][1] = 8;
  trans['v'][2] = 2;
  trans['v'][3] = 4;
  trans['L'][0] = 7;
  trans['L'][1] = 13;
  trans['L'][2] = 11;
  trans['L'][3] = 14;
  trans['R'][0] = 11;
  trans['R'][1] = 14;
  trans['R'][2] = 7;
  trans['R'][3] = 13;
  trans['U'][0] = 13;
  trans['U'][1] = 11;
  trans['U'][2] = 14;
  trans['U'][3] = 7;
  trans['D'][0] = 14;
  trans['D'][1] = 7;
  trans['D'][2] = 13;
  trans['D'][3] = 11;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) cin >> mapa[i];
  int x, y;
  scanf("%d%d", &x, &y);
  x--, y--;
  int fx, fy;
  scanf("%d%d", &fx, &fy);
  fx--, fy--;
  memset(loop, inf, sizeof loop);
  bfs(x, y);
  int menor = inf;
  for (int i = 0; i < 4; ++i) menor = min(menor, loop[fx][fy][i]);
  if (menor == inf)
    printf("%d\n", -1);
  else
    printf("%d\n", menor);
}
