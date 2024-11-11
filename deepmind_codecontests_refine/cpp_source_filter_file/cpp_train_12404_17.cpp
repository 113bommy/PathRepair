#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, r;
  cin >> n >> m >> r;
  long long a[n], b[m];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n, greater<long long>());
  long long rin = r;
  long long nos = r / a[0];
  r -= (r / a[0]) * (a[0]);
  r += b[0] * nos;
  cout << max(r, rin) << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t1 = 1;
  while (t1--) {
    solve();
  }
}
