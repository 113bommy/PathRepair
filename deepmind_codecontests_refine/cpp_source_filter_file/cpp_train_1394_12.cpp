#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using pii = std::pair<long long, long long>;
using namespace std;
long long n, k, x, cnt[2], dp[55][55][55], fact[55] = {0}, nCr[55][55] = {0};
class CGregAndFriends {
 public:
  void solve(std::istream& in, std::ostream& out) {
    fact[0] = 1;
    for (long long i = (1); i < (52); i++) fact[i] = (fact[i - 1] * i) % MOD;
    for (long long i = (0); i < (52); i++)
      for (long long j = (0); j < (i + 1); j++) nCr[i][j] = nCr_mod(i, j);
    cnt[0] = cnt[1] = 0;
    in >> n >> k;
    for (long long i = (0); i < (n); i++) {
      in >> x;
      cnt[x / 100]++;
    }
    for (long long i = (0); i < (n + 3); i++)
      for (long long j = (0); j < (cnt[0] + 2); j++)
        for (long long k = (0); k < (cnt[1] + 2); k++) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    for (long long trips = (0); trips < (n + 1); trips++) {
      if (dp[trips][cnt[0]][cnt[1]]) {
        out << 2 * trips - 1 << "\n"
            << (dp[trips][cnt[0]][cnt[1]]) % MOD << "\n";
        return;
      }
      for (long long i = (0); i < (cnt[0] + 1); i++)
        for (long long j = (0); j < (cnt[1] + 1); j++)
          if (dp[trips][i][j]) {
            if (dp[trips][i][j] >= MOD) dp[trips][i][j] %= MOD;
            for (long long numf = (0); numf < (cnt[0] + 1 - i); numf++) {
              if (numf * 50 > k) break;
              for (long long numh = (0); numh < (cnt[1] + 1 - j); numh++) {
                if (!numf && !numh) continue;
                if (numf * 50 + numh * 100 > k) break;
                for (long long a = (0); a < (i + numf + 1); a++)
                  for (long long b = (0); b < (j + numh + 1); b++)
                    if (a || b || (i + numf == cnt[0] && j + numh == cnt[1]))
                      dp[trips + 1][i + numf - a][j + numh - b] +=
                          (((dp[trips][i][j] * nCr[cnt[0] - i][numf]) % MOD) *
                           ((nCr[cnt[1] - j][numh] *
                             (((nCr[i + numf][a]) * (nCr[j + numh][b])) %
                              MOD)) %
                            MOD)) %
                          MOD;
              }
            }
          }
    }
    out << "-1\n0\n";
  }
  long long nCr_mod(long long x, long long r) {
    long long num = fact[x];
    long long denom = (mod_inv(fact[r]) * mod_inv(fact[x - r])) % MOD;
    return (num * denom) % MOD;
  }
  long long mod_inv(long long x) { return mod_exp(x, MOD - 2); }
  long long mod_exp(long long x, long long p) {
    long long result = 1;
    while (p > 0) {
      if (p & 1) {
        result *= x;
        if (result >= MOD) result %= MOD;
      }
      x *= x;
      if (x >= MOD) x %= MOD;
      p /= 2;
    }
    return result % MOD;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  CGregAndFriends solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
