#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
vector<long long> ticks;
long long mincost[N];
long long memo[N];
int n;
long long DP(int idx) {
  if (idx < 0) return 0;
  long long& ret = memo[idx];
  if (ret != -1) return ret;
  ret = LLONG_MAX;
  int nxt;
  nxt = upper_bound(ticks.begin(), ticks.end(), ticks[idx] - 1439) -
        ticks.begin();
  ret = min(ret, 120 + DP(nxt - 1));
  nxt =
      upper_bound(ticks.begin(), ticks.end(), ticks[idx] - 89) - ticks.begin();
  ret = min(ret, 50 + DP(nxt - 1));
  ret = min(ret, 20 + DP(idx - 1));
  return ret;
}
int main() {
  int t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    ticks.push_back(t);
  }
  memset(memo, -1, sizeof(memo));
  DP(n - 1);
  long long sum, cur;
  sum = 0;
  for (int i = 0; i < n; i++) {
    cur = memo[i] - sum;
    cout << cur << "\n";
    sum += cur;
  }
  return 0;
}
