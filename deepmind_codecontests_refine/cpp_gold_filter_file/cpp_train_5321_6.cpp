#include <bits/stdc++.h>
const long long INF = 1e18L + 1;
const int IINF = 1e9 + 1;
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << '=' << h << endl;
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
long double t, c;
long double fn_val(long double x, long double probs_solved,
                   long double cum_diff) {
  return (1 + c * x) * (t - x - 10.0 * probs_solved) - cum_diff;
}
long double dp[101][101][1001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tc;
  cin >> tc;
  for (long long _ = (long long)0; _ < (long long)tc; _++) {
    long long n;
    cin >> n;
    long long msc = 10 * n;
    for (long long i = (long long)0; i < (long long)n + 1; i++) {
      for (long long j = (long long)0; j < (long long)n + 1; j++) {
        for (long long s = (long long)0; s < (long long)msc + 1; s++) {
          dp[i][j][s] = INF;
        }
      }
    }
    cin >> c >> t;
    vector<pair<long double, long long> > problems(n + 1);
    for (long long i = (long long)1; i < (long long)n + 1; i++) {
      cin >> problems[i].first >> problems[i].second;
    }
    sort(problems.rbegin(), problems.rend() - 1);
    for (long long i = (long long)0; i < (long long)n + 1; i++) {
      long long val = problems[i].second;
      long double diff = problems[i].first;
      long double sk = 1.0;
      dp[i][0][0] = 0.0;
      for (long long j = (long long)1; j < (long long)i + 1; j++) {
        sk *= 0.9;
        for (long long s = (long long)0; s < (long long)msc + 1; s++) {
          if (s >= val) {
            dp[i][j][s] =
                min(dp[i - 1][j][s], dp[i - 1][j - 1][s - val] + diff / sk);
          } else {
            dp[i][j][s] = dp[i - 1][j][s];
          }
        }
      }
    }
    long long res = 0;
    for (long long s = msc; s >= 1 and res == 0; s--) {
      for (long long j = (long long)1; j < (long long)n + 1; j++) {
        if (dp[n][j][s] < 1e15) {
          long double st = 0.0, fn = t;
          for (long long __ = (long long)0; __ < (long long)80; __++) {
            long double md1 = (3.0 * st + 2.0 * fn) / 5.0,
                        md2 = (2.0 * st + 3.0 * fn) / 5.0;
            if (fn_val(md1, j, dp[n][j][s]) > fn_val(md2, j, dp[n][j][s])) {
              fn = md2;
            } else {
              st = md1;
            }
          }
          if (fn_val(st, j, dp[n][j][s]) > 0) {
            res = max(res, s);
          }
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}
