#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1000000007;
const long long INF = 1e18;
const int MX = 2000000001;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long t, q, n, au, b, k, l, m, r, x = 0, y = 0, ans = 0, temp = 0,
                                        res = 0;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < (n); i++) cin >> a[i];
  ans = 1;
  for (long long i = 0; i < (n - 1); i++) {
    if (a[i] != a[i + 1])
      res = max(res, ++ans);
    else
      ans = 1;
  }
  cout << res;
}
