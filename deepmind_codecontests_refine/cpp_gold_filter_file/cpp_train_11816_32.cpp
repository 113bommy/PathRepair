#include <bits/stdc++.h>
using namespace std;
int H, W, N;
long long int dp[2010];
long long int fact[205001];
long long int pow_mod(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = ans * a % 1000000007;
    b >>= 1;
    a = a * a % 1000000007;
  }
  return ans;
}
long long int comb(pair<int, int> p1, pair<int, int> p2) {
  long long int n = abs(p2.first - p1.first) + abs(p2.second - p1.second);
  long long int r = n - abs(p2.first - p1.first);
  return (fact[n] *
          pow_mod((fact[r] * fact[n - r]) % 1000000007, 1000000007 - 2) %
          1000000007) %
         1000000007;
}
int main() {
  cin >> H >> W >> N;
  vector<pair<int, int> > black;
  for (int i = (int)1; i <= (N); i++) {
    int x, y;
    cin >> x >> y;
    black.push_back(make_pair(x, y));
  }
  black.push_back(make_pair(H, W));
  fact[0] = 1;
  for (int i = (int)1; i <= (205001); i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
  sort(black.begin(), black.end());
  pair<int, int> start = make_pair(1, 1);
  for (int i = (int)0; i <= (N); i++) {
    dp[i] = comb(start, black[i]) % 1000000007;
    for (int k = (int)0; k <= (i); k++) {
      if (i != k && black[k].first <= black[i].first &&
          black[k].second <= black[i].second)
        dp[i] = dp[i] - (dp[k] * comb(black[k], black[i])) % 1000000007;
      dp[i] = (dp[i] + 1000000007) % 1000000007;
    }
  }
  cout << dp[N] << "\n";
  return 0;
}
