#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
long long n, x, y, ans;
vector<pair<long long, long long> > arr;
multiset<long long> tv;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> x >> y;
  for (long long i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    arr.emplace_back(l, r);
  }
  sort(arr.begin(), arr.end());
  for (auto v : arr) {
    bool buy = false;
    long long l = v.first, r = v.second;
    auto it = tv.lower_bound(-l + 1);
    ans = (ans + ((r - l) * y) % MOD) % MOD;
    if (tv.empty())
      buy = true;
    else {
      if (it == tv.end())
        buy = true;
      else {
        long long r0 = -(*it);
        if ((l - r0) * y > x) buy = true;
      }
    }
    if (buy)
      ans = (ans + x) % MOD;
    else {
      long long r0 = -(*it);
      ans = (ans + ((l - r0) * y) % MOD) % MOD;
      tv.erase(it);
    }
    tv.insert(-r);
  }
  cout << ans << endl;
  return 0;
}
