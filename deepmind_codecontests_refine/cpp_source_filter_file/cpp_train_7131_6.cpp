#include <bits/stdc++.h>
using namespace std;
bool cmp_pair_F_2(pair<int, int> x, pair<int, int> y) {
  return x.first > y.first;
}
bool cmp_pair_S_2(pair<int, int> x, pair<int, int> y) {
  return x.second > y.second;
}
bool cmp_pair_S_1(pair<int, int> x, pair<int, int> y) {
  return x.second < y.second;
}
bool cmp(int x, int y) { return x > y; }
const int N = 152, M = (N * (N - 1)) / 2;
int dp[2][N][M];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, s;
  cin >> n >> k >> s;
  if ((n * (n - 1) / 2) <= s) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort((v).begin(), (v).end());
    int c = 0;
    for (int i = 0; i < k; i++) c += v[i];
    cout << c;
  } else {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++) dp[0][i][j] = 1e9, dp[1][i][j] = 1e9;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int now = i & 1;
      if (!i)
        dp[now][now][0] = x;
      else {
        dp[now][i][0] = dp[1 - now][i - 1][0] + x;
        for (int j = 0; j <= i; j++) {
          for (int t = 0; t <= s; t++) {
            (dp[now][j][t]) = min((dp[now][j][t]), (dp[1 - now][j][t]));
            if (!j)
              (dp[now][j][now]) = min((dp[now][j][now]), (x));
            else {
              if (t >= i - j && dp[1 - now][j - 1][t - (i - j)] != 1e9)
                (dp[now][j][t]) =
                    min((dp[now][j][t]), (dp[1 - now][j - 1][t - (i - j)] + x));
            }
          }
        }
      }
    }
    int c = 1e9;
    for (int i = 0; i <= s; i++) (c) = min((c), (dp[(n - 1) & 1][k - 1][i]));
    cout << c;
  }
  return 0;
}
