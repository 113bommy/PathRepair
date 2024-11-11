#include <bits/stdc++.h>
using namespace std;
struct node {
  int t, d, p, idd;
} e[104];
bool cmp(node a, node b) { return a.d < b.d; }
int dp[104][2004];
int bg[104][204];
int n;
int ans;
int lu[104];
void dfs(int cg, int shu) {
  if (cg == 0) return;
  if (bg[cg][shu]) {
    lu[ans++] = e[cg].idd;
    dfs(cg - 1, shu - e[cg].t);
  } else {
    dfs(cg - 1, shu);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", &e[i].t, &e[i].d, &e[i].p), e[i].idd = i;
  sort(e + 1, e + 1 + n, cmp);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= e[n].d; j++) {
      if (j > e[i].t && j <= e[i].d) {
        if (dp[i - 1][j] < dp[i - 1][j - e[i].t] + e[i].p) {
          dp[i][j] = dp[i - 1][j - e[i].t] + e[i].p;
          bg[i][j] = 1;
        } else
          dp[i][j] = dp[i - 1][j];
      } else
        dp[i][j] = dp[i - 1][j];
    }
  int da = 0;
  int wei = 0;
  for (int i = 1; i <= e[n].d; i++) {
    if (da < dp[n][i]) {
      da = dp[n][i];
      wei = i;
    }
  }
  printf("%d\n", da);
  dfs(n, wei);
  printf("%d\n", ans);
  for (int i = ans - 1; i >= 0; i--) {
    printf("%d%c", lu[i], i == ans ? '\n' : ' ');
  }
}
