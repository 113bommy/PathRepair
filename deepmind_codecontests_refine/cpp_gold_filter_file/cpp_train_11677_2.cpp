#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long N = 2e6 + 7;
const long long mod = 1e9 + 7;
pair<long long, long long> pr[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long x = 1;
  for (long long i = 1; i <= n; i++) {
    long long j = m, add = -1;
    if (i & 1) {
      j = 1;
      add = 1;
    }
    for (; j > 0 && j <= m; j += add) {
      pr[x] = {i, j};
      x += 2;
    }
  }
  x = 2;
  long long ok = 1;
  for (long long i = n; i > 0; i--) {
    long long j = m, add = -1;
    if (!ok) {
      j = 1;
      add = 1;
    }
    for (; j > 0 & j <= m; j += add) {
      pr[x] = {i, j};
      x += 2;
    }
    ok = 1 - ok;
  }
  for (long long i = 1; i <= n * m; i++) {
    cout << pr[i].first << ' ' << pr[i].second << '\n';
  }
}
