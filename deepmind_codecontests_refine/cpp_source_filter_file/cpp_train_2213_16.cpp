#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], vis[N][2], vid, n, m;
long long dp[N][2], x, k, y;
long long solve(int len, bool one) {
  if (len < 0) return 1e9;
  if (len == 0) return 0;
  long long &ret = dp[len][one];
  if (vis[len][one] == vid) return ret;
  vis[len][one] = vid;
  ret = 1e9;
  if (len >= k) ret = min(ret, solve(len - k, one) + x);
  if (len > 1 or (len == 1 and one)) ret = min(ret, solve(len - 1, one) + y);
  return ret;
}
int main() {
  ++vid;
  scanf("%d%d%lld%lld%lld", &n, &m, &x, &k, &y);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) scanf("%d", b + i);
  int ind = 0;
  vector<int> pos, val;
  pos.emplace_back(-1);
  val.emplace_back(0);
  for (int i = 0; i < n and ind < m; i++)
    if (b[ind] == a[i]) pos.emplace_back(i), val.emplace_back(b[ind++]);
  pos.emplace_back(n);
  val.emplace_back(0);
  if (ind != m) return puts("-1"), 0;
  long long ans = 0;
  for (int i = 1; i < pos.size(); i++) {
    int mx = 0, l = pos[i - 1] + 1, r = pos[i], mxB = 0;
    for (int j = l; j < r; j++) mx = max(mx, a[j]);
    mxB = max(val[i - 1], val[i]);
    long long temp = solve(pos[i] - pos[i - 1] - 1, (mxB > mx));
    if (temp == 1e9) return puts("-1"), 0;
    ans += temp;
  }
  printf("%lld\n", ans);
  return 0;
}
