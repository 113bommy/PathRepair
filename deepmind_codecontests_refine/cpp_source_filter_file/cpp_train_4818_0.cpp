#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 80;
int n;
int a[MAXN];
int ans[MAXN * (MAXN - 1) / 2 + 1];
void solve() {
  vector<int> zeroes;
  vector<int> ones;
  for (int i = (0); i < (n); ++i)
    if (a[i] == 0)
      zeroes.push_back(i);
    else
      ones.push_back(i);
  int nzeroes = ((int)(zeroes).size()), nones = ((int)(ones).size());
  int mxcost = nones * (n - 1) - nones * (nones - 1) / 2;
  vector<vector<vector<int>>> dp(
      nzeroes + 1,
      vector<vector<int>>(nones + 1, vector<int>(mxcost + 1, INT_MAX)));
  auto upd = [&](int& a, int b) { a = min(a, b); };
  upd(dp[0][0][0], 0);
  for (int zero = (0); zero <= (nzeroes); ++zero)
    for (int one = (0); one <= (nones); ++one)
      for (int cost = (0); cost <= (mxcost); ++cost)
        if (dp[zero][one][cost] != INT_MAX) {
          if (one + 1 <= nones)
            for (int dzero = (0); dzero <= (nzeroes - zero); ++dzero) {
              upd(dp[zero + dzero][one + 1]
                    [cost + abs(zero + one + dzero - ones[one])],
                  dp[zero][one][cost] + dzero * (dzero - 1) / 2);
            }
          if (one == nones && zero < nzeroes) {
            int dzero = nzeroes - zero;
            upd(dp[zero + dzero][one][cost],
                dp[zero][one][cost] + dzero * (dzero - 1) / 2);
          }
        }
  int nans = n * (n - 1) / 2 + 1;
  for (int i = (0); i < (nans); ++i) ans[i] = INT_MAX;
  for (int cost = (0); cost <= (mxcost); ++cost)
    upd(ans[cost], dp[nzeroes][nones][cost]);
  for (int i = (1); i < (nans); ++i) upd(ans[i], ans[i - 1]);
  for (int i = (0); i < (nans); ++i) assert(ans[i] != INT_MAX);
  for (int i = (0); i < (nans); ++i)
    ans[i] = nzeroes * (nzeroes - 1) / 2 - ans[i];
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  solve();
  for (int i = (0); i < (n * (n - 1) / 2); ++i) {
    if (i != 0) printf(" ");
    printf("%d", ans[i]);
  }
  puts("");
}
int main() {
  run();
  return 0;
}
