#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int N = 1e9 + 7, M = 1e6, N2 = 1234567891;
int x, y, z, i, j, n, m, k, l, r, t, ma = 0, ans, x2, y2, f, kol, mi, a[410000],
                                     b[410000], d[401000], d2[401000],
                                     dp[401000], p[410000];
string s, s2, s3;
vector<int> v[410000], v2, v3;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> a[i];
    ans += a[i];
  }
  if (n % 2 == 0) {
    if (a[m])
      cout << "odd";
    else
      cout << "even";
  } else {
    if (ans % 2)
      cout << "odd";
    else
      cout << "even";
  }
}
