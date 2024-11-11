#include <bits/stdc++.h>
using namespace std;
const long long maxm = 3e5 + 5;
long long q[maxm];
long long w[maxm];
long long n, m;
bool cmp(long long a, long long b) { return a > b; }
void solve() {
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> q[i] >> w[i];
  }
  sort(w + 1, w + 1 + m, cmp);
  long long pos = -1;
  for (long long i = m; i >= 1; i--) {
    long long t = m * (m - 1) / 2;
    if (i % 2 == 0) {
      t += i / 2 - 1;
    }
    if (t < n) {
      pos = i;
      break;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= pos; i++) {
    ans += w[i];
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
