#include <bits/stdc++.h>
using namespace std;
long long multi(long long a, long long b) {
  return ((a % 998244353) * (b % 998244353)) % 998244353;
}
long long sum(long long a, long long b) {
  return ((a % 998244353) + (b % 998244353)) % 998244353;
}
long long calc(long long a, long long b) {
  long long total = 1;
  long long temp = a;
  while (b) {
    if (b & 1) {
      total *= multi(total, temp);
    }
    temp = multi(temp, a);
    b = b >> 1;
  }
  return total;
}
vector<vector<long long> > dp;
long long combi(long long n, long long k) {
  dp[0].push_back(1);
  for (long long i = 1; i <= 2000; i++) {
    dp[i].push_back(1);
    for (long long i2 = 1; i2 <= i - 1; i2++) {
      dp[i].push_back(sum(dp[i - 1][i2 - 1], dp[i - 1][i2]));
    }
    dp[i].push_back(1);
  }
  return dp[n][k];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  if (k == 0) {
    cout << m << endl;
    return 0;
  }
  dp.assign(2010, vector<long long>());
  long long colors = multi(calc(m - 1, k), m);
  long long manners = combi(n - 1, k);
  long long res = multi(colors, manners);
  cout << res << endl;
  return 0;
}
