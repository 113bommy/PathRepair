#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T& a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T& a, Args&... args) {
  cin >> a;
  __read(args...);
}
void solve2() {
  long long k;
  __read(k);
  if (k == 1) {
    cout << 1 << "\n";
    return;
  }
  long long now = 2;
  long long prev = 1;
  k--;
  long long ln = 1;
  while (k > 0) {
    ln = (long long)to_string(now).size();
    if (k > prev + ln) {
      k -= prev + ln;
      prev += ln;
      now++;
    } else
      break;
  }
  long long pw = 9;
  ln = 1;
  now = 1;
  while (k > 0) {
    if (pw * ln <= k) {
      k -= pw * ln;
      now += pw;
      pw *= 10;
      ++ln;
    } else
      break;
  }
  while (k > 0) {
    ln = (long long)to_string(now).size();
    if (ln < k) {
      k -= ln;
    } else
      break;
    ++now;
  }
  string ans = to_string(now);
  cout << ans[k - 1] << endl;
}
void solve() {
  long long tests;
  __read(tests);
  while (tests--) solve2();
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
