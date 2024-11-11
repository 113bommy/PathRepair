#include <bits/stdc++.h>
using namespace std;
long long n, m, t;
long long C(long long N, long long k) {
  double res = 1;
  for (long long i = 1; i <= k; ++i) res = res * (N - k + i) / i;
  return (long long)(res + 0.01);
}
void input() { cin >> n >> m >> t; }
void solve() {
  long long ans = 0;
  for (long long i = 4; i <= n; i++) {
    long long d = t - i;
    if (d < 1) break;
    ans += C(n, i) * C(m, d);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  long long T = 1;
  while (T--) {
    input();
    solve();
    cout << endl;
  }
  cin.get();
  return 0;
}
