#include <bits/stdc++.h>
using namespace std;
const long double PI = atan(1.0) * 4;
const int64_t INF = 3e18;
const int32_t LOG = 21;
const long long int MOD = 1e9 + 7;
long long int a[500005];
long long int n;
long long int ok(long long int x) {
  vector<long long int> cnt(n + 3, 0);
  vector<long long int> pref(n + 3, 0);
  vector<long long int> suf(n + 3, 0);
  vector<long long int> vals;
  vals.push_back(0);
  for (long long int i = 1; i < n + 1; i++) cnt[a[i]]++;
  cnt[x]++;
  for (long long int i = n + 1; i >= 0; i--)
    for (long long int j = 0; j < cnt[i]; j++) vals.push_back(i);
  for (long long int i = 1; i < n + 2; i++) pref[i] = pref[i - 1] + vals[i];
  long long int ptr = n + 1;
  suf[n + 1] = vals[n + 1];
  for (long long int i = n; i >= 1; i--) suf[i] = suf[i + 1] + vals[i];
  bool gotcha = false;
  long long int left = 0, right = 0;
  for (long long int k = 1; k < n + 2; k++) {
    if (vals[k] == x) gotcha = true;
    while (ptr > 0 && vals[ptr] < k) ptr--;
    long long int right = 0;
    if (ptr <= k)
      right = suf[k + 1];
    else {
      long long int rem = ptr - k;
      right = suf[ptr + 1] + rem * k;
    }
    right += k * (k - 1);
    left = pref[k];
    if (left > right && gotcha)
      return -1;
    else if (left > right)
      return 1;
  }
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int tests = 1;
  for (long long int ii = 0; ii < tests; ii++) {
    cin >> n;
    for (long long int i = 1; i < n + 1; i++) cin >> a[i];
    long long int parity = accumulate(a + 1, a + n + 1, 0LL) & 1;
    long long int l = parity, r = n;
    long long int lb = -2;
    while (l <= r) {
      long long int mid = (l + r) >> 1;
      long long int x = 2 * mid - parity;
      if (x > n) {
        r = mid - 1;
        continue;
      }
      if (ok(x) == 1) {
        lb = max(lb, x);
        l = mid + 1;
      } else
        r = mid - 1;
    }
    if (lb != -2)
      lb += 2;
    else {
      if (parity)
        lb = 1;
      else
        lb = 0;
    }
    l = parity, r = n;
    long long int ub = n + 3;
    while (l <= r) {
      long long int mid = (l + r) >> 1;
      long long int x = 2 * mid - parity;
      if (x > n) {
        r = mid - 1;
        continue;
      }
      if (ok(x) == -1) {
        ub = min(ub, x);
        r = mid - 1;
      } else
        l = mid + 1;
    }
    if (ub != n + 3)
      ub -= 2;
    else {
      if (parity) {
        if (n & 1)
          ub = n;
        else
          ub = n - 1;
      } else {
        if (n & 1)
          ub = n - 1;
        else
          ub = n;
      }
    }
    long long int tot = 0;
    for (long long int i = lb; i <= ub; i += 2) {
      cout << i << " ";
      tot++;
    }
    if (!tot) cout << -1;
    cout << '\n';
  }
  return 0;
}
