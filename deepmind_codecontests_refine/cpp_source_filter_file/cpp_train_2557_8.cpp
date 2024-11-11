#include <bits/stdc++.h>
using namespace std;
vector<long long> g[1000000];
long long ans[1000000];
long long vis[1000000];
long long n, m, k, sum = 0;
int dfs(long long x) {
  vis[x] = true;
  long long ret = 0;
  for (long long i = 0; i < g[x].size(); i++) {
    long long a = g[x][i];
    if (!vis[a]) ret += dfs(a) + 1;
  }
  if (!ret)
    return 1;
  else
    return ret;
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  for (long long i = 0; i < m; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (long long i = 0; i < n; i++) {
    if (!vis[i]) {
      ans[sum] = dfs(i);
      if (ans[sum] > k) ans[sum] = k;
      sum++;
    }
  }
  long long h = 0;
  for (long long i = 0; i < sum; i++) h += ans[i];
  sum--;
  if (k != 1) {
    if (h / 2 >= sum)
      printf("%d\n", 0);
    else
      printf("%d\n", sum - h / 2);
  } else {
    if (sum - 2 < 0)
      printf("%d\n", 0);
    else
      printf("%d\n", sum - 1);
  }
  return 0;
}
