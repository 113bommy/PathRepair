#include <bits/stdc++.h>
using namespace std;
void chmin(int64_t& a, int64_t b) { a = min(a, b); }
int main() {
  int N, A[50], B[50];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  map<int, vector<int>> mp;
  for (int i = 0; i < N; i++) mp[A[i]].push_back(B[i]);
  vector<pair<int, vector<int>>> vs;
  for (auto& p : mp) {
    sort(p.second.rbegin(), p.second.rend());
    vs.push_back(p);
  }
  reverse(vs.begin(), vs.end());
  int sz = vs.size();
  const int64_t INF = 1e18;
  static int64_t dp[51][51][5001];
  for (int i = 0; i <= sz; i++)
    for (int j = 0; j <= N; j++)
      for (int k = 0; k <= 5000; k++) dp[i][j][k] = INF;
  dp[0][0][0] = 0;
  int num = 0, sum = 0;
  for (int i = 0; i < sz; i++) {
    int64_t a = vs[i].first;
    auto& bs = vs[i].second;
    int kd = 0;
    for (int use = 0; use <= bs.size(); use++) {
      int need = bs.size() - use;
      if (use > 0) kd += bs[use - 1];
      for (int j = need; j <= num; j++) {
        for (int k = 0; k <= sum; k++)
          chmin(dp[i + 1][j - need + use][k + kd], dp[i][j][k] + a * use);
      }
    }
    num += bs.size();
    for (int b : bs) sum += b;
  }
  double ans = INF;
  for (int j = 0; j <= N; j++)
    for (int k = 1; k <= 5000; k++) {
      double res = (double)dp[sz][j][k] / k;
      ans = min(ans, res);
    }
  int64_t Ans = ceil(ans * 1000);
  cout << Ans << endl;
  return 0;
}
