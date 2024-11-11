#include <bits/stdc++.h>
const int inf = 0x7FFFFFFF;
using namespace std;
const int mod = 1e9 + 7;
int N;
int a[101], dp[101][101];
void add(int &x, int val) {
  x += val;
  if (x >= mod) x -= mod;
}
int C[101][101];
void pre() {
  C[0][0] = 1;
  for (int i = 1; i < 101; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      add(C[i][j], (C[i - 1][j - 1] + C[i - 1][j]) % mod);
    }
  }
}
int dfs(int pos, int left) {
  if (pos > 9) return left == 0;
  int &ret = dp[pos][left];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = max(0, a[pos]); i <= left; i++) {
    add(ret, dfs(pos + 1, left - i) * C[left][i] % mod);
  }
  return ret;
}
int main() {
  pre();
  scanf("%d", &N);
  for (int i = 0; i < 10; i++) scanf("%d", a + i);
  int ans = 0;
  for (int len = 1; len <= N; len++) {
    for (int i = 1; i <= 9; i++) {
      a[i]--;
      memset(dp, -1, sizeof(dp));
      add(ans, dfs(0, len - 1));
      a[i]++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
