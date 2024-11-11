#include <bits/stdc++.h>
using namespace std;
int mat[110][110];
vector<int> p[110][110];
int n, que[2 * 110];
bool solve(int type, int x, int &g, int &h) {
  if (g == h) return true;
  if (h > 2 * n) return false;
  if (mat[x][que[g]] != type) return false;
  for (int i = 0; i < (p[x][que[g]].size()); i++) que[h++] = p[x][que[g]][i];
  g++;
  return solve(type, que[g - 1], g, h);
}
int main() {
  int m, x, y;
  vector<int> v;
  scanf("%d%d", &n, &m);
  memset(mat, 0, sizeof(mat));
  for (int i = 0; i < (m); i++) {
    scanf("%d%d", &x, &y);
    int g, h;
    scanf("%d", &g);
    v.clear();
    while (g--) {
      scanf("%d", &h);
      v.push_back(h);
    }
    p[x][y] = v;
    mat[x][y] = 1;
    reverse(v.begin(), v.end());
    mat[y][x] = 2;
    p[y][x] = v;
  }
  bool flag = 0;
  for (int i = 1; i <= n && !flag; i++)
    for (int j = 1; j <= n && !flag; j++)
      if (mat[i][j] == 1) {
        for (int k = 0; k < ((int)p[i][j].size() - 1); k++)
          if (p[i][j][k] == i && p[i][j][k + 1] == j) {
            int g = 0, h = 0;
            for (int t = k - 1; t >= 0; t--) que[h++] = p[i][j][t];
            if (!solve(2, i, g, h)) continue;
            v.clear();
            for (int i = 0; i < (h); i++) v.push_back(que[h - i - 1]);
            g = 0, h = 0;
            for (int t = k + 2; t < p[i][j].size(); t++) que[h++] = p[i][j][t];
            if (!solve(1, j, g, h)) continue;
            v.push_back(i);
            v.push_back(j);
            for (int i = 0; i < (h); i++) v.push_back(que[h]);
            if (v.size() > 2 * n) continue;
            printf("%d\n", v.size());
            for (int i = 0; i < (v.size()); i++)
              printf("%d%c", v[i], i == v.size() - 1 ? '\n' : ' ');
            flag = 1;
            break;
          }
      }
  if (!flag) puts("0");
  return 0;
}
