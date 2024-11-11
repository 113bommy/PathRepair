#include <bits/stdc++.h>
using namespace std;
int n, q;
int ara[3 * 100010], tmm, lst[20][3 * 100010], dp[3 * 100010][20];
bool vis[3 * 100010];
void input() {
  int i, j;
  scanf("%d %d", &n, &q);
  for (i = 0; i < n; i++) {
    scanf("%d", &ara[i]);
  }
}
int F(int pos, int bit) {
  int i, j, ret = INT_MAX;
  if (pos == n) {
    return n;
  }
  if ((ara[pos] & (1 << bit))) {
    return pos;
  }
  if (dp[pos][bit] != -1) {
    return dp[pos][bit];
  }
  for (i = 0; i <= 20; i++) {
    if ((ara[pos] & (1 << i))) {
      ret = min(ret, F(lst[i][pos + 1], bit));
    }
  }
  return dp[pos][bit] = ret;
}
void solve() {
  int i, j;
  for (i = 0; i <= 20; i++) {
    for (j = n - 1, lst[i][n] = n; j >= 0; j--) {
      if ((ara[j] & (1 << i))) {
        lst[i][j] = j;
      } else {
        lst[i][j] = lst[i][j + 1];
      }
    }
  }
  for (i = 0, memset(dp, -1, sizeof(dp)); i < n; i++) {
    for (j = 0; j < 20; j++) {
      dp[i][j] = F(i, j);
    }
  }
  for (i = 0; i < q; i++) {
    int u, v;
    scanf("%d %d", &u, &v), u--, v--;
    for (j = 0; j <= 20; j++) {
      if ((ara[v] & (1 << j))) {
        if (dp[u][j] <= v) {
          break;
        }
      }
    }
    if (j < 21) {
      printf("%s", "Shi\n");
    } else {
      printf("%s", "Fou\n");
    }
  }
}
int main() {
  input();
  solve();
}
