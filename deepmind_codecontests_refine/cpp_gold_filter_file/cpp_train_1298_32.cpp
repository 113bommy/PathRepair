#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100100;
struct bamboo {
  long long x, y;
};
inline bool operator<(register bamboo a, register bamboo b) {
  return a.y > b.y;
}
priority_queue<bamboo> q;
long long n, m, k, p, h[MAXN], a[MAXN], f[MAXN];
long long l = 0, r = 1e14, ans;
inline bool check(register long long x) {
  memset(f, 0, sizeof(f));
  while (!q.empty()) q.pop();
  for (register long long i = 1; i <= n; i++)
    if (x < h[i] + a[i] * m) q.push((bamboo){i, x / a[i]});
  for (register long long i = 1; i <= m; i++)
    for (register long long j = 1; j <= k; j++)
      if (!q.empty()) {
        register bamboo now = q.top();
        q.pop();
        if (now.y < i) return false;
        f[now.x]++;
        if (x + f[now.x] * p < h[now.x] + a[now.x] * m)
          q.push((bamboo){now.x, (x + f[now.x] * p) / a[now.x]});
      }
  return q.empty();
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> p;
  for (register long long i = 1; i <= n; i++) cin >> h[i] >> a[i];
  while (l <= r) {
    register long long mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
