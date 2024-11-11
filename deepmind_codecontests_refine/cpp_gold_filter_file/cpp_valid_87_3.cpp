#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << '=' << h << endl;
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
int n, m;
int a[1010], flag[1010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < m; ++i) cin >> a[i];
    int tot = 0, ans = 0;
    while (tot < m) {
      int maxx = 1e9 + 100, pos = 0;
      for (int i = m - 1; i >= 0; --i)
        if (flag[i] == 0 && a[i] < maxx) {
          maxx = a[i];
          pos = i;
        }
      for (int j = 0; j < pos; ++j)
        if (flag[j] == 1) ans++;
      flag[pos] = 1;
      tot++;
    }
    cout << ans << endl;
  }
  return 0;
}
