#include <bits/stdc++.h>
using namespace std;
const int INFTY = 1 << 25;
const int NOTUSED = 1 << 30;
string E;
int N, P, M;
int dp[10005][105][2];
int cur[10005];
int A[10005][2];
int getdp(int x, int m, int t) {
  if (dp[x][m][t] != NOTUSED) {
    return dp[x][m][t];
  }
  if (t == 0)
    dp[x][m][t] = INFTY;
  else
    dp[x][m][t] = -INFTY;
  if (M <= P) {
    for (int i = 0; i < m; i++) {
      if (t == 0)
        dp[x][m][t] = min(dp[x][m][t],
                          getdp(A[x][0], i, 0) - getdp(A[x][1], m - 1 - i, 1));
      else
        dp[x][m][t] = max(dp[x][m][t],
                          getdp(A[x][0], i, 1) - getdp(A[x][1], m - 1 - i, 0));
    }
    for (int i = 0; i <= m; i++) {
      if (t == 0)
        dp[x][m][t] =
            min(dp[x][m][t], getdp(A[x][0], i, 0) + getdp(A[x][1], m - i, 0));
      else
        dp[x][m][t] =
            max(dp[x][m][t], getdp(A[x][0], i, 1) + getdp(A[x][1], m - i, 1));
    }
  } else {
    for (int i = 0; i <= m; i++) {
      if (t == 0)
        dp[x][m][t] =
            min(dp[x][m][t], getdp(A[x][0], i, 0) - getdp(A[x][1], m - i, 1));
      else
        dp[x][m][t] =
            max(dp[x][m][t], getdp(A[x][0], i, 1) - getdp(A[x][1], m - i, 0));
    }
    for (int i = 0; i < m; i++) {
      if (t == 0)
        dp[x][m][t] = min(dp[x][m][t],
                          getdp(A[x][0], i, 0) + getdp(A[x][1], m - 1 - i, 0));
      else
        dp[x][m][t] = max(dp[x][m][t],
                          getdp(A[x][0], i, 1) + getdp(A[x][1], m - 1 - i, 1));
    }
  }
  return dp[x][m][t];
}
int main() {
  ios::sync_with_stdio(0);
  cin >> E >> P >> M;
  N = E.size();
  if (N == 1) {
    cout << E << "\n";
    return 0;
  }
  for (int i = 0; i < 10005; i++)
    for (int j = 0; j < 105; j++) dp[i][j][0] = dp[i][j][1] = NOTUSED;
  memset(A, -1, sizeof(A));
  vector<int> stk;
  int sz = 0;
  for (int i = 0; i < N; i++) {
    if ('0' <= E[i] && E[i] <= '9') {
      if (!stk.empty()) A[stk.back()][cur[stk.back()]] = sz;
      dp[sz][0][0] = dp[sz][0][1] = E[i] - '0';
      for (int j = 1; j <= min(M, P); j++) {
        dp[sz][j][0] = INFTY;
        dp[sz][j][1] = -INFTY;
      }
      sz++;
    } else if (E[i] == '(') {
      if (!stk.empty()) A[stk.back()][cur[stk.back()]] = sz;
      stk.push_back(sz++);
    } else if (E[i] == ')') {
      stk.pop_back();
    } else if (E[i] == '?') {
      cur[stk.back()] = 1;
    }
  }
  if (M <= P)
    cout << getdp(0, M, 1) << "\n";
  else
    cout << getdp(0, P, 1) << "\n";
  return 0;
}
