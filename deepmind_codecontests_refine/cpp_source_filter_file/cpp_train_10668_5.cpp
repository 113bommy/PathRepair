#include <bits/stdc++.h>
using namespace std;
map<int, long long> mat[31];
long long n, k, sum, ans, a[31], jc[31];
void dfs(int x, int y, int t, long long s) {
  if ((t > k) || (s > sum)) return;
  if (x > y) {
    if (y < n)
      mat[t][s]++;
    else
      for (int i = 0; i + t <= k; i++) ans += mat[i][sum - s];
    return;
  }
  dfs(x + 1, y, t, s);
  dfs(x + 1, y, t, s + a[x]);
  if (a[x] < 19) dfs(x + 1, y, t + 1, s + jc[a[x]]);
}
int main() {
  scanf("%lld%lld%lld", &n, &k, &sum);
  jc[0] = 1;
  for (int i = 1; i <= 18; i++) jc[i] = jc[i - 1] * i;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  if (n == 1) {
    printf("%d", ((a[1] == sum) || (!k) && (a[1] < 19) && (jc[a[1]] == sum)));
    return 0;
  }
  dfs(1, (n + 1) / 2, 0, 0);
  dfs((n + 1) / 2 + 1, n, 0, 0);
  printf("%lld", ans);
}
