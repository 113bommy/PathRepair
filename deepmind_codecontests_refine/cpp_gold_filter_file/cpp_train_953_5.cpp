#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long INFF = 1e18;
const long long MAXN = 510;
const long long MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getTC() {
  if (0) {
    long long t;
    cin >> t;
    return t;
  } else
    return 1;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  k *= 8;
  vector<long long> nums;
  map<long long, long long> frek;
  for (long long i = 0; i < n; i++) {
    long long ta;
    cin >> ta;
    frek[ta]++;
    nums.push_back(ta);
  }
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  vector<long long> pref;
  pref.push_back(frek[nums[0]]);
  for (long long i = 1; i < nums.size(); i++) {
    pref.push_back(pref.back() + frek[nums[i]]);
  }
  const auto get = [&](long long l, long long r) -> long long {
    return (l == 0 ? pref[r] : pref[r] - pref[l - 1]);
  };
  long long ans = INF;
  for (long long i = 0; (1 << i) <= nums.size() * 2; i++) {
    long long len = min((1ll << i), (long long)nums.size());
    if (n * i > k) break;
    for (long long j = 0; j + len - 1 < nums.size(); j++) {
      long long l = j;
      long long r = j + len - 1;
      long long sum = get(l, r);
      long long ubah = n - sum;
      ans = min(ans, ubah);
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = getTC();
  while (t--) {
    solve();
  }
  return 0;
}
