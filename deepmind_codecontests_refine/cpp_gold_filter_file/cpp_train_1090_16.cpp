#include <bits/stdc++.h>
using namespace std;
long long solve(int spt, long long ans, long long e) {
  if (ans == 0) return 0ll;
  long long ret;
  if (spt == 0) {
    long long v = (1ll << (ans - 1));
    if (e <= v)
      ret = solve(!spt, ans - 1, e) + 1;
    else
      ret = solve(spt, ans - 1, e - v) + (1ll << ans);
  } else {
    long long v = (1ll << (ans - 1));
    if (e > v)
      ret = solve(!spt, ans - 1, e - v) + 1;
    else
      ret = solve(spt, ans - 1, e) + (1ll << ans);
  }
  return ret;
}
int main() {
  long long ans, n;
  cin >> ans >> n;
  cout << solve(0, ans, n);
}
