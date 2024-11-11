#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
int upmin(T1 &x, T2 v) {
  if (x > v) {
    x = v;
    return 1;
  }
  return 0;
}
template <class T1, class T2>
int upmax(T1 &x, T2 v) {
  if (x < v) {
    x = v;
    return 1;
  }
  return 0;
}
const int INF = 0x3f3f3f3f;
int N;
vector<string> C;
vector<int> R, B;
void init() {
  cin >> N;
  C = vector<string>(N);
  R = B = vector<int>(N);
  for (int i = 0; i < N; ++i) cin >> C[i] >> R[i] >> B[i];
}
const int MAXN = 16;
int dp[1 << MAXN][MAXN * MAXN];
int sumrcost, sumbcost;
void preprocess() {
  for (int i = 0; i < N; ++i) sumrcost += R[i], sumbcost += B[i];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < 1 << N; ++i)
    for (int j = 0; j < N * N; ++j)
      if (dp[i][j] != -1) {
        int rc = 0, bc = 0;
        for (int k = 0; k < N; ++k)
          if (i & 1 << k) rc += C[k] == "R", bc += C[k] == "B";
        for (int k = 0; k < N; ++k)
          if (~i & 1 << k) {
            int nrc = j + min(rc, R[k]);
            int brc = dp[i][j] + min(bc, B[k]);
            upmax(dp[i | 1 << k][nrc], brc);
          }
      }
}
void solve() {
  int ans = INF;
  for (int i = 0; i <= N * N; ++i)
    if (dp[(1 << N) - 1][i] != -1)
      upmin(ans, N + max(sumrcost - i, sumbcost - dp[(1 << N) - 1][i]));
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  init();
  preprocess();
  solve();
  return 0;
}
