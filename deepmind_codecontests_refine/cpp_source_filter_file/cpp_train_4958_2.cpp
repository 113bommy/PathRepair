#include <bits/stdc++.h>
#pragma GCC optimization "O2"
#pragma GCC optimization "unroll-loop"
#pragma GCC target("avx2")
using namespace std;
const long long N = 1e5 + 9;
const long long Log2 = 20;
const long long inf = 1e9 + 7;
long long cnt[N], dp[30][N], n, a[N];
long long st, en, res, k;
long long cal(long long l, long long r) {
  while (st > l) {
    st--;
    res += cnt[a[st]];
    cnt[a[st]]++;
  }
  while (st < l) {
    cnt[a[st]]--;
    res -= cnt[a[st]];
    st++;
  }
  while (en > r) {
    cnt[a[en]]--;
    res -= cnt[a[en]];
    en--;
  }
  while (en < r) {
    en++;
    res += cnt[a[en]];
    cnt[a[en]]++;
  }
  return res;
}
void out() {
  for (long long i = 1; i <= k; i++) {
    for (long long j = 1; j <= n; j++) cout << dp[i][j] << " ";
    cout << "\n";
  }
  exit(0);
}
void DAC(long long id, long long l, long long r, long long lf, long long rg) {
  if (l > r) return;
  long long mid = (l + r) / 2, opt, mn = inf;
  for (long long i = lf; i <= min(mid, rg); i++) {
    long long total = cal(i, mid) + dp[id - 1][i - 1];
    if (mn > total) {
      mn = total;
      opt = i;
    }
  }
  dp[id][mid] = mn;
  DAC(id, l, mid - 1, lf, opt);
  DAC(id, mid + 1, r, opt, rg);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if (fopen("tst"
            ".inp",
            "r")) {
    freopen(
        "tst"
        ".inp",
        "r", stdin);
  }
  cin >> n >> k;
  st = en = 1;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  cnt[a[1]] = 1;
  for (long long i = 1; i <= n; i++) dp[1][i] = cal(1, i);
  for (long long i = 2; i <= k; i++) DAC(i, 1, n, 1, n);
  cout << dp[k][n];
}
