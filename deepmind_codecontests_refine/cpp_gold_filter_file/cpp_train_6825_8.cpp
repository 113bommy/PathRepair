#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline int msbp(int x) { return 31 - __builtin_clz(x); }
inline int msb(int x) { return 1 << msbp(x); }
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
int n, s, ans, a[N], l[N], hi;
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  for (int i = (1); i <= (n); ++i) {
    cin >> a[i];
    if (i == s && a[i]) {
      ++ans;
      a[i] = 0;
    }
    hi = max(hi, a[i]);
    l[a[i]]++;
  }
  ans += l[0] - 1;
  int liars = l[0] - 1;
  for (int i = (1); i <= (hi); ++i) {
    if (!l[i]) {
      ++l[i];
      if (liars)
        --liars;
      else {
        ++ans;
        --l[hi];
        while (l[hi] == 0) --hi;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
