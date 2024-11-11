#include <bits/stdc++.h>
using namespace std;
int N, M;
void fix(vector<vector<int>>& mat) {
  vector<vector<int>> ne(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      ne[i][j] = mat[j][i];
    }
  }
  mat = ne;
}
vector<int> fix2(vector<vector<int>>& mat) {
  vector<int> res(N);
  for (int i = 0; i < N; i++) {
    int t = 0;
    for (int j = 0; j < M; j++) {
      if (mat[i][j]) t |= (1 << j);
    }
    res[i] = t;
  }
  return res;
}
bool check(int c) {
  int a = 0;
  a |= ((c >> 1) & 1) << 1;
  a |= ((c >> 2) & 1) << 2;
  a |= ((c >> 4) & 1) << 4;
  a |= ((c >> 5) & 1) << 5;
  int b = 0;
  b |= ((c >> 0) & 1) << 0;
  b |= ((c >> 1) & 1) << 1;
  b |= ((c >> 3) & 1) << 3;
  b |= ((c >> 4) & 1) << 4;
  return (__builtin_popcount(a) % 2 == 0 || __builtin_popcount(b) % 2 == 0);
}
void solve() {
  cin >> N >> M;
  vector<vector<int>> mat(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char c;
      cin >> c;
      c -= '0';
      mat[i][j] = c;
    }
  }
  if (min(N, M) == 1) cout << 0 << endl, exit(0);
  if (min(N, M) > 3) cout << -1 << endl, exit(0);
  if (M > N) swap(N, M), fix(mat);
  vector<int> arr = fix2(mat);
  vector<vector<int>> dp(N, vector<int>(1 << M, INT_MAX));
  for (int i = 0; i < 1 << M; i++)
    dp[N - 1][i] = __builtin_popcount(i ^ arr[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j < 1 << (2 * M); j++) {
      if (M == 2 && __builtin_popcount(j) % 2 == 0) continue;
      if (M == 3 && check(j)) continue;
      int b = j >> M;
      int a = 0;
      for (int k = 0; k < M; k++) a |= ((j >> k) & 1) << k;
      int c = __builtin_popcount(a ^ arr[i]);
      dp[i][a] = min(dp[i][a], c + dp[i + 1][b]);
    }
  }
  cout << *min_element(dp[0].begin(), dp[0].end()) << endl;
}
int main() {
  int T = 1;
  while (T--) solve();
}
