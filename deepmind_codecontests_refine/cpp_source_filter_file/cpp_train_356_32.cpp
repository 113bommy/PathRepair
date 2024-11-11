#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long fast_exp(long long a, long long b) {
  if (b <= 0)
    return 1;
  else {
    long long res = 1;
    res = fast_exp(a, b / 2);
    res = (res * res) % mod;
    if (b % 2 == 1) res = (res * a) % mod;
    return res;
  }
}
const long long N = 2e5 + 1000;
const long double pi = acos(-1.0);
long double dp[2][N + 5] = {};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  const int lim = 100;
  dp[0][1] = 1;
  long double ans = 0;
  int cur = 0;
  int next = (cur + 1) % 2;
  int iter = 0;
  long double inverse_k = 1 / (long double)k;
  while (iter < n) {
    for (int i = 1; i < lim; i++) dp[next][i] = 0;
    for (int i = 1; i < lim; i++) {
      long double prob_inc = ((long double)1 / (i + 1));
      long double prob_ninc = 1 - (long double)1 / (long double)(i + 1);
      dp[next][i] += dp[cur][i] * (1 - prob_inc * inverse_k);
      dp[next][i + 1] += dp[cur][i] * (prob_inc)*inverse_k;
      long double avg = (i + 1) / (long double)2;
      ans += inverse_k *
             (avg * dp[cur][i] * prob_ninc + (1 - prob_ninc) * i * dp[cur][i]);
    }
    swap(cur, next);
    iter++;
  }
  cout << fixed << setprecision(12) << ans * k << '\n';
  return 0;
}
