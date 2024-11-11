#include <bits/stdc++.h>
using namespace std;
long long a[9], aa[9];
int c[9], cc[9];
int n;
int ans;
void dfs(int u, int cnt, int self) {
  if (u == n) {
    ans = min(ans, cnt + (self > 1));
    return;
  }
  dfs(u + 1, cnt + cc[u] + (c[u] != 1), self + 1);
  for (int i = u + 1; i < n; i++)
    if (aa[i] % a[u] == 0) {
      aa[i] /= a[u];
      cc[i] -= c[u];
      dfs(u + 1, cnt + cc[u] + (c[u] != 1), self);
      aa[i] *= a[u];
      cc[i] += c[u];
    }
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    long long x = a[i];
    long long m = sqrt(x + 0.5);
    for (j = 2; j <= m; j++)
      while (x % j == 0) {
        c[i]++;
        x /= j;
      }
    if (x > 1) c[i]++;
    aa[i] = a[i];
    cc[i] = c[i];
  }
  ans = 1e9;
  dfs(0, 0, 0);
  printf("%d\n", ans);
  return 0;
}
