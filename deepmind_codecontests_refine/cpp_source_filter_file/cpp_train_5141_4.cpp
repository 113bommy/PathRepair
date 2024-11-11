#include <bits/stdc++.h>
using namespace std;
int n, in[24], dp[1 << 24];
int dfs(int status, int idx) {
  if (dp[status]) return dp[status];
  if (status == 1) return 1;
  int cnt = 0, res = 100000;
  for (int i = 0; i <= 24; i++)
    if ((1 << i) & status) cnt++;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      if (in[i] + in[j] == in[idx]) {
        int v =
            dfs(status & ~(1 << idx) | (1 << (idx - 1)) | (1 << i) | (1 << j),
                idx - 1);
        res = min(res, max(cnt, v));
      }
  return dp[status] = res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", in + i);
  int ac = dfs(1 << (n - 1), n - 1);
  if (ac >= 100000)
    puts("-1");
  else
    printf("%d\n", ac);
}
