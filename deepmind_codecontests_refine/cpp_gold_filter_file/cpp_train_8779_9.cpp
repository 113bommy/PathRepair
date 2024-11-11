#include <bits/stdc++.h>
using namespace std;
int N, M;
char cs[610][610];
int dp[610][26][26];
int pre[610][26][26];
int w[610][26][26];
int ci[26][2];
char ans[610][610];
typedef struct node {
  int v;
  int x;
  int y;
} node;
bool cmp(const node &a, const node &b) { return a.v < b.v; }
int main() {
  int i, j, k, p;
  scanf("%d%d", &N, &M);
  for (i = (0); i < (N); i++) scanf("%s", cs[i]);
  memset(w, 0x6f, sizeof w);
  for (i = (0); i < (N); i++) {
    memset((ci), 0, sizeof(ci));
    ;
    for (j = (0); j < (M); j++)
      if (j % 2 == 0)
        ci[cs[i][j] - 'a'][0]++;
      else
        ci[cs[i][j] - 'a'][1]++;
    for (j = (0); j < (26); j++)
      for (k = (0); k < (26); k++)
        if (j == k)
          continue;
        else {
          w[i][j][k] = M - (ci[j][0] + ci[k][1]);
        }
  }
  memset(dp, 0x6f, sizeof dp);
  for (i = (0); i < (26); i++)
    for (j = (0); j < (26); j++) dp[0][i][j] = w[0][i][j];
  for (i = (1); i < (N); i++) {
    vector<node> tmp;
    for (j = (0); j < (26); j++)
      for (k = (0); k < (26); k++) {
        node t;
        t.v = dp[i - 1][j][k], t.x = j, t.y = k;
        tmp.push_back(t);
      }
    sort(tmp.begin(), tmp.end(), cmp);
    for (j = (0); j < (26); j++)
      for (k = (0); k < (26); k++) {
        if (j == k) continue;
        for (p = (0); p < (60); p++) {
          node now = tmp[p];
          if (j == now.x || k == now.y) continue;
          if (dp[i][j][k] > now.v + w[i][j][k]) {
            dp[i][j][k] = now.v + w[i][j][k];
            pre[i][j][k] = now.x * 26 + now.y;
          }
        }
      }
  }
  int minv = 1000000001;
  int mini = -1;
  for (i = (0); i < (26); i++)
    for (j = (0); j < (26); j++)
      if (dp[N - 1][i][j] < minv) minv = dp[N - 1][i][j], mini = i * 26 + j;
  printf("%d\n", minv);
  int now = mini;
  for (i = N - 1; i >= 0; i--) {
    int c1 = now / 26, c2 = now % 26;
    for (j = (0); j < (M); j++)
      if (j % 2 == 0)
        ans[i][j] = c1 + 'a';
      else
        ans[i][j] = c2 + 'a';
    ans[i][M] = 0;
    now = pre[i][c1][c2];
  }
  for (i = (0); i < (N); i++) printf("%s\n", ans[i]);
  return 0;
}
