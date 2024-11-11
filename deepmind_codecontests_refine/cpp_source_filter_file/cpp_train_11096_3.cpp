#include <bits/stdc++.h>
using namespace std;
template <typename T>
void uin(T &a, T b) {
  if (b < a) {
    a = b;
  }
}
template <typename T>
void uax(T &a, T b) {
  if (b > a) {
    a = b;
  }
}
const long long maxn = 100 * 1000 + 228;
long long n;
long long a[maxn], b[maxn], pref[maxn];
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= (long long)n; ++i) {
    cin >> b[i];
  }
  for (long long i = 1; i <= (long long)n - 1; ++i) {
    a[i] = abs(b[i] - b[i + 1]);
    long long kek = 1;
    if (i % 2 == 0) {
      kek = -1;
    }
    pref[i] = pref[i - 1] + a[i] * kek;
  }
  long long mn_odd = 0, mn_even = 0, mn_odd1 = 0, mn_even1 = 0;
  long long res = 0;
  for (long long i = 1; i <= (long long)n - 1; ++i) {
    if (i & 1) {
      uax(res, pref[i] - mn_odd);
      uax(res, -pref[i] - mn_even1);
      uin(mn_odd1, -pref[i]);
      uin(mn_odd, pref[i]);
    } else {
      uax(res, pref[i] - mn_even);
      uax(res, -pref[i] - mn_odd1);
      uin(mn_even1, -pref[i]);
      uin(mn_even, pref[i]);
    }
  }
  cout << res << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
