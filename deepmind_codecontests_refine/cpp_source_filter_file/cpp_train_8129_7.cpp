#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int N = 1007;
int n, m, a[N][N], c[N * N], R, C, pre[N];
vector<pair<int, int> > g[N * N];
long long inv[N * N];
inline long long sqr(long long x) { return x * x % MOD; }
int main() {
  scanf("%d%d", &n, &m);
  int tot = 0;
  for (int i = int(1); i <= int(n); ++i)
    for (int j = int(1); j <= int(m); ++j)
      scanf("%d", &a[i][j]), c[++tot] = a[i][j];
  scanf("%d%d", &R, &C);
  sort(c + 1, c + 1 + tot);
  tot = unique(c + 1, c + 1 + tot) - c - 1;
  for (int i = int(1); i <= int(n); ++i)
    for (int j = int(1); j <= int(m); ++j) {
      int t = lower_bound(c + 1, c + 1 + tot, a[i][j]) - c;
      g[t].push_back(pair<int, int>(i, j));
    }
  for (int i = int(1); i <= int(tot); ++i)
    pre[i] = pre[i - 1] + (int)g[i].size();
  inv[0] = inv[1] = 1;
  for (int i = int(2); i <= int(N * N - 1); ++i)
    inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
  int cur = lower_bound(c + 1, c + 1 + tot, a[R][C]) - c;
  if (cur == 1) {
    cout << 0 << endl;
    return 0;
  }
  long long prob = inv[pre[cur - 1]], exp = 0,
            sos = (sqr(R) + sqr(C)) % MOD * inv[pre[cur - 1]] % MOD,
            rsum = R * inv[pre[cur - 1]] % MOD,
            csum = C * inv[pre[cur - 1]] % MOD;
  for (int i = int(cur - 1); i >= int(2); --i) {
    long long tmp_prob = prob, tmp_exp = exp, tmp_rsum = rsum, tmp_csum = csum,
              tmp_sos = sos;
    for (pair<int, int> p : g[i]) {
      int x = p.first, y = p.second;
      (tmp_prob += prob * inv[pre[i - 1]] % MOD) %= MOD;
      (tmp_sos += (sqr(x) + sqr(y)) * prob % MOD * inv[pre[i - 1]] % MOD) %=
          MOD;
      (tmp_rsum += x * prob % MOD * inv[pre[i - 1]] % MOD) %= MOD;
      (tmp_csum += y * prob % MOD * inv[pre[i - 1]] % MOD) %= MOD;
      (tmp_exp += exp * inv[pre[i - 1]] % MOD + sos * inv[pre[i - 1]] % MOD +
                  MOD - 2 * x * rsum % MOD * inv[pre[i - 1]] % MOD + MOD -
                  2 * y * csum % MOD * inv[pre[i - 1]] % MOD +
                  prob * (sqr(x) + sqr(y)) % MOD * inv[pre[i - 1]] % MOD) %=
          MOD;
    }
    prob = tmp_prob;
    exp = tmp_exp;
    sos = tmp_sos;
    rsum = tmp_rsum;
    csum = tmp_csum;
  }
  long long ans = 0;
  for (pair<int, int> p : g[1]) {
    int x = p.first, y = p.second;
    ans += exp + sos + MOD - 2 * x * rsum % MOD + MOD - 2 * y * csum % MOD +
           prob * (sqr(x) + sqr(y)) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}
