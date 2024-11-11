#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int MAXX = 2048;
long long bit[MAXX][MAXX];
void update(int x, int y, int v) {
  for (; x < MAXX; x += (x & -x)) {
    for (int yy = y; yy < MAXX; yy += (yy & (-yy))) {
      bit[x][yy] += v;
    }
  }
}
long long query(int x, int y) {
  int res = 0;
  for (; x > 0; x -= x & (-x)) {
    for (int yy = y; yy > 0; yy -= yy & -yy) {
      res += bit[x][yy];
    }
  }
  return res;
}
int R, C, K, Q = 0;
int garlands[2048][2048][3];
int glen[2048];
bool active[2048];
vector<int> in_use[2048];
int position[2048][4];
long long res[2048];
int main() {
  scanf("%d%d%d", &R, &C, &K);
  for (int k = (0); k < (K); k++) {
    scanf("%d", &(glen[k]));
    for (int i = (0); i < (glen[k]); i++)
      for (int j = (0); j < (3); j++) scanf("%d", &(garlands[k][i][j]));
  }
  int QQ;
  scanf("%d", &QQ);
  for (int i = (0); i < (K); i++) active[i] = true;
  for (int q = (0); q < (QQ); q++) {
    char t[16];
    scanf("%s", t);
    if (t[0] == 'S') {
      int id;
      scanf("%d", &id);
      active[id - 1] ^= 1;
    } else {
      for (int i = (0); i < (4); i++) scanf("%d", &(position[Q][i]));
      for (int i = (0); i < (2); i++) --position[Q][i];
      for (int i = (0); i < (K); i++)
        if (active[i]) in_use[i].push_back(Q);
      ++Q;
    }
  }
  memset(bit, 0, sizeof(bit));
  memset(res, 0, sizeof(res));
  for (int k = (0); k < (K); k++) {
    for (int i = (0); i < (glen[k]); i++) {
      update(garlands[k][i][0], garlands[k][i][1], garlands[k][i][2]);
    }
    for (auto id : in_use[k]) {
      res[id] += query(position[id][0], position[id][1]);
      res[id] += query(position[id][2], position[id][3]);
      res[id] -= query(position[id][2], position[id][1]);
      res[id] -= query(position[id][0], position[id][3]);
    }
    for (int i = (0); i < (glen[k]); i++) {
      update(garlands[k][i][0], garlands[k][i][1], -garlands[k][i][2]);
    }
  }
  for (int i = (0); i < (Q); i++) cout << res[i] << endl;
  ;
  return 0;
}
