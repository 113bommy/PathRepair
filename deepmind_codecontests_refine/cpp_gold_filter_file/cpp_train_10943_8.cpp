#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
const int N = 2228;
const ll MOD = 998244353;
int n;
ll f[N][N];
struct Fen {
  int fen[N];
  void ad(int x, int y) {
    for (int i = x; i < n; i |= (i + 1)) {
      fen[i] += y;
    }
  }
  void cl() { fill(fen, fen + n, 0); }
  int gt(int x) {
    int ans = 0;
    for (int i = x; --i >= 0; i &= (i + 1)) {
      ans += fen[i];
    }
    return ans;
  }
};
bool wup[N];
bool wdown[N];
Fen all;
Fen diff;
void cl() {
  all.cl();
  diff.cl();
  fill(wup, wup + n, 0);
  fill(wdown, wdown + n, 0);
}
int a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(20);
  cin >> n;
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i][0] = f[i - 1][0] * i % MOD;
    for (int j = 1; j <= i; ++j) {
      f[i][j] = (j - 1) * f[i - 1][max(j - 2, 0)] + (i - j) * f[i - 1][j - 1];
      f[i][j] %= MOD;
    }
  }
  ll ans = 0;
  cl();
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    ans *= (n - i);
    ans += (a[i] - all.gt(a[i]));
    ans %= MOD;
    all.ad(a[i], 1);
  }
  for (int i = 1; i < n; ++i) {
    ans *= f[n][n];
    ans %= MOD;
    cl();
    int diffs = 0;
    for (int j = 0; j < n; ++j) {
      int r = n - j - 1;
      int k = n - j - diffs;
      assert(k >= 0);
      int x;
      cin >> x;
      --x;
      if (wdown[a[j]]) {
        int tot = x - all.gt(x);
        int df = diff.gt(x);
        int sm = tot - df;
        assert(df >= 0 && sm >= 0);
        if (df) {
          ans += df * f[r][k];
        }
        if (sm) {
          assert(k >= 1);
          ans += sm * f[r][k - 1];
        }
      } else {
        int tot = x - (a[j] < x) - all.gt(x);
        int df = diff.gt(x);
        int sm = tot - df;
        assert(df >= 0 && sm >= 0);
        if (df) {
          assert(k >= 1);
          ans += df * f[r][k - 1];
        }
        if (sm) {
          assert(k >= 2);
          ans += sm * f[r][k - 2];
        }
        ++diffs;
        diff.ad(a[j], 1);
      }
      all.ad(x, 1);
      if (wup[x]) {
        diff.ad(x, -1);
        --diffs;
      }
      wdown[x] = true;
      wup[a[j]] = true;
      a[j] = x;
      ans %= MOD;
    }
  }
  cout << ans << "\n";
}
