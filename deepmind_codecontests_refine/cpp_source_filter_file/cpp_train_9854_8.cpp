#include <bits/stdc++.h>
using namespace std;
long long n, m, x, c;
const long long N = 1000000;
long long z;
long long inf = 1e7;
long long dp[N];
long long a[N];
pair<long long, long long> t[4 * N];
void build(long long v, long long l, long long r) {
  if (l == r) {
    t[v].first = a[l];
    t[v].second = inf;
  } else {
    long long mid = (l + r) / 2;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    vector<long long> vv;
    vv.push_back(t[v * 2].first);
    vv.push_back(t[v * 2].second);
    vv.push_back(t[v * 2 + 1].first);
    vv.push_back(t[v * 2 + 1].second);
    sort(vv.begin(), vv.end());
    t[v] = {vv[0], vv[1]};
  }
}
pair<long long, long long> get(long long v, long long l, long long r,
                               long long tl, long long tr) {
  if (l > r || tl > tr) {
    return {inf, inf};
  } else {
    if (l == tl && r == tr) {
      return t[v];
    } else {
      long long m = (l + r) / 2;
      pair<long long, long long> b = get(v * 2, l, m, tl, min(m, tr));
      pair<long long, long long> c =
          get(v * 2 + 1, m + 1, r, max(tl, m + 1), tr);
      vector<long long> vv;
      vv.push_back(b.first), vv.push_back(b.second), vv.push_back(c.first),
          vv.push_back(c.second);
      sort(vv.begin(), vv.end());
      return {vv[0], vv[1]};
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> c;
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  build(1, 1, n);
  for (long long i = 1; i <= n; i++) {
    if (i >= c) {
      pair<long long, long long> p = get(1, 1, n, i - c + 1, i);
      dp[i] = p.first + dp[i - c];
      dp[i] = max(dp[i], dp[i - 1]);
    }
  }
  cout << sum - dp[n];
  return 0;
}
