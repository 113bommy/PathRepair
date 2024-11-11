#include <bits/stdc++.h>
using namespace std;
int N;
int A[303030];
signed long long dp[303030][22];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  scanf("%d", &N);
  for (i = 0; i < (N); i++) scanf("%d", &A[i]), A[i] /= 100;
  for (i = 0; i < (N + 1); i++)
    for (j = 0; j < (22); j++) dp[i][j] = 1LL << 60;
  dp[0][0] = 0;
  for (i = 0; i < (N); i++) {
    for (j = 0; j < (22); j++)
      if (dp[i][j] < 1LL << 60) {
        for (int use = 0; use <= min(j, A[i]); use++) {
          dp[i + 1][j - use] = min(dp[i + 1][j - use], dp[i][j] + A[i] - use);
        }
        if (j < 20)
          dp[i + 1][j + A[i] / 10] =
              min(dp[i + 1][j + A[i] / 10], dp[i][j] + A[i]);
      }
  }
  signed long long mi = 1LL << 60;
  for (i = 0; i < (22); i++) mi = min(mi, dp[N][i] * 100);
  cout << mi << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
