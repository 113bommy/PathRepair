#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 2e5 + 9;
void init() {}
void test_case(long long tc) {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > arr(m);
  long long mex = 1e18;
  for (long long i = 0; i <= n - 1; ++i) {
    long long l, r;
    cin >> l >> r;
    mex = min(mex, r - l + 1);
  }
  vector<long long> ans(n);
  for (long long i = 0; i <= n - 1; ++i) {
    ans[i] = (i % (mex));
  }
  cout << mex << "\n";
  for (long long i = 0; i <= n - 1; ++i) cout << ans[i] << " ";
  init();
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  for (long long tc = 1; tc <= t; ++tc) test_case(tc);
}
