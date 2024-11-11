#include <bits/stdc++.h>
using namespace std;
const int N = 505;
long long n, dp[2][N];
struct card {
  long long a, b, k;
} a[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].a >> a[i].b >> a[i].k;
  sort(a, a + n, [](card A, card B) { return A.b > B.b; });
  for (int i = 0; i < n; i++) {
    card p = a[i];
    auto now = dp[i & 1], last = dp[!(i & 1)];
    copy(last, last + N, now);
    for (long long j = 1; j <= n; j++) {
      now[j] = max(now[j], last[j] + max(p.a - p.b * p.k, 0LL));
      now[j] = max(now[j], last[j - 1] + p.a - p.b * min(p.k, j - 1));
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) ans = max(ans, max(dp[0][i], dp[1][i]));
  cout << ans;
  return 0;
}
