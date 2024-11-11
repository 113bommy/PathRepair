#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200005;
const long long K = 24;
long long st[MAXN][K + 1];
long long LOG[MAXN];
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long query(long long L, long long R) {
  long long j = LOG[R - L + 1];
  return gcd(st[L][j], st[R - (1 << j) + 1][j]);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (auto &i : v) cin >> i;
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  long long m = n - 1;
  vector<long long> diff(m);
  for (long long i = 0; i < m; i++) diff[i] = abs(v[i + 1] - v[i]);
  for (long long i = 0; i < m; i++) st[i][0] = diff[i];
  for (long long j = 1; j <= K; j++) {
    for (long long i = 0; i + (1 << j) < m; i++) {
      st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  long long j = 0;
  long long ans = 1;
  for (long long i = 0; i < n - 1; i++) {
    while (j < i && query(j, i) == 1) j++;
    ans = max(ans, i - j + 2);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  LOG[1] = 0;
  for (long long i = 2; i < MAXN; i++) LOG[i] = LOG[i / 2] + 1;
  long long tc;
  tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
