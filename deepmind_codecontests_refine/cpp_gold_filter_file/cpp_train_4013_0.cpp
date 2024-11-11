#include <bits/stdc++.h>
using namespace std;
struct cell {
  int doors[4], aux[4];
  int i, j;
  int rotation;
  int dist[4];
  cell(int i = 0, int j = 0, char c = '*') {
    this->i = i;
    this->j = j;
    rotation = 0;
    for (int i = 0; i < 4; i++) doors[i] = 1;
    for (int i = 0; i < 4; i++) dist[i] = 100000000;
    switch (c) {
      case '+':
        break;
      case '-':
        doors[0] = doors[2] = 0;
        break;
      case '|':
        doors[1] = doors[3] = 0;
        break;
      case '^':
        doors[0] = doors[1] = doors[3] = 0;
        break;
      case '>':
        doors[0] = doors[1] = doors[2] = 0;
        break;
      case '<':
        doors[0] = doors[2] = doors[3] = 0;
        break;
      case 'v':
        doors[1] = doors[2] = doors[3] = 0;
        break;
      case 'L':
        doors[1] = 0;
        break;
      case 'R':
        doors[3] = 0;
        break;
      case 'U':
        doors[2] = 0;
        break;
      case 'D':
        doors[0] = 0;
        break;
      default:
        for (int i = 0; i < 4; i++) doors[i] = 0;
        break;
    }
  }
  void rotate(int times) {
    for (int i = 0; i < 4; i++) aux[i] = doors[i];
    int aux2[4];
    for (int i = 0; i < times; i++) {
      int aux3 = aux[3];
      for (int i = 1; i < 4; i++) aux2[i] = aux[i - 1];
      aux2[0] = aux3;
      for (int i = 0; i < 4; i++) aux[i] = aux2[i];
    }
  }
  bool isDoor(int id) { return aux[id]; }
};
cell mat[1110][1110];
int n, m;
bool valid(int i, int j, int r, int d, int id) {
  if (i < 0 || i >= n || j < 0 || j >= m) return 0;
  mat[i][j].rotate(r);
  if (!mat[i][j].isDoor(id)) return 0;
  return mat[i][j].dist[r] > d + 1;
}
int bfs(int x1, int y1, int x2, int y2) {
  mat[x1][y1].dist[0] = 0;
  queue<pair<cell, int> > q;
  q.push(make_pair(mat[x1][y1], 0));
  while (!q.empty()) {
    cell top = q.front().first;
    int i = top.i, j = top.j;
    int r = q.front().second;
    mat[i][j].rotate(r);
    q.pop();
    if (i == x2 && j == y2) return top.dist[r];
    if (mat[i][j].isDoor(0) && valid(i + 1, j, r, mat[i][j].dist[r], 2)) {
      mat[i + 1][j].dist[r] = mat[i][j].dist[r] + 1;
      q.push(make_pair(mat[i + 1][j], r));
    }
    if (mat[i][j].isDoor(1) && valid(i, j - 1, r, mat[i][j].dist[r], 3)) {
      mat[i][j - 1].dist[r] = mat[i][j].dist[r] + 1;
      q.push(make_pair(mat[i][j - 1], r));
    }
    if (mat[i][j].isDoor(2) && valid(i - 1, j, r, mat[i][j].dist[r], 0)) {
      mat[i - 1][j].dist[r] = mat[i][j].dist[r] + 1;
      q.push(make_pair(mat[i - 1][j], r));
    }
    if (mat[i][j].isDoor(3) && valid(i, j + 1, r, mat[i][j].dist[r], 1)) {
      mat[i][j + 1].dist[r] = mat[i][j].dist[r] + 1;
      q.push(make_pair(mat[i][j + 1], r));
    }
    if (mat[i][j].dist[r] + 1 < mat[i][j].dist[(r + 1) % 4]) {
      mat[i][j].dist[(r + 1) % 4] = mat[i][j].dist[r] + 1;
      q.push(make_pair(mat[i][j], (r + 1) % 4));
    }
  }
  return -1;
}
int main() {
  scanf("%d %d", &n, &m);
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &c);
      mat[i][j] = cell(i, j, c);
    }
  }
  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  x1--;
  y1--;
  x2--;
  y2--;
  printf("%d\n", bfs(x1, y1, x2, y2));
  return 0;
}
