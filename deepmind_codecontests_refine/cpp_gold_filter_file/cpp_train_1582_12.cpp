#include <bits/stdc++.h>
using namespace std;
const int N = 20, S = (1 << 16) + 10, V = 2048;
bitset<V> dp[S];
int a[N], id[N];
priority_queue<pair<int, int> > q;
int main() {
  int n, k, v = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), v += a[i];
  dp[0][0] = 1;
  int u = (1 << n) - 1;
  for (int s = 0; s <= u; ++s) {
    for (int i = v; i >= 1; --i)
      if (i % k == 0 && dp[s][i]) dp[s][i / k] = 1;
    for (int i = 1; i <= n; ++i)
      if (!(s >> i - 1 & 1)) dp[s | (1 << i - 1)] |= dp[s] << a[i];
  }
  puts(dp[u][1] ? "YES" : "NO");
  if (!dp[u][1]) return 0;
  int c = 1e9;
  for (int s = u, j = 1; s;)
    for (int t = j, ok = 0; !ok; t *= k, c -= !ok)
      for (int i = 1; i <= n; ++i) {
        if (t < a[i]) continue;
        if ((s >> i - 1 & 1) && dp[s ^ (1 << i - 1)][t - a[i]]) {
          id[i] = c, s ^= 1 << i - 1, j = t - a[i], ok = 1;
          break;
        }
      }
  for (int i = 1; i <= n; ++i) q.push(make_pair(-(id[i] - c), a[i]));
  while (q.size() > 1) {
    pair<int, int> x = q.top();
    q.pop();
    pair<int, int> y = q.top();
    q.pop();
    printf("%d %d\n", x.second, y.second);
    int v = x.second + y.second, u = 0;
    while (v % k == 0) v /= k, ++u;
    q.push(make_pair(-(-x.first + u), v));
  }
  return 0;
}
