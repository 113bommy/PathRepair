#include <bits/stdc++.h>
using namespace std;
struct firework {
  long long pos, time;
  bool operator<(firework obj) const { return time < obj.time; }
};
signed main() {
  long long m, n, d;
  cin >> m >> n >> d;
  vector<firework> fws;
  long long ans = 0;
  for (long long i = 0; i < (long long)(n); i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    ans += b;
    fws.emplace_back(firework{a - 1, c});
  }
  sort((fws).begin(), (fws).end());
  vector<long long> dp(3 * m, (1LL << 59)), bef(3 * m, (1LL << 59));
  for (long long i = m; i < 2 * m; i++) bef[i] = 0;
  long long time = 0;
  for (auto fw : fws) {
    vector<long long> minval(m);
    long long radius = min(fw.time - time, m);
    deque<long long> deq;
    for (long long i = m - radius; i < 2 * m + radius; i++) {
      while (deq.size() && bef[deq.back()] >= bef[i]) deq.pop_back();
      deq.push_back(i);
      if (i >= m + radius) {
        minval[i - (m + radius)] = deq.front();
        if (deq.front() == i - (1 + 2 * radius) + 1) deq.pop_front();
      }
    }
    for (long long i = m; i < 2 * m; i++) {
      dp[i] = bef[minval[i - m]] + abs(fw.pos - (i - m));
    }
    time = fw.time;
    bef = dp;
  }
  cout << ans - *min_element((dp).begin(), (dp).end()) << endl;
}
