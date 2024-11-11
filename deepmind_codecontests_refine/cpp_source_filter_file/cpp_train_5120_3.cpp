#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
double pi = acos(-1.0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long powerm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % M;
    y = y >> 1;
    x = (x * x) % M;
  }
  return res % M;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool comp(const pair<long long, long long>& a,
          const pair<long long, long long>& b) {
  return a.first + a.second > b.first + b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long r;
  cin >> n >> r;
  vector<pair<long long, long long>> v1, v2;
  for (int i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    if (b >= 0)
      v1.push_back(make_pair(a, b));
    else {
      a = max(a, abs(b));
      v2.push_back(make_pair(a + b, b));
    }
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end(), comp);
  long long cc = 0;
  for (auto it : v1) {
    if (r >= it.first) {
      r += it.second;
      cc++;
    }
  }
  vector<vector<long long>> dp(v2.size() + 1, vector<long long>(r + 1, 0));
  dp[0][r] = cc;
  for (int i = 0; i < v2.size(); i++) {
    for (int j = 0; j <= r; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + v2[i].second >= 0 && j >= v2[i].first)
        dp[i + 1][j + v2[i].second] =
            max(dp[i + 1][j + v2[i].second], dp[i][j] + 1);
    }
  }
  long long ans = 0;
  for (int i = 0; i <= r; i++) ans = max(ans, dp[v2.size()][i]);
  cout << ans;
  return 0;
}
