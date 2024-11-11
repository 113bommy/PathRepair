#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, k;
int mx, cnt;
int a[N], b[N], vis[N];
long long ans;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  mx = cnt = 0;
  ans = -1;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    vis[a[i]] = 1;
  }
  for (int i = 1; i <= k; i++) scanf("%d", &b[i]);
  sort(a + 1, a + m + 1);
  if (a[1] == 0) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    if (a[i] == a[i - 1] + 1)
      cnt++;
    else
      cnt = 1;
    mx = max(mx, cnt);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      a[i] = a[i - 1];
    else
      a[i] = i;
  }
  for (int i = k; i >= 1; i--) {
    if (i <= mx) break;
    if ((n + i - 1) / i * b[i] >= ans && ans != -1) continue;
    int l = 0;
    long long sum = 0;
    while (l < n) {
      sum += b[i];
      if (l + i >= n) break;
      l = a[l + i];
    }
    if (ans == -1) ans = sum;
    ans = min(ans, sum);
  }
  printf("%lld\n", ans);
}
