#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long power(long long a, long long b, long long m = 1000000007) {
  long long answer = 1;
  while (b) {
    if (b & 1) answer = (answer * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return answer;
}
using namespace std;
void ctrl() { cout << "Control\n"; }
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  long long n;
  cin >> n;
  long long dp[n][n];
  long long second = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) cin >> dp[i][j], second += dp[i][j];
  vector<pair<pair<long long, long long>, long long>> v;
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    if (x > y) swap(x, y);
    v.push_back({{x, y}, z});
  }
  second = second / 2;
  for (long long i = 0; i < q; i++) {
    for (long long c = 0; c < n; c++) {
      for (long long t = c + 1; t < n; t++) {
        long long st = v[i].first.first, en = v[i].first.second,
                  wt = v[i].second;
        if (dp[c][t] > dp[c][st] + wt + dp[en][t]) {
          second -= dp[c][t];
          second += dp[c][st] + wt + dp[en][t];
          dp[c][t] = dp[c][st] + wt + dp[en][t];
          dp[t][c] = dp[c][st] + wt + dp[en][t];
        } else if (dp[c][t] > dp[c][en] + wt + dp[st][t]) {
          second -= dp[c][t];
          second += dp[c][en] + wt + dp[st][t];
          dp[c][t] = dp[c][en] + wt + dp[st][t];
          dp[t][c] = dp[c][en] + wt + dp[st][t];
        }
      }
    }
    cout << second << " ";
  }
  return 0;
}
