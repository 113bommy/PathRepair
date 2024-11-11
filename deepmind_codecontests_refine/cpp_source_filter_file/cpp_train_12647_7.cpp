#include <bits/stdc++.h>
using namespace std;
bool isp[(1 << 19)], vis[(1 << 19)];
vector<int> fac[(1 << 19)];
int n, x, q, a[(1 << 19)], cnt[(1 << 19)];
void init() {
  for (int i = 2; i < (1 << 19); i++) isp[i] = 1;
  for (int i = 2; i < (1 << 19); i++)
    if (isp[i]) {
      fac[i].push_back(i);
      for (int j = i + i; j < (1 << 19); j += i)
        isp[j] = 0, fac[j].push_back(i);
    }
}
int dfs(int f, int x, int cur, int s) {
  if (cur == fac[x].size()) {
    if (s != 1) {
      if (f == 1) {
        cnt[s]++;
        if (fac[cur].size() & 1)
          return cnt[s] - 1;
        else
          return -(cnt[s] - 1);
      } else {
        cnt[s]--;
        if (fac[cur].size() & 1)
          return cnt[s];
        else
          return -cnt[s];
      }
    } else
      return 0;
  }
  return dfs(f, x, cur + 1, s) + dfs(f, x, cur + 1, s * fac[x][cur]);
}
int main() {
  init();
  cin >> n >> q;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  long long res = 0, tot = 0;
  for (int i = 0; i < q; i++) {
    scanf("%d", &x);
    if (!vis[x]) {
      tot++, vis[x] = 1;
      res += dfs(1, a[x], 0, 1);
    } else {
      tot--, vis[x] = 0;
      res -= dfs(-1, a[x], 0, 1);
    }
    printf("%I64d\n", tot * (tot - 1) / 2 - res);
  }
  return 0;
}
