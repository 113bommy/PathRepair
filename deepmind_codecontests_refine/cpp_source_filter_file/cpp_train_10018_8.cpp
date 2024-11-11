#include <bits/stdc++.h>
using namespace std;
const long long N = 2051;
const long long INF = 1e18 + 230;
long long dp[N][N];
long long pmax[N + 1];
long long c[2 * N];
void add_person(long long L, long long S) {
  for (long long alr = N - 1; alr >= 0; alr--) {
    if (alr == 0) {
      dp[L][alr] = max(dp[L][alr], *max_element(pmax, pmax + L + 1));
    }
    if (dp[L][alr] == -INF) continue;
    long long nw = alr + 1;
    long long pc = c[L] - S;
    for (long long nx = L; nw >= 0; nx++, nw /= 2) {
      if (nx > L) pc += c[nx] * nw;
      dp[nx][nw] = max(dp[nx][nw], dp[L][alr] + pc);
      if (nw == 0) {
        pmax[nx] = max(pmax[nx], dp[L][alr] + pc);
        break;
      }
    }
  }
}
void init() {
  for (long long i = 0; i < N; i++) {
    for (long long j = 0; j < N; j++) {
      dp[i][j] = -INF;
    }
    dp[i][0] = 0;
    pmax[i] = 0;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  long long n, useless;
  cin >> n >> useless;
  vector<long long> l(n);
  vector<long long> s(n);
  for (auto &t : l) {
    cin >> t;
  }
  for (auto &t : s) {
    cin >> t;
  }
  for (long long i = 1; i <= n + useless; i++) {
    cin >> c[i];
  }
  reverse(l.begin(), l.end());
  reverse(s.begin(), s.end());
  for (long long i = 0; i < n; i++) {
    add_person(l[i], s[i]);
  }
  long long ans = -INF;
  for (long long i = 0; i < N; i++) {
    ans = max(ans, dp[i][1]);
  }
  cout << ans << endl;
}
