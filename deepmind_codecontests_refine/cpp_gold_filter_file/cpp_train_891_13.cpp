#include <bits/stdc++.h>
using namespace std;
vector<int> v[2];
int dp[7005][2];
int cnt[7005][2];
int n, k1, k2, x;
void build_dp(int vtx, int player) {
  int other = 1 - player;
  if (dp[vtx][player] == 0)
    for (int i = 0; i < (int)v[other].size(); i++) {
      int from =
          (vtx - v[other][i] + n) % n == 0 ? n : (vtx - v[other][i] + n) % n;
      if (dp[from][other] != -1) continue;
      dp[from][other] = 1;
      build_dp(from, other);
    }
  if (dp[vtx][player] == 1)
    for (int i = 0; i < (int)v[other].size(); i++) {
      int from =
          (vtx - v[other][i] + n) % n == 0 ? n : (vtx - v[other][i] + n) % n;
      if (dp[from][other] != -1) continue;
      cnt[from][other]++;
      if (cnt[from][other] < (int)v[other].size()) continue;
      dp[from][other] = 0;
      build_dp(from, other);
    }
}
int main() {
  ios::sync_with_stdio(0);
  ;
  memset(dp, -1, sizeof dp);
  cin >> n >> k1;
  for (int i = 0; i < k1; i++) {
    cin >> x;
    v[0].push_back(x);
  }
  cin >> k2;
  for (int i = 0; i < k2; i++) {
    cin >> x;
    v[1].push_back(x);
  }
  dp[1][0] = 0;
  dp[1][1] = 0;
  build_dp(1, 0);
  build_dp(1, 1);
  for (int i = 2; i <= n; i++) {
    if (dp[i][0] == 0) cout << "Lose ";
    if (dp[i][0] == 1) cout << "Win ";
    if (dp[i][0] == -1) cout << "Loop ";
  }
  cout << endl;
  for (int i = 2; i <= n; i++) {
    if (dp[i][1] == 0) cout << "Lose ";
    if (dp[i][1] == 1) cout << "Win ";
    if (dp[i][1] == -1) cout << "Loop ";
  }
}
