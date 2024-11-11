#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
inline int add(long long a, long long b) { return (a + b) % MOD; }
inline int mul(long long a, long long b) { return (a * b) % MOD; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  function<int(int, int)> rec = [&](int from, int to) {
    if (from >= to) return 1;
    int& ret = dp[from][to];
    if (ret != -1) return ret;
    ret = rec(from + 1, to);
    for (int i = from + 1; i <= to; i++) {
      if (arr[i] > arr[from])
        ret = add(ret, mul(rec(from + 1, i - 1), rec(i + 1, to)));
    }
    return ret;
  };
  cout << rec(1, n - 1) << '\n';
  return (0);
}
