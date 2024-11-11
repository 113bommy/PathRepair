#include <bits/stdc++.h>
const int N = 59;
const int inf = 0x3f3f3f3f;
using namespace std;
int la, lb;
int d1[N][N][26], d2[N][N][26];
struct data {
  int x, y;
  data() {}
  data(int x, int y) : x(x), y(y) {}
};
vector<data> vt[26];
char A[N], B[N], s[N];
int dfs1(int a, int b, int k) {
  if (d1[a][b][k] + 1) return d1[a][b][k];
  if (a == b) {
    if (A[a] - 'a' == k) return d1[a][b][k] = 1;
    return d1[a][b][k] = 0;
  }
  int sz = vt[k].size();
  for (int l = 0; l < sz; l++) {
    int x = vt[k][l].x, y = vt[k][l].y;
    for (int i = a; i < b; i++)
      if (dfs1(a, i, x) && dfs1(i + 1, b, y)) return d1[a][b][k] = 1;
  }
  return d1[a][b][k] = 0;
}
int dfs2(int a, int b, int k) {
  if (d2[a][b][k] + 1) return d2[a][b][k];
  if (a == b) {
    if (B[a] - 'a' == k) return d2[a][b][k] = 1;
    return d2[a][b][k] = 0;
  }
  int sz = vt[k].size();
  for (int l = 0; l < sz; l++) {
    int x = vt[k][l].x, y = vt[k][l].y;
    for (int i = a; i < b; i++)
      if (dfs2(a, i, x) && dfs2(i + 1, b, y)) return d2[a][b][k] = 1;
  }
  return d2[a][b][k] = 0;
}
int dp[N][N];
int dfs(int a, int b) {
  if (a < 0 && b < 0)
    return 0;
  else if (a < 0)
    return inf;
  else if (b < 0)
    return inf;
  if (dp[a][b] + 1) return dp[a][b];
  int &ret = dp[a][b] = inf;
  for (int i = 0; i <= a; i++)
    for (int j = 0; j <= b; j++)
      for (int k = 0; k < 26; k++)
        if (dfs1(i, a, k) && dfs2(j, b, k))
          ret = min(ret, dfs(i - 1, j - 1) + 1);
  return ret;
}
int main() {
  scanf("%s%s", A, B);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    vt[s[0] - 'a'].push_back(data(s[3] - 'a', s[4] - 'a'));
  }
  la = strlen(A);
  lb = strlen(B);
  memset(d1, -1, sizeof(d1));
  memset(d2, -1, sizeof(d2));
  memset(dp, -1, sizeof(dp));
  int ret = dfs(la - 1, lb - 1);
  if (ret == inf) ret = -1;
  printf("%d\n", ret);
  return 0;
}
