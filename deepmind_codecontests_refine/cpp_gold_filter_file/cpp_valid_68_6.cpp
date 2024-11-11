#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
void io() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
template <typename T>
inline void debug(T const& x) {
  cout << x << "\n";
}
inline int fread() {
  int ans = 0, fl = 1;
  char i = getchar();
  while (i < '0' || i > '9') {
    if (i == '-') {
      fl = -1;
    }
    i = getchar();
  }
  while (i >= '0' && i <= '9') {
    ans = ans * 10 + i - '0';
    i = getchar();
  }
  return ans * fl;
}
const long long maxn = 1e7 + 10;
long long tot;
long long a[maxn];
long long t, n;
signed main() {
  io();
  for (tot = 1;; ++tot) {
    a[tot] = a[tot - 1] + tot * 2ll - 1ll;
    if (a[tot] > 1000000000) break;
  }
  cin >> t;
  while (t--) {
    cin >> n;
    long long pos = lower_bound(a + 1, a + 1 + tot, n) - a;
    if (a[pos] == n) {
      cout << pos << " " << 1 << "\n";
      continue;
    }
    pos--;
    long long res = n - a[pos];
    if (res <= pos + 1ll) {
      cout << res << " " << pos + 1ll << "\n";
    } else {
      res -= (pos + 1ll);
      cout << pos + 1ll << " " << pos + 1ll - res << "\n";
    }
  }
  return 0;
}
