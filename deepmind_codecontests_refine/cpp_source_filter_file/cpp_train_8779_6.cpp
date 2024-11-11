#include <bits/stdc++.h>
using namespace std;
char in[501][501];
array<int, 3> dp[501][26][26];
array<int, 3> table[2][2][26][26];
const int inf = 1 << 29;
void f(array<int, 3> s[26][26], array<int, 3> t[26][26], int s0, int e0, int s1,
       int e1) {
  int d0 = abs(e0 - s0) / (e0 - s0);
  int d1 = abs(e1 - s1) / (e1 - s1);
  for (int i = s0;; i += d0) {
    t[i][s1] = {{s[i][s1][0], i, s1}};
    for (int j = s1 + d1;; j += d1) {
      t[i][j] = min(t[i][j - d1], {{s[i][j][0], i, j}});
      if (j == e1) {
        break;
      }
    }
    if (i == e0) {
      break;
    }
  }
  for (int i = s0 + d0;; i += d0) {
    for (int j = s1;; j += d1) {
      t[i][j] = min(t[i - d0][j], t[i][j]);
      if (j == e1) {
        break;
      }
    }
    if (i == e0) {
      break;
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", in[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int a = 0; a < 26; a++) {
      for (int b = 0; b < 26; b++) {
        if (a == b) {
          dp[i][a][b] = {{inf, 0, 0}};
          continue;
        }
        array<int, 3> r = {{inf, 0, 0}};
        if (i < n - 1) {
          for (int p = 0; p < 2; p++) {
            for (int q = 0; q < 2; q++) {
              int u = a - 1 + 2 * p;
              int v = b - 1 + 2 * q;
              if (0 <= u && u < 26 && 0 <= v && v < 26) {
                r = min(r, table[p][q][u][v]);
              }
            }
          }
        } else {
          r[0] = 0;
        }
        int v = 0;
        for (int j = 0; j < m; j++) {
          if (j % 2) {
            if (in[i][j] - 'a' != a) {
              v++;
            }
          } else {
            if (in[i][j] - 'a' != b) {
              v++;
            }
          }
        }
        r[0] += v;
        dp[i][a][b] = r;
      }
    }
    f(dp[i], table[0][0], 0, 25, 0, 25);
    f(dp[i], table[0][1], 0, 25, 25, 0);
    f(dp[i], table[1][0], 25, 0, 0, 25);
    f(dp[i], table[1][1], 25, 0, 25, 0);
  }
  int v = inf;
  int ma;
  int mb;
  for (int a = 0; a < 26; a++) {
    for (int b = 0; b < 26; b++) {
      if (dp[0][a][b][0] < v) {
        ma = a;
        mb = b;
        v = dp[0][a][b][0];
      }
    }
  }
  printf("%d\n", v);
  for (int i = 0; i < n; i++) {
    char a = 'a' + ma;
    char b = 'a' + mb;
    for (int j = 0; j < m; j++) {
      printf("%c", j % 2 == 0 ? a : b);
    }
    puts("");
    int na = dp[i][ma][mb][1];
    int nb = dp[i][ma][mb][2];
    ma = na;
    mb = nb;
  }
  return 0;
}
