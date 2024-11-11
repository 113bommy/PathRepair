#include <bits/stdc++.h>
using namespace std;
vector<vector<long double>> expected_score;
vector<vector<long double>> prob;
vector<vector<long long>> v;
long long N;
void solve() {
  cin >> N;
  v.resize((1 << N), vector<long long>((1 << N)));
  for (long long i = 0; i < 1 << N; i++) {
    for (long long j = 0; j < 1 << N; j++) cin >> v[i][j];
  }
  expected_score.resize(N + 1, vector<long double>((1 << N), 0));
  prob.resize(N + 1, vector<long double>((1 << N), 0));
  long double ans = 0;
  for (long long h = 0; h <= N; h++) {
    for (long long num = 0; num < (1 << N); num++) {
      if (h == 0)
        prob[h][num] = 1;
      else {
        expected_score[h][num] = expected_score[h - 1][num];
        long double toadd = 0;
        long double win_prob = 0;
        for (long long def = 0; def < (1 << N); def++) {
          if ((num >> h) == (def >> h) &&
              (num & (1 << (h - 1))) ^ (def & (1 << (h - 1)))) {
            toadd = max(toadd, expected_score[h - 1][def]);
            prob[h][num] +=
                prob[h - 1][num] * prob[h - 1][def] * (v[num][def]) / 100.0l;
            win_prob +=
                prob[h - 1][num] * prob[h - 1][def] * v[num][def] / 100.0l;
          }
        }
        expected_score[h][num] += toadd + win_prob * (1 << h);
      }
      if (h == N) {
        ans = max(ans, expected_score[h][num]);
      }
    }
  }
  cout << fixed << setprecision(10) << ans / 2.0l << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
