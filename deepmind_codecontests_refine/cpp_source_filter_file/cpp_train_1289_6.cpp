#include <bits/stdc++.h>
using namespace std;
int n, num_fa;
long long total, ans, decre;
int cnt[5005][5005], dis[5005][5005], a[5005], b[5005], c;
vector<int> r[5005];
int dfs_n(int u, int fa) {
  int ret = 1LL;
  for (long long k = 0LL; k < r[u].size(); k++) {
    int next = r[u][k];
    if (next == fa) {
      continue;
    }
    ret += dfs_n(next, u);
  }
  return ret;
}
void dfs(int u, int fa, long long sum) {
  decre = min(decre, sum);
  for (long long k = 0; k < r[u].size(); k++) {
    long long before = 0LL, now = 0LL;
    int next = r[u][k];
    if (next == fa) {
      continue;
    }
    before = (long long)cnt[u][next] * dis[u][next] * cnt[next][u];
    now = (long long)(cnt[u][next] - num_fa) * dis[u][next] *
          (cnt[next][u] + num_fa);
    dfs(next, u, sum - before + now);
  }
}
int main() {
  int i, j;
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) r[i].clear();
    memset(cnt, 0, sizeof(cnt));
    memset(dis, 0, sizeof(dis));
    for (i = 1; i < n; i++) {
      scanf("%I64d%I64d%I64d", &a[i], &b[i], &c);
      r[a[i]].push_back(b[i]);
      r[b[i]].push_back(a[i]);
      dis[a[i]][b[i]] = dis[b[i]][a[i]] = c;
    }
    total = 0LL;
    for (i = 1; i < n; i++) {
      cnt[a[i]][b[i]] = dfs_n(a[i], b[i]);
      cnt[b[i]][a[i]] = n - cnt[a[i]][b[i]];
      total += (long long)cnt[a[i]][b[i]] * dis[a[i]][b[i]] * cnt[b[i]][a[i]];
    }
    ans = 1000000000000000LL;
    for (i = 1; i < n; i++) {
      decre = 0LL;
      num_fa = cnt[b[i]][a[i]];
      dfs(a[i], b[i], 0);
      long long tmp1 = decre;
      decre = 0LL;
      num_fa = cnt[a[i]][b[i]];
      dfs(b[i], a[i], 0);
      long long tmp2 = decre;
      ans = min(ans, total + tmp1 + tmp2);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
