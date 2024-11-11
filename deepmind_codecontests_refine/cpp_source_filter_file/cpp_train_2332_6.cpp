#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[505][505];
char st[505];
int b[505][505];
struct Ins {
  char cz;
  int x, y;
} ins[1000000];
int num = 0;
int dx[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
void dfs(int x, int y) {
  b[x][y] = 1;
  ins[num].cz = 'B';
  ins[num].x = x;
  ins[num].y = y;
  num++;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[0][i];
    int ny = y + dx[1][i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] && !b[nx][ny]) {
      dfs(nx, ny);
      ins[num].cz = 'D';
      ins[num].x = nx;
      ins[num].y = ny;
      num++;
      ins[num].cz = 'R';
      ins[num].x = nx;
      ins[num].y = ny;
      num++;
    }
  }
}
int main(int argc, char *argv[]) {
  memset(b, 0, sizeof(b));
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    scanf("%s", st);
    for (int j = 0; j < m; ++j)
      if (st[j] == '.')
        a[i][j] = 1;
      else
        a[i][j] = 0;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (b[i][j] == 0 && a[i][j]) dfs(i, j);
  cout << num << endl;
  for (int i = 0; i < num; ++i) {
    cout << ins[i].cz << " " << ins[i].x + 1 << " " << ins[i].y + 1 << endl;
  }
  return 0;
}
