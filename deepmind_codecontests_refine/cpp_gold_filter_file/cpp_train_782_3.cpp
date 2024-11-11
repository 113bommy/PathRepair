#include <bits/stdc++.h>
using namespace std;
pair<int, long long> dp[10000000];
pair<int, long long> cdp[100000];
long long cubes[100001];
int getcube(long long val) {
  int i = lower_bound(cubes, cubes + 100001, val) - cubes;
  if (val == cubes[i]) return i;
  return i - 1;
}
pair<int, long long> solve(long long val) {
  if (val < 0) val = 0;
  if (val < 10000000) return dp[val];
  long long cb = getcube(val);
  long long cbb = cb * cb * cb;
  auto a = solve(val - cbb);
  a.first++;
  a.second += cbb;
  auto b = cdp[cb];
  return max(a, b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (long long i = 0; i <= 100000; i++) cubes[i] = i * i * i;
  dp[0] = make_pair(0, 0ll);
  dp[1] = make_pair(1, 1ll);
  for (long long i = 1, j = 1; i < 10000000; i++) {
    int k = j - 1;
    if (j * j * j == i) {
      dp[i] = make_pair(1, i);
      j++;
    } else {
      dp[i] = make_pair(dp[i - k * k * k].first + 1, i);
    }
  }
  for (long long i = 2; i < 10000000; i++) {
    dp[i] = max(dp[i], dp[i - 1]);
  }
  cdp[1] = dp[1];
  for (long long i = 2; i < 100000; i++) {
    cdp[i] = max(cdp[i - 1], solve(i * i * i - 1));
  }
  long long m;
  cin >> m;
  long long maxv = 1e15;
  if (m == maxv) m--;
  auto ans = solve(m);
  cout << ans.first << ' ' << ans.second << endl;
  return 0;
}
