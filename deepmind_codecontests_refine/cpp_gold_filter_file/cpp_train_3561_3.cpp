#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const long long maxn = (long long)2e5 + 5;
const long long mod = 998244353;
const long long inf = 0x3f3f3f3f;
long long T = 1;
void solve() {
  long long n;
  cin >> n;
  long long sum = 0, num = 0;
  for (long long i = 1; i <= n; ++i) {
    long long x;
    cin >> x;
    sum += x;
    num += x / 2 + ((x & 1) && (i & 1));
  }
  cout << min(num, sum - num);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  while (T--) solve();
  return 0;
}
