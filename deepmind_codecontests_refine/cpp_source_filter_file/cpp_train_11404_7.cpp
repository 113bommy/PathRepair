#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
using namespace std;
long long a, b, c, d, e, f, p = 998244353, base = 157;
string s;
vector<long long> vec;
map<long long, long long> map1;
long long ans[50][50];
signed main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
  cin >> a >> b;
  ans[0][0] = b * 2048;
  if (b > 0) {
    c++;
  }
  for (long long i = 1; i <= a; i++) {
    for (long long j = 0; j <= i; j++) {
      if (j == 0) {
        ans[i][j] = max((ans[i - 1][j] - 2048) / 2, 0ll);
      } else {
        ans[i][j] = max((ans[i - 1][j] - 2048) / 2, 0ll) +
                    max((ans[i - 1][j - 1] - 2048) / 2, 0ll);
      }
      if (ans[i][j] >= 2048) {
        c++;
      }
    }
  }
  cout << c;
  cin >> a;
  return 0;
}
