#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
long long f(long long x) {
  long long ret = 0;
  while (x) {
    ret = max(ret, x % 10);
    x /= 10;
  }
  return ret;
}
pair<long long, long long> dp[10][N];
long long ff[N];
int main() {
  for (int i = 0; i < N; ++i) {
    ff[i] = f(i);
  }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < N; ++j) {
      if (j == 0) {
        dp[i][j] = make_pair(0, 0);
        continue;
      }
      int _ = ff[j];
      int __ = max(_, i);
      if (j - __ < 0) {
        dp[i][j] = make_pair(0, j);
      } else {
        dp[i][j] = dp[i][j - __];
        dp[i][j].first++;
      }
    }
  }
  int n;
  cin >> n;
  long long ans = 0;
  while (n != 0) {
    long long pre = n / 1000000;
    long long suf = n % 1000000;
    long long _ = ff[pre];
    pair<long long, long long> val = dp[_][suf];
    ans += val.first;
    n = pre * 1000000 + val.second;
    if (n != 0) {
      ++ans;
      n -= f(n);
    }
  }
  cout << ans << endl;
}
