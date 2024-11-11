#include <bits/stdc++.h>
using namespace std;
const int N = 75;
char mp[N][N];
struct Stone_Position {
  int posx, posy, posz, res;
};
struct Answer_Path {
  int from;
  int num;
  int res;
} pa[N][N][N];
int n, s1, s2, s3;
queue<Stone_Position> q;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
void BFS_FOR_PATH() {
  while (!q.empty()) {
    Stone_Position cur = q.front();
    q.pop();
    int pos1 = cur.posx, pos2 = cur.posy, pos3 = cur.posz;
    for (int i = 1; i <= n; i++) {
      if (i == pos1 || i == pos2 || i == pos3) continue;
      if (mp[pos1][i] == mp[pos2][pos3] && !(~pa[i][pos2][pos3].res)) {
        pa[i][pos2][pos3].res = cur.res + 1;
        pa[i][pos2][pos3].from = pos1;
        pa[i][pos2][pos3].num = 1;
        q.push(Stone_Position{i, pos2, pos3, cur.res + 1});
      }
      if (mp[pos2][i] == mp[pos1][pos3] && !(~pa[pos1][i][pos3].res)) {
        pa[pos1][i][pos3].res = cur.res + 1;
        pa[pos1][i][pos3].from = pos2;
        pa[pos1][i][pos3].num = 2;
        q.push(Stone_Position{pos1, i, pos3, cur.res + 1});
      }
      if (mp[pos3][i] == mp[pos1][pos2] && !(~pa[pos1][pos2][i].res)) {
        pa[pos1][pos2][i].res = cur.res + 1;
        pa[pos1][pos2][i].from = pos3;
        pa[pos1][pos2][i].num = 3;
        q.push(Stone_Position{pos1, pos2, i, cur.res + 1});
      }
    }
  }
}
void Find_Path(int x, int y, int z) {
  if (!pa[x][y][z].res) return;
  if (pa[x][y][z].num == 1) {
    Find_Path(pa[x][y][z].from, y, z);
    cout << pa[x][y][z].from << " " << x << endl;
  }
  if (pa[x][y][z].num == 2) {
    Find_Path(x, pa[x][y][z].from, z);
    cout << pa[x][y][z].from << " " << y << endl;
  }
  if (pa[x][y][z].num == 3) {
    Find_Path(x, y, pa[x][y][z].from);
    cout << pa[x][y][z].from << " " << z << endl;
  }
  return;
}
int main() {
  n = read(), s1 = read(), s2 = read(), s3 = read();
  memset(pa, -1, sizeof(pa));
  pa[s1][s2][s3].res = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> mp[i][j];
  q.push(Stone_Position{s1, s2, s3, 0});
  BFS_FOR_PATH();
  int ans = 0x3f3f3f3f;
  int end1, end2, end3;
  if (~pa[1][2][3].res && pa[1][2][3].res < ans) {
    ans = pa[1][2][3].res;
    end1 = 1, end2 = 2, end3 = 3;
  }
  if (~pa[1][3][2].res && pa[1][3][2].res < ans) {
    ans = pa[1][3][2].res;
    end1 = 1, end2 = 3, end3 = 2;
  }
  if (~pa[2][1][3].res && pa[2][1][3].res < ans) {
    ans = pa[2][1][3].res;
    end1 = 2, end2 = 1, end3 = 3;
  }
  if (~pa[2][3][1].res && pa[2][3][1].res < ans) {
    ans = pa[2][3][1].res;
    end1 = 2, end2 = 3, end3 = 1;
  }
  if (~pa[3][2][1].res && pa[3][2][1].res < ans) {
    ans = pa[3][2][1].res;
    end1 = 3, end2 = 2, end3 = 1;
  }
  if (~pa[3][1][2].res && pa[3][1][2].res < ans) {
    ans = pa[3][1][2].res;
    end1 = 3, end2 = 1, end3 = 2;
  }
  if (ans == 0x3f3f3f3f) puts("-1"), exit(0);
  cout << ans << endl;
  Find_Path(end1, end2, end3);
  return 0;
}
