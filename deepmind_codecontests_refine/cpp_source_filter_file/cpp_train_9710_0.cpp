#include <bits/stdc++.h>
using namespace std;
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
struct compare {
  bool operator()(const pair<long long, long long> a,
                  const pair<long long, long long> b) const {
    return a.first < b.first;
  }
};
const long long nax = 2005;
long long n, m;
vector<pair<long long, long long>> robber, light, moves;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  robber.assign(n, {0, 0});
  light.assign(m, {0, 0});
  for (long long i = 0; i < n; i++) {
    cin >> robber[i].first >> robber[i].second;
  }
  for (long long i = 0; i < m; i++) {
    cin >> light[i].first >> light[i].second;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long a = light[j].first - robber[i].first + 1;
      long long b = light[j].second - robber[i].second + 1;
      a = max(a, 0LL);
      b = max(b, 0LL);
      moves.push_back({a, b});
    }
  }
  long long sz = moves.size();
  sort(moves.begin(), moves.end());
  vector<long long> suf(sz);
  suf[sz - 1] = moves[sz - 1].second;
  for (long long i = sz - 2; i >= 0; i--) {
    suf[i] = max(suf[i + 1], moves[i].second);
  }
  long long ans = 1e18;
  for (long long i = 0; i < sz; i++) {
    ans = min(ans, moves[i].first + (i + 1 < sz ? suf[i + 1] : 0));
  }
  cout << ans << "\n";
}
