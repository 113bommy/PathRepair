#include <bits/stdc++.h>
using namespace std;
int memo[30010][1600];
int n, d;
int p[30010];
int base;
int dfs(int cur, int pre) {
  if (cur > 30000) return 0;
  if (memo[cur][pre + base] != -1) return memo[cur][pre + base];
  int ret = p[cur];
  int plus = 0;
  for (int i = -1; i <= 1; i++) {
    int npre = pre + i;
    if (npre <= 0) continue;
    if (cur + npre > 30000) continue;
    plus = max(plus, dfs(cur + npre, npre));
  }
  ret += plus;
  return memo[cur][pre + base] = ret;
}
int main(void) {
  cin >> n >> d;
  base = 800 - d;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    p[x]++;
  }
  for (int i = 0; i < 1600; i++)
    for (int j = 0; j < 30010; j++) {
      memo[i][j] = -1;
    }
  cout << dfs(d, d) << endl;
  return 0;
}
