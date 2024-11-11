#include <bits/stdc++.h>
using namespace std;
struct pos {
  int x, y, t, b, len, dir;
  pos(int x_, int y_, int t_, int b_, int len_) {
    x = x_;
    y = y_;
    t = t_;
    b = b_;
    len = len_;
  }
  bool operator<(pos b) const { return len > b.len; }
};
short minDist[32][32][(1 << 8)][(1 << 8)];
char arr[32][32];
int ids[32][32], val[32];
int cntB, cntT;
int sizeX, sizeY, stX, stY;
int setPosB(int x, int y) {
  int ret = 0;
  for (int cx = 0; cx < x; cx++) {
    if (arr[y][cx] == 'B') {
      ret |= (1 << ids[y][cx]);
    }
  }
  return ret;
}
int setPosT(int x, int y) {
  int ret = 0;
  for (int cx = 0; cx < x; cx++) {
    if (arr[y][cx] >= '0' && arr[y][cx] <= '9') {
      ret |= (1 << ids[y][cx]);
    }
  }
  return ret;
}
queue<pos> q;
void getPos(int x, int y, int t, int b, int len) {
  if (arr[y][x] != '.' && arr[y][x] != 'S') {
    return;
  }
  if (minDist[y][x][t][b] <= len) {
    return;
  }
  minDist[y][x][t][b] = len;
  if (x > 0) {
    q.push(pos(x - 1, y, t, b, len + 1));
  }
  if (x + 1 < sizeX) {
    q.push(pos(x + 1, y, t, b, len + 1));
  }
  if (y > 0) {
    q.push(
        pos(x, y - 1, t ^ setPosT(x, y - 1), b ^ setPosB(x, y - 1), len + 1));
  }
  if (y + 1 < sizeY) {
    q.push(pos(x, y + 1, t ^ setPosT(x, y), b ^ setPosB(x, y), len + 1));
  }
}
int getVal(int t) {
  int ret = 0;
  for (int i = 0; i < cntT; i++) {
    if ((1 << i) & t) {
      ret += val[i];
    }
  }
  return ret;
}
int main() {
  cin >> sizeY >> sizeX;
  for (int i = 0; i < sizeY; i++) {
    cin >> arr[i];
    for (int j = 0; j < sizeX; j++) {
      if (arr[i][j] == '.') {
        continue;
      } else if (arr[i][j] == '#') {
        continue;
      } else if (arr[i][j] == 'B') {
        ids[i][j] = cntB++;
      } else if (arr[i][j] == 'S') {
        stX = j;
        stY = i;
      } else {
        ids[i][j] = arr[i][j] - '0' - 1;
        cntT++;
      }
    }
  }
  for (int i = 0; i < cntT; i++) {
    cin >> val[i];
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      for (int k1 = 0; k1 < (1 << 8); k1++) {
        for (int k2 = 0; k2 < (1 << 8); k2++) {
          minDist[i][j][k1][k2] = (1 << 10);
        }
      }
    }
  }
  int t = 0, b = 0;
  q.push(pos(stX, stY, 0, 0, 0));
  while (!q.empty()) {
    pos c = q.front();
    getPos(c.x, c.y, c.t, c.b, c.len);
    q.pop();
  }
  int ret = 0;
  for (int t = 0; t < (1 << cntT); t++) {
    ret = max(ret, getVal(t) - minDist[stY][stX][t][0]);
  }
  cout << ret << "\n";
  return 0;
}
