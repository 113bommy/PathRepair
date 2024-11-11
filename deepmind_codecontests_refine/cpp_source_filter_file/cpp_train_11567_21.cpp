#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
const long long INF = 10004205361450474;
void into() {}
long long dp[6][N + 9];
void Get_dp() {
  for (int i = 1; i <= 5; ++i)
    for (int j = 1; j <= N; ++j) {
      dp[i][j] = dp[i - 1][j];
      long long now = j + dp[i - 1][j] + 1;
      for (int k = 1; k <= j; ++k) {
        if (now >= N) {
          dp[i][j] += dp[i - 1][N] * (j - k + 1);
          break;
        }
        dp[i][j] += dp[i - 1][now] + 1;
        now += dp[i - 1][now] + 1;
      }
    }
}
int Query(vector<long long>& p) {
  cout << p.size() << endl;
  for (long long x : p) cout << x << ' ';
  cout << endl;
  int res;
  cin >> res;
  return res;
}
void Get_ans() {
  long long now = 1;
  for (int i = 4; i >= 0; --i) {
    vector<long long> p;
    long long t = now;
    for (int j = 1; j <= now && j <= N; ++j) {
      t += dp[i][min(t, 1LL * N)];
      if (t > INF) break;
      p.push_back(t);
      ++t;
    }
    int x = Query(p);
    if (x == -1) return;
    now = x ? p[x - 1] + 1 : now;
  }
}
void work() {
  Get_dp();
  Get_ans();
}
void outo() {}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
