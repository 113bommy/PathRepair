#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
long long int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
long long int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const long long int MAXN = 1e5 + 5;
const long long int N = 1e5 + 5;
long long int n, m;
void solve() {
  long long int x, y, z, k, c, d;
  cin >> c >> d;
  cin >> n >> m;
  cin >> k;
  long long int req = n * m - k;
  long long int res = 1000111000111000111LL;
  for (long long int i = 0; i <= 10005; i++) {
    x = i * n;
    if (x >= req)
      res = min(res, i * c);
    else {
      y = req - x;
      res = min(res, i * c + y * d);
    }
  }
  cout << res << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
