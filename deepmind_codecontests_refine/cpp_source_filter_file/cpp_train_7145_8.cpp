#include <bits/stdc++.h>
using namespace std;
long long c[60];
long long dfs(int m, int n) {
  if (n == 0) return m * c[0];
  if ((1LL << n) >= m) return min(c[n], dfs(m, n - 1));
  return (m / (1 << n)) * c[n] + dfs(m % (1 << n), n - 1);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%lld", c + i);
  long long now = c[0];
  for (int i = 0; i < n; i++) {
    now = c[i] = min(c[i], now * 2);
  }
  printf("%lld\n", dfs(m, n - 1));
}
