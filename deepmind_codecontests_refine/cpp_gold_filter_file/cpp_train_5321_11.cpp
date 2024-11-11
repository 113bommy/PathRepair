#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 110;
int n, a, p, _;
double c, t;
pair<int, int> prob[N];
double dp[N][1010], pd[N][1010], pw[N];
void solve() {
  scanf("%d", &n);
  scanf("%lf%lf", &c, &t);
  int sp = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &p);
    prob[i] = make_pair(a, p);
  }
  sort(prob, prob + n);
  reverse(prob, prob + n);
  sp = 0;
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++)
      for (int k = 0; k < sp + 1; k++) pd[j][k] = dp[j][k];
    for (int j = 0; j < i + 2; j++)
      for (int k = 0; k < sp + prob[i].second + 1; k++) {
        dp[j][k] = 1e30;
      }
    for (int j = 0; j < i + 1; j++)
      for (int k = 0; k < sp + 1; k++) {
        dp[j][k] = min(dp[j][k], pd[j][k]);
        dp[j + 1][k + prob[i].second] =
            min(dp[j + 1][k + prob[i].second],
                pd[j][k] + prob[i].first * pw[j + 1]);
      }
    sp += prob[i].second;
  }
  int sco = 0;
  for (int j = 0; j <= n; j++)
    for (int k = 0; k <= sp; k++)
      if (dp[j][k] < 1e20) {
        double x = sqrt(dp[j][k] / c) - 1 / c;
        x = max(x, 0.0);
        if (dp[j][k] / (1 + c * x) + x + 10 * j <= t) {
          sco = max(sco, k);
        }
      }
  printf("%d\n", sco);
}
int main() {
  pw[0] = 1;
  for (int i = 1; i < 101; i++) pw[i] = pw[i - 1] / 0.9;
  for (scanf("%d", &_); _; _--) {
    solve();
  }
}
