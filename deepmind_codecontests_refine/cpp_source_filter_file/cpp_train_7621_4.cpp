#include <bits/stdc++.h>
using namespace std;
const int MAXN = 52;
const int MOD = 998244353;
int n, l[MAXN], r[MAXN];
int64_t rev[MAXN], rev_fact[MAXN], f[MAXN][MAXN];
void readInput() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> l[n - i + 1] >> r[n - i + 1];
  }
}
int64_t comb(int n, int k) {
  int64_t res = rev_fact[k];
  for (int i = n - k + 1; i <= n; ++i) {
    res = res * i % MOD;
  }
  return res;
}
int64_t candiesPartition(int n, int S) {
  int64_t res = (S == 0);
  for (int i = 1; i <= min(n, S); ++i) {
    int64_t cnt = comb(n, i);
    cnt = cnt * comb(S - 1, i - 1);
    res = (res + cnt) % MOD;
  }
  return res;
}
int64_t pw(int n, int k) {
  if (k == 0) return 1;
  int64_t tmp = pw(n, k / 2);
  if (k % 2) return tmp * tmp % MOD * n % MOD;
  return tmp * tmp % MOD;
}
bool check(int l, int r, int u, int v) { return l <= u && v <= r; }
void solve() {
  rev[0] = rev[1] = 1;
  rev_fact[0] = rev_fact[1] = 1;
  for (int i = 2; i <= n; ++i) {
    rev[i] = MOD - MOD / i * rev[MOD % i] % MOD;
    rev_fact[i] = rev_fact[i - 1] * rev[i] % MOD;
  }
  vector<int> p;
  for (int i = 1; i <= n; ++i) {
    p.push_back(l[i]);
    p.push_back(r[i] + 1);
  }
  sort(p.begin(), p.end());
  p.resize(unique(p.begin(), p.end()) - p.begin());
  vector<pair<int, int> > seg(1);
  for (int i = 0; i + 1 < p.size(); ++i) {
    seg.push_back({p[i], p[i + 1] - 1});
  }
  int m = seg.size() - 1;
  f[0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 0; k <= i; ++k) {
        if (k > 0 &&
            !check(l[i - k + 1], r[i - k + 1], seg[j].first, seg[j].second))
          break;
        if (i == 2 && j == 3 && k == 0) {
        }
        f[i][j] = (f[i][j] +
                   f[i - k][j - 1] *
                       candiesPartition(seg[j].second - seg[j].first + 1, k)) %
                  MOD;
      }
    }
  }
  int64_t totalWays = 1;
  for (int i = 1; i <= n; ++i) {
    totalWays = totalWays * (r[i] - l[i] + 1) % MOD;
  }
  cout << f[n][m] * pw(totalWays, MOD - 2) % MOD << '\n';
}
int main() {
  readInput();
  solve();
}
