#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &a, const vector<long long> &b) {
  for (auto k : b) cout << k << " ";
  return a;
}
const long long INF = 8e18;
const long long p = 179;
long long n, k;
const long long LOG = 60;
long long sz = 0;
bitset<LOG> a;
long long count(long long k) {
  if (k > n) {
    return 0;
  } else if (k == n) {
    return 1;
  }
  bitset<LOG> cur(k);
  long long h = 0;
  for (long long i = 0; i < LOG; i++) {
    if (cur[i]) h = i;
  }
  if (sz == h) {
    return 2 - (k & 1);
  }
  long long ans = 0;
  if (k & 1) {
    ans = 1;
    for (long long i = h + 1; i < sz; i++) {
      ans += (1ll << (i - h));
    }
    if ((k << (sz - h)) > n) {
      return ans;
    }
    long long l = 0, r = (1ll << LOG), mid;
    while (r - l > 1) {
      mid = (l + r) / 2;
      if (mid + (k << (sz - h)) <= n)
        l = mid;
      else
        r = mid;
    }
    ans += min(l + 1, (1ll << (sz - h)));
  } else {
    ans = 2;
    for (long long i = h + 1; i < sz; i++) {
      ans += (1ll << (i - h + 1));
    }
    if ((k << (sz - h)) > n) {
      return ans;
    }
    long long l = 0, r = (1ll << LOG), mid;
    while (r - l > 1) {
      mid = (l + r) / 2;
      if (mid + (k << (sz - h)) <= n)
        l = mid;
      else
        r = mid;
    }
    ans += min(l + 1, (1ll << (sz - h + 1)));
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  a = bitset<LOG>(n);
  for (long long i = 0; i < LOG; i++) {
    if (a[i]) sz = i;
  }
  long long l = 0, r = 5e17, mid;
  long long ans = 1;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (count(2 * mid) >= k)
      l = mid;
    else
      r = mid;
  }
  ans = max(ans, 2 * l);
  l = 0, r = 5e17;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (count(2 * mid + 1) >= k)
      l = mid;
    else
      r = mid;
  }
  ans = max(ans, 2 * l + 1);
  cout << ans;
}
