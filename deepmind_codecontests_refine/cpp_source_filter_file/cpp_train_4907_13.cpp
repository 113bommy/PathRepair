#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC target(sse, sse2, sse3, ssse3, sse4, popcnt, tune = native)
#pragma GCC optimize(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           \
    "-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", \
    3)
using namespace std;
const long long MAXN = 447;
long long n, m;
vector<long long> city;
vector<pair<pair<long long, long long>, pair<long long, long long> > > car;
void read() {
  cin >> n >> m;
  city.resize(n);
  for (long long i = 0; i < n; i++) cin >> city[i];
  car.resize(m);
  for (long long i = 0; i < m; i++) {
    cin >> car[i].first.second >> car[i].second.first >> car[i].second.second >>
        car[i].first.first;
  }
}
long long dp[2][MAXN][MAXN], op[2][MAXN][MAXN];
long long get_hull(long long &l, long long &r, long long z) {
  long long res = 1e17 + 47;
  for (long long opt = op[z][l][r]; opt < r + 1; opt++) {
    res = min(res, max(city[r] - city[opt], dp[z][l][opt]));
    if (city[r] - city[opt] <= dp[z][l][opt]) {
      op[z ^ 1][l][r] = opt;
      return res;
    }
  }
  op[z ^ 1][l][r] = r - 1;
  return res;
}
bool good(pair<pair<long long, long long>, pair<long long, long long> > &a,
          long long z, long long &l, long long &r) {
  if (a.first.first == z && a.first.second - 1 == l && a.second.first - 1 == r)
    return true;
  return false;
}
void solve() {
  sort(car.begin(), car.end());
  reverse(car.begin(), car.end());
  for (long long l = 0; l < n; l++)
    for (long long r = l; r < n; r++) dp[0][l][r] = city[r] - city[l];
  long long ans = 0;
  for (long long l = 0; l < n; l++) {
    for (long long r = l; r < n; r++) {
      while ((long long)(car.size()) > 0 && good(car.back(), 0, l, r))
        ans = max(ans, car.back().second.second * dp[0][l][r]), car.pop_back();
    }
  }
  for (long long z = 1; z < n; z++) {
    long long kek = z % 2;
    for (long long l = 0; l < n; l++) {
      memset(dp[kek][l], 0, sizeof(dp[kek][l]));
      memset(op[kek][l], 0, sizeof(op[kek][l]));
      for (long long r = l; r < n; r++) {
        dp[kek][l][r] = get_hull(l, r, kek ^ 1);
        while ((long long)(car.size()) > 0 && good(car.back(), z, l, r))
          ans = max(ans, car.back().second.second * dp[kek][l][r]),
          car.pop_back();
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  read();
  solve();
}
