#include <bits/stdc++.h>
const int maxn = 0x3f3f3f3f;
const double EI =
    2.71828182845904523536028747135266249775724709369995957496696762772407663035354594571382178525166427;
const double PI = 3.141592653589793238462643383279;
using namespace std;
struct s {
  int a, b;
};
int c[6][6][210][210];
vector<s> d[6][6][210][210];
int dir[6][2] = {3, 0, 3, 1, 3, 2, 2, 3, 1, 3, 0, 3};
int a, b;
inline void init(void) {
  int i, j, k, l, r, tmp, o;
  memset(c, 0, sizeof(c));
  c[0][0][0][0] = 1;
  for (i = 0; i <= 4; i++) {
    for (l = 0; l <= i; l++) {
      r = i - l;
      if (max(l, r) >= 3 || l + r > 5) {
        continue;
      }
      for (j = 0; j <= 200; j++) {
        for (k = 0; k <= 200; k++) {
          if (!c[l][r][j][k]) {
            continue;
          }
          tmp = (i == 4 ? 15 : 25);
          for (o = tmp; o <= 200; o++) {
            if (o + j <= 200 && o + k - 2 <= 200 &&
                !c[l + 1][r][o + j][o + k - 2]) {
              c[l + 1][r][o + j][o + k - 2] = 1;
              d[l + 1][r][o + j][o + k - 2] = d[l][r][j][k];
              d[l + 1][r][o + j][o + k - 2].push_back({o, o - 2});
            }
            if (o + j - 2 <= 200 && o + k <= 200 &&
                !c[l][r + 1][o + j - 2][o + k]) {
              c[l][r + 1][o + j - 2][o + k] = 1;
              d[l][r + 1][o + j - 2][o + k] = d[l][r][j][k];
              d[l][r + 1][o + j - 2][o + k].push_back({o - 2, o});
            }
          }
          for (o = 0; o <= tmp - 2; o++) {
            if (k + o <= 200 && j + tmp <= 200 &&
                !c[l + 1][r][j + tmp][k + o]) {
              c[l + 1][r][j + tmp][k + o] = 1;
              d[l + 1][r][j + tmp][k + o] = d[l][r][j][k];
              d[l + 1][r][j + tmp][k + o].push_back({tmp, o});
            }
            if (j + o <= 200 && k + tmp <= 200 &&
                !c[l][r + 1][j + o][k + tmp]) {
              c[l][r + 1][j + o][k + tmp] = 1;
              d[l][r + 1][j + o][k + tmp] = d[l][r][j][k];
              d[l][r + 1][j + o][k + tmp].push_back({o, tmp});
            }
          }
        }
      }
    }
  }
}
inline void solve(int l, int r) {
  int i, si;
  printf("%d:%d\n", l, r);
  si = d[l][r][a][b].size();
  for (i = 0; i < si; i++) {
    printf("%d:%d", d[l][r][a][b][i].a, d[l][r][a][b][i].b);
    i == si - 1 ? printf("\n") : printf(" ");
  }
}
int main(void) {
  init();
  int n, i;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &a, &b);
    for (i = 0; i < 6; i++) {
      if (c[dir[i][0]][dir[i][1]][a][b]) {
        solve(dir[i][0], dir[i][1]);
        break;
      }
    }
    if (i == 6) {
      printf("Impossible\n");
    }
  }
  return 0;
}
