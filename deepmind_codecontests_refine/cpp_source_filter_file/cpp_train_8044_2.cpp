#include <bits/stdc++.h>
using namespace std;
int ver[(int)1e5][3];
int constmatr[4][3][3] = {
    {{1, 1, 1}, {0, 1, 0}, {0, 1, 0}},
    {{0, 0, 1}, {1, 1, 1}, {0, 0, 1}},
    {{0, 1, 0}, {0, 1, 0}, {1, 1, 1}},
    {{1, 0, 0}, {1, 1, 1}, {1, 0, 0}},
};
vector<vector<int> > es;
int ans[100], now[100];
int rnow, rans;
int n;
int used[1000];
long long tmeend;
void solve(int it) {
  while (it < n && used[it]) it++;
  if (it == n) {
    if (rnow > rans) {
      rans = rnow;
      for (int i = 0; i < rans; i++) ans[i] = now[i];
    }
    return;
  }
  if (clock() > tmeend) return;
  now[rnow++] = it;
  used[it] = 1;
  for (int iter = 0; iter < (int)es[it].size(); iter++) used[es[it][iter]]++;
  solve(it + 1);
  for (int iter = 0; iter < (int)es[it].size(); iter++) used[es[it][iter]]--;
  used[it] = 0;
  rnow--;
  solve(it + 1);
}
int main() {
  tmeend = clock() + CLOCKS_PER_SEC * 2.6;
  int w, h;
  while (scanf("%d%d", &h, &w) >= 1) {
    int cnt = 0;
    for (int i = 0; i < h - 2; i++) {
      for (int j = 0; j < w - 2; j++) {
        for (int g = 0; g < 4; g++) {
          ver[cnt][0] = i;
          ver[cnt][1] = j;
          ver[cnt][2] = g;
          cnt++;
        }
      }
    }
    es = vector<vector<int> >(cnt);
    vector<vector<int> > matr(h, vector<int>(w, 0));
    for (int i = 0; i < cnt; i++) {
      int y1 = ver[i][0];
      int x1 = ver[i][1];
      int g1 = ver[i][2];
      for (int j = i + 1; j < cnt; j++) {
        int y2 = ver[j][0];
        int x2 = ver[j][1];
        int g2 = ver[j][2];
        if (abs(y1 - y2) > 2 || abs(x1 - x2) > 2) continue;
        for (int y = 0; y < 3; y++) {
          for (int x = 0; x < 3; x++) {
            matr[y1 + y][x1 + x] += constmatr[g1][y][x];
          }
        }
        bool neededge = 0;
        for (int y = 0; y < 3; y++) {
          for (int x = 0; x < 3; x++) {
            matr[y2 + y][x2 + x] += constmatr[g2][y][x];
            neededge |= (matr[y2 + y][x2 + x] == 2);
          }
        }
        for (int y = 0; y < 3; y++) {
          for (int x = 0; x < 3; x++) {
            matr[y2 + y][x2 + x] = 0;
          }
        }
        for (int y = 0; y < 3; y++) {
          for (int x = 0; x < 3; x++) {
            matr[y1 + y][x1 + x] = 0;
          }
        }
        if (neededge) {
          es[i].push_back(j);
          es[j].push_back(i);
        }
      }
    }
    rans = 0;
    rnow = 0;
    n = cnt;
    memset(used, 0, sizeof(used));
    solve(0);
    vector<vector<char> > res(h, vector<char>(w, '.'));
    for (int it = 0; it < rans; it++) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (!constmatr[ver[ans[it]][2]][i][j]) continue;
          res[ver[ans[it]][0] + i][ver[ans[it]][1] + j] = 'A' + it;
        }
      }
    }
    printf("%d\n", rans);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) printf("%c", res[i][j]);
      printf("\n");
    }
  }
  return 0;
}
