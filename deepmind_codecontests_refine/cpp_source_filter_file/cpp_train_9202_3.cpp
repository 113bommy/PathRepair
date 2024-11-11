#include <bits/stdc++.h>
using namespace std;
char mark[3][10010];
const int MOD = 1e9 + 7;
int dp[2][8][2];
int n, cur, nex, val, s, cen;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
void dfs(int ns, int pos, int ed) {
  if (pos >= 3) {
    add(dp[nex][ns][ed], val);
    return;
  }
  if (!(s & (1 << pos))) {
    dfs(ns, pos + 1, ed);
    if (pos < 2 && !(s & (1 << pos)) && (ns & (1 << (pos + 1))) &&
        (ns & (1 << pos))) {
      if (ed == 0) {
        if ((pos && mark[pos][cen] == 'O') ||
            (!pos && mark[pos + 2][cen] == 'O')) {
          dfs(ns ^ (3 << pos), pos + 2, 1);
        } else
          dfs(ns ^ (3 << pos), pos + 2, 0);
      } else {
        dfs(ns ^ (3 << pos), pos + 2, 1);
      }
    }
  } else {
    if (ns & (1 << pos)) {
      if (ed == 0) {
        if ((cen > 1 && mark[pos][cen - 2] == 'O') ||
            (cen < n - 1 && mark[pos][cen + 1] == 'O')) {
          dfs(ns ^ (1 << pos), pos + 1, 1);
        } else
          dfs(ns ^ (1 << pos), pos + 1, 0);
      } else {
        dfs(ns ^ (1 << pos), pos + 1, 1);
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; i++) scanf("%s", mark[i]);
  dp[0][0][0] = 1;
  cur = 0, nex = 1;
  for (int i = 0; i < n; i++) {
    cen = i;
    for (s = 0; s < 8; s++) {
      int ns = 0;
      for (int j = 0; j < 3; j++)
        if (mark[j][i] == '.') ns ^= (1 << j);
      for (int k = 0; k < 2; k++)
        if (dp[cur][s][k]) {
          val = dp[cur][s][k];
          dfs(ns, 0, k);
          dp[cur][s][k] = 0;
        }
    }
    cur = nex, nex = !cur;
  }
  printf("%d\n", dp[cur][0][1]);
  return 0;
}
