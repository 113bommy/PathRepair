#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 100, OO = 1e9, M = 1e9 + 7, P = 6151, SQ = 120,
                lg = 12;
bool mark[N];
long long a[N], b[N], ans[N];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    mark[i] = false;
  }
  long long cnt = 0;
  long long x = 1;
  while (!mark[x]) {
    mark[x] = true;
    b[cnt] = x;
    cnt++;
    x = x - a[x];
  }
  long long h = 0;
  for (long long i = cnt - 1; i >= 0; i--) {
    ans[h] = b[i];
    h++;
    if (b[i] == b[cnt] - a[b[cnt]]) break;
  }
  cout << h << '\n';
  for (long long i = 0; i < h; i++) cout << ans[i] << " ";
  cout << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
