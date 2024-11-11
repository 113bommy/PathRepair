#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 1 << 6 | 1;
const int inf = 0x3f3f3f3f;
const long long oo = 0x3f3f3f3f3f3f3f3fll;
int n, m;
int dp[41][N][N], w[N];
int dfs(int a, int nw, int sp) {
  if (a == n + 1) return (sp == 0) ? 0 : inf;
  int &ret = dp[a][nw][sp];
  if (ret + 1) return ret;
  ret = inf;
  for (int i = 0; i < (1 << m); i++) {
    int nx = sp | i;
    int ns = nx | (nx << 1) | (nx >> 1) | nw;
    ns = (~ns) & ((1 << m) - 1);
    ret = min(ret, dfs(a + 1, nx, ns) + w[nx]);
  }
  return ret;
}
int main() {
  for (int i = 1; i < N; i++)
    if ((i & (-i)) != i)
      w[i] = w[i ^ (i & (-i))] + 1;
    else
      w[i] = 1;
  scanf("%d%d", &n, &m);
  if (n < m) swap(m, n);
  memset(dp, -1, sizeof(dp));
  cout << n * m - dfs(1, 0, 0) << endl;
  return 0;
}
