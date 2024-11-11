#include <bits/stdc++.h>
using namespace std;
int64_t chk(int64_t m, int64_t n, int64_t x) {
  int64_t tot = n * n;
  int64_t zero = (n / m) * (n / m);
  if (tot - zero == x) return 0;
  if (tot - zero < x) return 1;
  return 2;
}
void solve() {
  int64_t x;
  cin >> x;
  int64_t sq = sqrt(x);
  sq++;
  for (int64_t i = 0; i < 5; i++) {
    int64_t n = sq + i;
    int64_t lo = 1;
    int64_t hi = n;
    while (lo <= hi) {
      int64_t mid = (lo + hi) / 2;
      int64_t res = chk(mid, n, x);
      if (res == 0) {
        cout << n << ' ' << mid << '\n';
        return;
      } else if (res == 1)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
  }
  cout << -1 << '\n';
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t tt;
  cin >> tt;
  while (tt--) solve();
  cerr << " Execution : " << (1.0 * clock()) / CLOCKS_PER_SEC << "s \n";
  return 0;
}
