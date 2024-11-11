#include <bits/stdc++.h>
using namespace std;
long long Mod = 998244353;
long long Comb[80][80];
long long N, K;
long long Ans[80];
vector<int> G[4100], Ch[4100];
long long Dp[4100][80];
void dfs(int x, int fa) {
  for (auto &y : G[x]) {
    if (y != fa) {
      dfs(y, x);
      Ch[x].push_back(y);
    }
  }
  Dp[x][0] = 1;
  for (int i = 2; i <= K; i += 2) {
    for (auto &y : Ch[x]) {
      for (int j = 0; j + 2 <= i; j += 2) {
        Dp[x][i] = (Dp[x][i] + Dp[x][j] * Dp[y][i - 2 - j]) % Mod;
      }
    }
  }
}
long long T[80];
void sfd(int x) {
  for (int i = 0; i <= K; i += 2) {
    Ans[i] = (Ans[i] + Dp[x][i]) % Mod;
  }
  for (auto &y : Ch[x]) {
    for (int i = 0; i <= K; i += 2) T[i] = 0;
    for (int i = 0; i <= K; i += 2) {
      for (int j = 0; i + j <= K; j += 2) {
        T[i + j] = (T[i + j] + Dp[y][i] * Dp[y][j]);
      }
    }
    for (int i = 0; i <= K; i += 2) {
      for (int j = 0; j + 2 <= i; j += 2) {
        Dp[y][i] = (Dp[y][i] + T[j] * Dp[x][i - 2 - j]) % Mod;
      }
    }
    sfd(y);
  }
}
void solve(int _N, long long *ans) {
  N = _N;
  for (int i = 1; i <= N; ++i) G[i].clear();
  for (int i = 1; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= N; ++i) Ch[i].clear();
  memset(Dp, 0x00, sizeof Dp);
  dfs(1, 0);
  memset(Ans, 0x00, sizeof Ans);
  sfd(1);
  memcpy(ans, Ans, sizeof Ans);
}
int main() {
  for (int i = 0; i < 80; ++i) {
    Comb[i][0] = Comb[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      Comb[i][j] = (Comb[i - 1][j] + Comb[i - 1][j - 1]) % Mod;
    }
  }
  long long N1, N2;
  cin >> N1 >> N2 >> K;
  if (K & 1) {
    cout << 0 << endl;
    return 0;
  }
  long long ans1[80], ans2[80];
  solve(N1, ans1);
  solve(N2, ans2);
  long long ans = 0;
  for (int i = 0; i <= K; i += 2) {
    ans = (ans + Comb[K][i] * ans1[i] % Mod * ans2[K - i] % Mod) % Mod;
  }
  cout << ans << endl;
  return 0;
}
