#include <bits/stdc++.h>
using namespace std;
long long f[505][505], vis[505][505], n;
long long dfs(long long n, long long k) {
  if (!k) return 1;
  if (n == 1) {
    return k == 1;
  }
  if (vis[n][k]) return f[n][k];
  vis[n][k] = 1;
  for (long long i = 0; i <= k - 1; i++) {
    f[n][k] = (f[n][k] + dfs(n - 1, i) * dfs(n - 1, k - 1 - i)) % 1000000007;
  }
  for (long long i = 0; i <= k; i++) {
    f[n][k] =
        (f[n][k] + dfs(n - 1, i) * dfs(n - 1, k - i) % 1000000007 * 2 * k) %
        1000000007;
  }
  for (long long i = 0; i <= k; i++) {
    f[n][k] = (f[n][k] + dfs(n - 1, i) * dfs(n - 1, k - i)) % 1000000007;
  }
  for (long long i = 0; i <= k + 1; i++) {
    f[n][k] = (f[n][i] + dfs(n - 1, i) * dfs(n - 1, k - i + 1) % 1000000007 *
                             (k + 1) % 1000000007 * k) %
              1000000007;
  }
  return f[n][k];
}
int main() {
  scanf("%lld", &n);
  printf("%lld", dfs(n, 1));
}
