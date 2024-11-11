#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long nax = 3e5 + 5;
long long cnt[nax];
long long f[nax];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long mx = 0;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long clr;
    cin >> clr;
    cnt[f[clr]]--;
    f[clr]++;
    cnt[f[clr]]++;
    mx = max(mx, f[clr]);
    if (cnt[1] == i) {
      ans = i;
    } else if (cnt[i] == 1) {
      ans = i;
    } else if (cnt[1] == 1 && cnt[mx] * mx == i - 1) {
      ans = i;
    } else if (cnt[mx - 1] * (mx - 1) == i - mx && cnt[mx] == 1) {
      ans = i;
    }
  }
  cout << ans << '\n';
  return 0;
}
