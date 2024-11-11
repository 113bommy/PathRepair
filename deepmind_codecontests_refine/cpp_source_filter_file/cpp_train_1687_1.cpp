#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
long long dp[N][2];
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  vector<long long> fact;
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", a + i), sum += a[i];
  if (sum == 1) {
    cout << -1;
    return 0;
  }
  for (long long i = 2; i * i <= sum; i++) {
    if (sum % i == 0) {
      fact.push_back(i);
      while (sum % i == 0) {
        sum /= i;
      }
    }
  }
  if (sum) fact.push_back(sum);
  long long res = 1e18;
  for (auto p : fact) {
    long long cur = a[n - 1];
    dp[n - 1][0] = cur % p;
    dp[n - 1][1] = (p - cur % p) % p;
    for (int i = n - 2; i >= 0; i--) {
      long long rem = cur % p;
      long long nv = a[i] + rem;
      dp[i][0] = dp[i + 1][0] + nv % p;
      dp[i][1] = dp[i + 1][0] + (p - nv % p) % p;
      nv = a[i] - (p - rem) % p;
      long long up, down;
      if (nv % p == 0) {
        up = down = nv;
      } else {
        if (nv < 0) {
          nv *= -1;
          up = nv / p * p;
          down = (nv + p - 1) / p * p;
          up *= -1;
          down *= -1;
          nv *= -1;
        } else {
          down = nv / p * p;
          up = (nv + p - 1) / p * p;
        }
      }
      dp[i][0] = min(dp[i][0], dp[i + 1][1] + up - nv);
      dp[i][1] = min(dp[i][1], dp[i + 1][1] + nv - down);
      cur += a[i];
    }
    res = min(res, dp[0][0]);
  }
  cout << res;
}
