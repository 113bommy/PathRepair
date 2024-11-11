#include <bits/stdc++.h>
using namespace std;
const long long N = 105;
long long ans, ans1, n1, n, k, pw[N], t, ff[N], fix[N], cntt, cnt, mn, cnt1, xx;
vector<long long> v, vv;
signed main() {
  std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  pw[0] = 1;
  ans = 1e9;
  for (long long i = 1; i <= 10; i++) {
    pw[i] = pw[i - 1] * 10;
  }
  long long bb = 0;
  while (t--) {
    bb++;
    cin >> n >> k;
    n1 = n;
    cntt = 0;
    ans = 1e9;
    for (long long i = 0; i <= 9; i++) ff[i] = 0;
    v.clear();
    while (n1) {
      if (!ff[n1 % 10]) ff[n1 % 10] = 1, cntt++;
      v.push_back(n1 % 10);
      n1 /= 10;
    }
    if (cntt <= k) {
      cout << n << endl;
      continue;
    }
    reverse(v.begin(), v.end());
    cnt = v.size();
    for (long long idx = 0; idx < cnt; idx++) {
      if (v[idx] == 9) continue;
      mn = 1e9;
      cnt1 = 0;
      ans1 = 0;
      for (long long j = 0; j <= 9; j++) fix[j] = 0;
      for (long long j = 0; j < idx; j++) {
        if (!fix[v[j]]) cnt1++, fix[v[j]] = 1, mn = min(mn, v[j]);
        ans1 += pw[cnt - j - 1] * v[j];
      }
      if (cnt1 > k) {
        continue;
      }
      if (cnt1 + 2 <= k || (fix[v[idx] + 1] && cnt1 + 1 <= k) ||
          (fix[0] && cnt1 + 1 <= k)) {
        ans1 += pw[cnt - idx - 1] * (v[idx] + 1);
        ans = min(ans, ans1);
        continue;
      }
      if (cnt1 + 1 <= k) {
        ans1 += pw[cnt - idx - 1] * (v[idx] + 1);
        mn = min(mn, v[idx] + 1);
        for (long long j = idx + 1; j < cnt; j++) {
          ans1 += pw[cnt - j - 1] * mn;
        }
        ans = min(ans, ans1);
      }
      if (cnt1 == k) {
        xx = 0;
        for (long long j = v[idx] + 1; j <= 9; j++) {
          if (fix[j]) {
            xx = j;
            break;
          }
        }
        if (!xx) continue;
        ans1 += xx * pw[cnt - idx - 1];
        for (long long j = idx + 1; j < cnt; j++) {
          ans1 += pw[cnt - j - 1] * mn;
        }
        ans = min(ans, ans1);
      }
    }
    cout << ans << endl;
  }
}
