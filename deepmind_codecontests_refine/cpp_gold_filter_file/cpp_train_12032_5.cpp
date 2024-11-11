#include <bits/stdc++.h>
using namespace std;
long long n, m;
const long long N = 16;
string ans;
void add(long long x) {
  if (x >= 0 and x <= 9)
    ans += (char)('0' + x);
  else
    ans += (char)('a' - 10 + x);
}
long long c[N][N];
vector<long long> backpack;
long long lft;
long long dp[N];
long long tmp[N];
long long able = 1;
long long calc() {
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (long long i = backpack.size() - 1; i >= 0; i--) {
    memset(tmp, 0, sizeof(tmp));
    for (long long j = 0; j <= backpack[i]; j++)
      for (long long k = 0; k <= lft; k++)
        if (k + j <= lft and k + j >= (i == 0 and able))
          tmp[k + j] += dp[k] * c[j][k + j - (j > 0 and i == 0 and able)];
    swap(dp, tmp);
  }
  if (!able) return dp[lft];
  long long cg = dp[lft];
  for (long long i = lft - 1; i >= 0; i--) dp[lft] += dp[i];
  return dp[lft] - (cg * 0);
}
int main() {
  long long k, t;
  cin >> k >> t;
  vector<long long> _backpack;
  for (long long i = 0; i < N; i++) _backpack.push_back(t);
  c[0][0] = 1;
  for (long long i = 1; i < N; i++) {
    c[0][i] = 1;
    for (long long j = 1; j <= i; j++) c[j][i] = c[j - 1][i - 1] + c[j][i - 1];
  }
  able = 1;
  for (long long i = 10 - 1; i >= 0; i--) {
    long long befs = 0;
    long long stg = 0;
    backpack = _backpack, lft = i;
    if (calc() >= k and able) {
      continue;
    } else if (able)
      k -= calc(), stg = 1;
    able = 0;
    for (long long j = stg; j < N; j++) {
      if (!_backpack[j]) continue;
      backpack = _backpack, lft = i;
      backpack[j]--;
      if (calc() + befs >= k) {
        k -= befs;
        _backpack[j]--;
        add(j);
        break;
      }
      befs += calc();
    }
  }
  long long ij = 0;
  for (long long i = ij; i < ans.size(); i++) cout << ans[i];
  return 0;
}
