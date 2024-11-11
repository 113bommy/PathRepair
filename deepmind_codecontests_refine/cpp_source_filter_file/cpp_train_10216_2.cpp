#include <bits/stdc++.h>
using namespace std;
int n, k, len, ans, a[100005], f[100005][105], pre[105], sum[100005];
void add(int &x, int y) { x = (x + y > 998244353) ? x + y - 998244353 : x + y; }
int main() {
  scanf("%d%d%d", &n, &k, &len);
  for (register int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  memset(pre, -1, sizeof(pre));
  sum[0] = 1;
  for (register int i = 1; i <= n; ++i) {
    if (a[i] != -1) {
      f[i][a[i]] = (i == 1) ? 1 : sum[i - 1];
      for (register int j = 1; j <= k; ++j) {
        if (j != a[i])
          pre[j] = -1;
        else if (pre[j] == -1)
          pre[j] = i;
      }
      if (pre[a[i]] != -1 && i - pre[a[i]] + 1 >= len)
        add(f[i][a[i]], 998244353 - sum[i - len]),
            add(f[i][a[i]], f[i - len][a[i]]);
    } else {
      for (register int j = 1; j <= k; ++j) {
        if (pre[j] == -1) pre[j] = i;
        f[i][j] = (i == 1) ? 1 : sum[i - 1];
      }
      for (register int j = 1; j <= k; ++j)
        if (i - pre[j] + 1 >= len)
          add(f[i][j], 998244353 - sum[i - len]), add(f[i][j], f[i - len][j]);
    }
    for (register int j = 1; j <= k; j++) add(sum[i], f[i][j]);
  }
  printf("%d\n", sum[n]);
}
