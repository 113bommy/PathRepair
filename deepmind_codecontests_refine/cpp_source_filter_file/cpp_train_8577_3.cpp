#include <bits/stdc++.h>
using namespace std;
const int m = 3003;
int n, ax[100111], bx[100111], ay[100111], by[100111];
int pos[3003][3003], sum[3003][3003];
int difcol[3003][3003], difrow[3003][3003];
bool head[3003][3003];
inline int getSum(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x2][y1 - 1] - sum[x1 - 1][y2];
}
bool isRect(int x1, int y1, int x2, int y2) {
  if (getSum(x1, y1, x2, y2) != (x2 - x1 + 1) * (y2 - y1 + 1)) return false;
  if (difcol[x2][y2 + 1] - difcol[x1 - 1][y2 + 1] != x2 - x1 + 1) return false;
  if (difrow[x2 + 1][y2] - difrow[x2 + 1][y1 - 1] != y2 - y1 + 1) return false;
  return true;
}
bool solve() {
  for (int x = (1), _b = (m); x <= _b; x++)
    for (int y = (1), _b = (m); y <= _b; y++)
      if (head[x][y]) {
        int id = pos[x][y];
        int r = ax[id], c = ay[id];
        while (true) {
          if (pos[r][y] < 0 || pos[x][c] < 0) break;
          if (!head[r][y] || !head[x][c]) break;
          r = bx[pos[r][y]];
          c = by[pos[x][c]];
          if (r - x == c - y) {
            if (isRect(x, y, r, c)) {
              vector<int> res;
              for (int i = (x), _b = (r); i <= _b; i++)
                for (int j = (y), _b = (c); j <= _b; j++)
                  if (head[i][j]) res.push_back(pos[i][j]);
              sort(res.begin(), res.end());
              printf("YES %d\n", res.size());
              for (int i = 0, _n = (res.size()); i < _n; i++)
                printf("%d ", res[i]);
              return true;
            }
          }
          if (r - x < c - y) {
            c = ay[pos[x][c]];
            r++;
          } else {
            r = ax[pos[r][y]];
            c++;
          }
        }
      }
  return false;
}
int main() {
  scanf("%d", &n);
  memset(pos, -1, sizeof(pos));
  memset(head, false, sizeof(head));
  for (int i = 0, _n = (n); i < _n; i++) {
    scanf("%d %d %d %d", &ax[i], &ay[i], &bx[i], &by[i]);
    ax[i]++;
    ay[i]++;
    head[ax[i]][ay[i]] = true;
    for (int x = (ax[i]), _b = (bx[i]); x <= _b; x++)
      for (int y = (ay[i]), _b = (by[i]); y <= _b; y++) pos[x][y] = i;
  }
  memset(sum, 0, sizeof(sum));
  memset(difcol, 0, sizeof(difcol));
  memset(difrow, 0, sizeof(difrow));
  for (int i = (1), _b = (m); i <= _b; i++)
    for (int j = (1), _b = (m); j <= _b; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      if (pos[i][j] >= 0) sum[i][j]++;
      difcol[i][j] = difcol[i - 1][j];
      if (pos[i][j] != pos[i][j - 1]) difcol[i][j]++;
      difrow[i][j] = difrow[i][j - 1];
      if (pos[i][j] != pos[i - 1][j]) difrow[i][j]++;
    }
  if (!solve()) puts("NO");
  return 0;
}
