#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
int x[2][100005], y[2][100005];
int mp[3105][3105], l[3105][3105], r[3105][3105], u[3105][3105], d[3105][3105];
int main() {
  scanf("%d", &n);
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    scanf("%d%d%d%d", &x[0][i], &y[0][i], &x[1][i], &y[1][i]);
    for (int p = x[0][i] + 1; p <= x[1][i]; p++) {
      for (int q = y[0][i] + 1; q <= y[1][i]; q++) {
        mp[p][q] = 1;
      }
    }
    for (int p = x[0][i] + 1; p <= x[1][i]; p++) {
      d[p][y[0][i] + 1] = 1;
      u[p][y[1][i]] = 1;
    }
    for (int q = y[0][i] + 1; q <= y[1][i]; q++) {
      l[x[0][i] + 1][q] = 1;
      r[x[1][i]][q] = 1;
    }
  }
  for (int(i) = 1; (i) <= (int)(3105 - 1); (i)++) {
    for (int(j) = 1; (j) <= (int)(3105 - 1); (j)++) {
      mp[i][j] += mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
      u[i][j] += u[i - 1][j];
      d[i][j] += d[i - 1][j];
      l[i][j] += l[i][j - 1];
      r[i][j] += r[i][j - 1];
    }
  }
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    for (int X = x[0][i], Y = y[0][i], len = 1;
         d[X + len][Y + 1] - d[X][Y + 1] == len &&
         l[X + 1][Y + len] - l[X + 1][Y] == len;
         len++) {
      int S = mp[X + len][Y + len] - mp[X][Y + len] - mp[X + len][Y] + mp[X][Y];
      if (S != len * len) break;
      if (u[X + len][Y + len] - u[X][Y + len] == len &&
          r[X + len][Y + len] - r[X + len][Y] == len) {
        vector<int> ans;
        for (int(j) = 0; (j) < (int)(n); (j)++) {
          if (x[0][j] >= X && x[1][j] <= X + len && y[0][j] >= Y &&
              y[1][j] <= Y + len) {
            ans.push_back(j + 1);
          }
        }
        printf("YES %d\n", ans.size());
        for (int cc : ans) printf("%d ", cc);
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
