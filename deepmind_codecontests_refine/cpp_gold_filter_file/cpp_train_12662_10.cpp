#include <bits/stdc++.h>
using namespace std;
int cnt[71];
long long dp[2][1 << 20];
bool pri[71];
vector<int> primes;
vector<pair<int, int> > factors[71];
int code[71];
int mask[71];
long long power[100005];
int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    cnt[x]++;
  }
  for (int i = 2; i <= 70; i++) {
    if (pri[i]) continue;
    primes.push_back(i);
    for (int j = 2 * i; j <= 70; j += i) pri[j] = true;
  }
  for (int i = 0; i < primes.size(); i++) {
    code[primes[i]] = i;
  }
  for (int i = 2; i <= 70; i++) {
    x = i;
    for (int j = 0; j < primes.size() && x > 1; j++) {
      int cnt = 0;
      while (x > 1 && (x % primes[j] == 0)) {
        cnt++;
        x /= primes[j];
      }
      factors[i].push_back(make_pair(primes[j], cnt));
    }
  }
  for (int i = 1; i <= 70; i++) {
    int m = 0;
    for (int j = 0; j < factors[i].size(); j++) {
      if (factors[i][j].second & 1) m |= (1 << code[factors[i][j].first]);
    }
    mask[i] = m;
  }
  power[0] = 1;
  for (int i = 1; i <= n; i++) power[i] = (power[i - 1] * 2) % 1000000007;
  dp[0][0] = 1;
  int z = 1;
  for (int i = 1; i <= 70; i++) {
    if (!cnt[i]) continue;
    for (int j = 0; j <= (1 << 19) - 1; j++) {
      dp[z][j ^ mask[i]] =
          (power[cnt[i] - 1] * (dp[z ^ 1][j] + dp[z ^ 1][j ^ mask[i]]) %
           1000000007) %
          1000000007;
    }
    z ^= 1;
  }
  long long ans = dp[z ^ 1][0];
  ans = (ans - 1 + 1000000007) % 1000000007;
  printf("%lld\n", ans);
  return 0;
}
