#include <bits/stdc++.h>
int n, p, M, vis[200005], G[200005];
long long min = 0, max = 1e14;
long long a[200005];
std::stack<int> q;
int cmp(long long a, long long b) { return a > b; }
int wrap(long long x) { return (x % p + p) % p; }
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  std::sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    min = std::max(min, 1 + a[i] - n - i);
    if ((n - i + 1) % p == 0) max = std::min(max, a[i]);
    G[i] = wrap(i - 1 + a[i] - n);
  }
  int pt = 1;
  for (long long x = max; x >= min; --x) {
    while (pt < n && a[pt + 1] >= x) {
      pt++;
      vis[G[pt]] = 1;
    }
    if (!vis[x % p]) q.push(x);
  }
  printf("%d\n", q.size());
  while (!q.empty()) {
    printf("%d ", q.top());
    q.pop();
  }
  return 0;
}
