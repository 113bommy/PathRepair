#include <bits/stdc++.h>
using namespace std;
const long long N = 3e3 + 60;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, m, h;
  cin >> n >> h >> m;
  vector<long long> a(n, h);
  for (long long i = 0; i < m; i++) {
    long long l, r, x;
    cin >> l >> r >> x;
    --l, --r;
    for (long long j = l; j <= r; j++) {
      a[j] = min(a[j], x);
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) ans += a[i] * a[i];
  cout << ans << '\n';
}
