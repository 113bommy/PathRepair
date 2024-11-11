#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10;
const long long inf = 0x3f;
vector<long long> a[N];
long long n, m;
bool check(long long mid) {
  if (n <= m - 1) {
    for (long long j = 0; j < m; j++) {
      long long flag = 0;
      for (long long i = 0; i < n; i++) {
        if (a[i][j] >= mid) flag++;
      }
      if (flag == 0) return 0;
    }
    return 1;
  } else {
    for (long long i = 0; i < n; i++) {
      long long flag = 0;
      for (long long j = 0; j < m; j++) {
        if (a[i][j] >= mid) flag++;
      }
      if (flag >= 2) return 1;
    }
    return 0;
  }
}
void f() {
  long long l = 0, r = 1e9 + 9;
  for (long long j = 0; j < m; j++) {
    long long maxn = 0;
    for (long long i = 0; i < n; i++) {
      maxn = max(maxn, a[i][j]);
    }
    r = min(r, maxn);
  }
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << r << '\n';
  ;
}
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    a[i].clear();
    for (long long j = 0; j < m; j++) {
      long long x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  f();
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
