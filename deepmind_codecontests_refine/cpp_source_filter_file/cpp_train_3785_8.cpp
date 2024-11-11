#include <bits/stdc++.h>
using namespace std;
int n, m, cnt[125];
long long ans;
void dfs(int u, bitset<125> mask, long long res) {
  if (u > m >> 1) {
    ans = (ans + res) % 1000000007;
    return;
  }
  dfs(u + 1, mask, res);
  if (cnt[u] && !mask.test(u))
    dfs(u + 1,
        mask | ((mask << u) | (mask >> m - u)) |
            ((mask << m - u) | (mask >> m - m - u)),
        res * cnt[u] % 1000000007);
}
int main() {
  scanf("%*d%d%d", &m, &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    x %= m;
    if (x > m >> 1) x = m - x;
    cnt[x]++;
  }
  dfs(0, bitset<125>(1), 1);
  printf("%lld\n", ans);
  return 0;
}
