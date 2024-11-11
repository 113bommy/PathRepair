#include <bits/stdc++.h>
using namespace std;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const int MAXN = 21;
const int BITMASKLEN = 1 << 20;
int memo[BITMASKLEN];
int cost[MAXN][MAXN];
char str[MAXN][MAXN];
int s[MAXN][MAXN];
int c[MAXN][MAXN];
int N, M;
int main() {
  scanf("%d", &N);
  scanf("%d", &M);
  for (int i = 0; i < N; i++) scanf("%s", str[i]);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf("%d", &cost[i][j]);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int mx = -(int)1e9;
      c[i][j] = 0;
      s[i][j] = 0;
      for (int k = 0; k < N; k++) {
        if (str[i][j] == str[k][j]) {
          s[i][j] += (1 << k);
          c[i][j] += cost[k][j];
          mx = ((mx) > (cost[k][j]) ? (mx) : (cost[k][j]));
        }
      }
      c[i][j] -= mx;
    }
  }
  int powerset = (1 << N);
  memo[0] = 0;
  for (int mask = 1; mask < powerset; mask++) {
    int lowbit = -1;
    for (int i = 0; i < N; i++) {
      if (((mask >> i) & 1)) {
        lowbit = i;
        break;
      }
    }
    memo[mask] = (int)1e9;
    for (int i = 0; i < M; i++) {
      memo[mask] =
          ((memo[mask]) < (memo[mask & (mask ^ s[lowbit][i])] + c[lowbit][i])
               ? (memo[mask])
               : (memo[mask & (mask ^ s[lowbit][i])] + c[lowbit][i]));
      memo[mask] =
          ((memo[mask]) < (memo[mask ^ (1 << lowbit)] + cost[lowbit][i])
               ? (memo[mask])
               : (memo[mask ^ (1 << lowbit)] + cost[lowbit][i]));
    }
  }
  printf("%d\n", memo[powerset - 1]);
  return 0;
}
