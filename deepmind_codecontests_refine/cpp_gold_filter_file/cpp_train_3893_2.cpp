#include <bits/stdc++.h>
using namespace std;
const int NS = 1111;
const int MOD = 1000000007;
int n, m, k;
int v[11], u[NS];
int s[NS][NS], a[NS][NS];
int one_num(int z) {
  int cnt = 0;
  for (; z > 0; z = z & (z - 1)) cnt++;
  return cnt;
}
long long dfs(int x, int y) {
  if (y > m) return dfs(x + 1, 1);
  if (x > n) return 1;
  int cur = s[x - 1][y] | s[x][y - 1];
  if (n + m - x - y >= k - __builtin_popcount(cur)) return 0;
  long long ans = 0, tmp = -1;
  for (int t = ((~cur) & ((1 << k) - 1)); t > 0; t -= t & (-t)) {
    int i = u[t & (-t)];
    if (!(cur & (1 << (i))) && (a[x][y] == i + 1 || !a[x][y])) {
      s[x][y] = cur | (1 << (i));
      if (v[i + 1])
        v[i + 1]++, ans += dfs(x, y + 1);
      else {
        v[i + 1]++;
        if (tmp == -1) tmp = dfs(x, y + 1);
        ans += tmp;
      }
      v[i + 1]--;
      ans %= MOD;
    }
  }
  return ans;
}
int main() {
  while (~scanf("%d%d%d", &n, &m, &k)) {
    memset(v, 0, sizeof(v));
    for (int i = 0; i <= k; i++) u[1 << i] = i;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        v[a[i][j]]++;
      }
    if ((n + m - 1) > k) {
      printf("0\n");
      continue;
    }
    long long ans = dfs(1, 1);
    printf("%I64d\n", ans);
  }
  return 0;
}
