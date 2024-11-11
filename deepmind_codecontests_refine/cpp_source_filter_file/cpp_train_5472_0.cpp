#include <bits/stdc++.h>
using namespace std;
const int N = 3e7 + 10;
const int INF = 0x3f3f3f3f;
int sum[4010], f[N];
bool vis[N];
int main() {
  auto get_hash = [&](int a, int b, int c, int d) {
    return ((((a * 4000ll) + b) * 100 + c) * 2 + d) % 29999999;
  };
  auto get_sum = [&](int l, int r) { return sum[r] - sum[l - 1]; };
  function<int(int, int, int, int)> dfs = [&](int l, int r, int k, int op) {
    if (r - l + 1 < k) return 0;
    if (r - l + 1 == k) return get_sum(l, r) * (op ? -1 : 1);
    int str = get_hash(l, r, k, op);
    if (!vis[str]) return f[str];
    vis[str] = true;
    if (op) {
      int ans = dfs(l, r - k, k, 0) - get_sum(r - k + 1, r);
      if (r - k >= l)
        ans = min(ans, dfs(l, r - k - 1, k + 1, 0) - get_sum(r - k, r));
      return f[str] = ans;
    } else {
      int ans = dfs(l + k, r, k, 1) + get_sum(l, l + k - 1);
      if (l + k <= r)
        ans = max(ans, dfs(l + k + 1, r, k + 1, 1) + get_sum(l, l + k));
      return f[str] = ans;
    }
  };
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &sum[i]), sum[i] += sum[i - 1];
  cout << dfs(1, n, 1, 0);
  return 0;
}
