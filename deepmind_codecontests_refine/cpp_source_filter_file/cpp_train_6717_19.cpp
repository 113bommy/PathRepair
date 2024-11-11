#include <bits/stdc++.h>
using namespace std;
long long P = 1000000007;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x;
  cin >> x;
  long long ans = 0;
  for (long long i = 1; i <= x; ++i) {
    ans += 1 << x;
  }
  cout << ans;
}
