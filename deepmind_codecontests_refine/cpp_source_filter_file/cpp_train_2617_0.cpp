#include <bits/stdc++.h>
using namespace std;
long long n, k, a, b;
vector<long long> v;
multiset<long long> s;
long long bitfind(long long l, long long r) {
  long long lt = lower_bound(v.begin(), v.end(), l) - v.begin();
  long long rt = upper_bound(v.begin(), v.end(), r) - v.begin();
  if (lt == n) {
    return a;
  } else {
    if (v[lt] > r) {
      return a;
    } else {
      if (r > l) {
        long long mid = (l + r) / 2;
        return min(b * (rt - lt) * (r - l + 1),
                   bitfind(l, mid) + bitfind(mid + 1, r));
      } else {
        return b * (rt - lt);
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k >> a >> b;
  for (long long i = 1; i <= k; i++) {
    long long t;
    cin >> t;
    s.insert(t);
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  long long ans = bitfind(1, (1 << n));
  cout << ans << endl;
  return 0;
}
