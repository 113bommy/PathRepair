#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int N = 2002;
int n, m;
char mat[N][N];
queue<pair<long long, long long> > q;
string t1 = "^v<>";
string t2 = "v^><";
int check(int x, int y) {
  int qtd = 0;
  for (int i = 0; i < 4; ++i) {
    int xx = dx[i] + x;
    int yy = dy[i] + y;
    if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
    qtd += (mat[xx][yy] == '.');
  }
  return qtd;
}
void ver_adj(int a, int b) {
  for (int i = 0; i < 4; ++i) {
    int xx = a + dx[i];
    int yy = b + dy[i];
    if (mat[xx][yy] != '.') continue;
    if (check(xx, yy) == 1) q.push(make_pair(xx, yy));
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf(" %s", mat[i]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '.') {
        if (check(i, j) == 1) q.push(pair<long long, long long>(i, j));
      }
    }
  }
  while (!q.empty()) {
    pair<long long, long long> foo = q.front();
    q.pop();
    int x = foo.first;
    int y = foo.second;
    if (mat[x][y] != '.') continue;
    for (int i = 0; i < 4; ++i) {
      int xx = dx[i] + x;
      int yy = dy[i] + y;
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if (mat[xx][yy] == '.') {
        mat[x][y] = t1[i];
        mat[xx][yy] = t2[i];
        ver_adj(x, y);
        ver_adj(xx, yy);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '.') {
        printf("Not unique\n");
        return 0;
      }
    }
  }
  for (int i = 0; i < n; ++i) printf("%s\n", mat[i]);
  return 0;
}
