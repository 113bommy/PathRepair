#include <bits/stdc++.h>
using namespace std;
namespace {
const long long MAX_N = 6;
const long long MAX_T = 1 << MAX_N;
long double dp[MAX_N + 1][MAX_T];
long double win[MAX_N][MAX_T];
long double prob[MAX_T][MAX_T];
void Win(long long round, long long lef, long long rig) {
  if (round == 0) {
    assert(lef + 1 == rig);
    win[round][lef] = 1.0;
    return;
  }
  const long long mid = (lef + rig) / 2;
  Win(round - 1, lef, mid);
  Win(round - 1, mid, rig);
  for (auto a = (long long)(lef); a < (long long)(mid); ++a) {
    for (auto b = (long long)(mid); b < (long long)(rig); ++b) {
      win[round][a] += win[round - 1][a] * prob[a][b] * win[round - 1][b];
      win[round][b] += win[round - 1][b] * prob[b][a] * win[round - 1][a];
    }
  }
}
void Chmax(long double& a, long double b) { a = max(a, b); }
void Rec(long long round, long long lef, long long rig, long long score) {
  if (round == 0) {
    assert(lef + 1 == rig);
    dp[round][lef] = 0;
    return;
  }
  const long long mid = (lef + rig) >> 1;
  Rec(round - 1, lef, mid, score / 2);
  Rec(round - 1, mid, rig, score / 2);
  for (auto a = (long long)(lef); a < (long long)(mid); ++a) {
    for (auto b = (long long)(mid); b < (long long)(rig); ++b) {
      Chmax(dp[round][a],
            dp[round - 1][a] + win[round][a] * score + dp[round - 1][b]);
      Chmax(dp[round][b],
            dp[round - 1][b] + win[round][b] * score + dp[round - 1][a]);
    }
  }
}
void Solve(long long test_num) {
  (void)test_num;
  long long N;
  cin >> N;
  const long long T = 1 << N;
  for (auto i = (long long)(0); i < (long long)(T); ++i) {
    for (auto j = (long long)(0); j < (long long)(T); ++j) {
      cin >> prob[i][j];
      prob[i][j] /= 100;
    }
  }
  memset(dp, 0, sizeof(dp));
  memset(win, 0, sizeof(win));
  Win(N, 0, T);
  Rec(N, 0, T, 1 << (N - 1));
  long double res = 0;
  for (auto t = (long long)(0); t < (long long)(T); ++t)
    res = max(res, dp[N][t]);
  cout << setprecision(10) << res << endl;
}
void Init() {}
}  // namespace
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(1223);
  Init();
  long long tests = 1;
  for (auto test = (long long)(1); test < (long long)(tests + 1); ++test) {
    Solve(test);
  }
  return 0;
}
