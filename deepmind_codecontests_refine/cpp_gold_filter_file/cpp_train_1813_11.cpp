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
vector<int> P;
void init() {
  cin >> N;
  P = vector<int>(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }
}
int inv_cnt;
vector<int> dp;
void preprocess() {
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      inv_cnt += P[i] > P[j];
    }
  }
  dp = vector<int>(inv_cnt + 1);
  dp[1] = 1;
  for (int i = 0; i + 2 <= inv_cnt; ++i) {
    dp[i + 2] = dp[i] + 4;
  }
}
void solve() { cout << dp[inv_cnt] << endl; }
signed main() {
  ios::sync_with_stdio(0);
  init();
  preprocess();
  solve();
  return 0;
}
