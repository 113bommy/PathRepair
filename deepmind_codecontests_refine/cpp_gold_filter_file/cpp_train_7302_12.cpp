#include <bits/stdc++.h>
using namespace std;
long long cnt_bits(long long a, long long b) {
  long long c = a & b;
  long long cnt = 0;
  while (c) {
    if (c & 1) cnt++;
    c /= 2;
  }
  return cnt & 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<vector<pair<long long, long long> > > e(62);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    long long v, m;
    cin >> v >> m;
    sum += v;
    long long cur = m, last = 0, cnt = 0;
    while (cur) {
      if (cur & 1) last = cnt;
      cnt++;
      cur /= 2;
    }
    e[last].push_back({v, m});
  }
  bool positive = (sum < 0);
  long long ans = 0;
  sum = 0;
  for (long long i = 0; i < 62; i++) {
    long long step_sum = 0;
    for (pair<long long, long long> x : e[i]) {
      if (cnt_bits(ans, x.second))
        step_sum -= x.first;
      else
        step_sum += x.first;
    }
    if (step_sum == 0) continue;
    if (sum + step_sum > 0 && positive)
      sum += step_sum;
    else if (sum + step_sum < 0 && !positive)
      sum += step_sum;
    else {
      sum -= step_sum;
      ans += (1ll << i);
    }
  }
  cout << ans;
  return 0;
}
