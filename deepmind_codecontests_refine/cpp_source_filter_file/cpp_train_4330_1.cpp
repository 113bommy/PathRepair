#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
int dp[2000][2000], need;
vector<string> B;
vector<int> bask[10];
int cost[1000], c[1000], p[1000], p1[1000], p2[1000];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 0; i <= 1002; i++) {
    for (int j = 0; j <= 1002; j++) {
      dp[i][j] = -1e9;
    }
  }
  dp[0][0] = 0;
  string A;
  cin >> A;
  reverse(A.begin(), A.end());
  int n, x, l, r, ma, ans, y, z, an = 0, kkk;
  cin >> n;
  B.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> B[i];
    reverse(B[i].begin(), B[i].end());
    c[i] = i;
  }
  for (int i = 0; i <= 9; i++) cin >> cost[i];
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j < n; j++) {
      int x = 0;
      if (B[c[j]].size() > i) x = B[c[j]][i] - '0';
      bask[x].push_back(c[j]);
    }
    kkk = 0;
    for (int j = 9; j >= 0; j--) {
      for (auto u : bask[j]) {
        p[kkk++] = u;
      }
      bask[j].clear();
    }
    for (int j = 0; j < n; j++) {
      p1[c[j]] = j;
      p2[p[j]] = j;
    }
    if (A.size() > i) {
      l = A[i] - '0', r = A[i] - '0';
      if (A[i] == '?') {
        l = 0, r = 9;
      }
      if (i == A.size() - 1 && A[i] == '?') l++;
      for (int o = l; o <= r; o++) {
        int ma = 0, ans = 0;
        for (int j = 0; j < n; j++) {
          if (B[j].size() <= i)
            x = o;
          else
            x = B[j][i] - '0' + o;
          ans += cost[x % 10];
          if (x > 9) ma = max(ma, p2[j] + 1);
        }
        for (int j = 0; j <= n; j++) {
          if (j != 0) {
            int x = o;
            if (B[c[j - 1]].size() > i) {
              x = B[c[j - 1]][i] - '0' + o;
            }
            ans -= cost[x % 10];
            x++;
            ans += cost[x % 10];
            if (x > 9) ma = max(ma, p2[c[j - 1]] + 1);
          }
          if (dp[i][j] < 0) continue;
          dp[i + 1][ma] = max(dp[i + 1][ma], ans + dp[i][j]);
        }
      }
    } else {
      int ma = 0, ans = 0;
      for (int j = 0; j < n; j++) {
        if (B[j].size() <= i) continue;
        x = B[j][i] - '0';
        ans += cost[x % 10];
        if (x > 9) ma = max(ma, p2[j] + 1);
      }
      for (int j = 0; j <= n; j++) {
        if (j != 0) {
          int x = 0;
          if (B[c[j - 1]].size() > i) {
            x = B[c[j - 1]][i] - '0';
            ans -= cost[x % 10];
          }
          x++;
          ans += cost[x % 10];
          if (x > 9) ma = max(ma, p2[c[j - 1]] + 1);
        }
        if (dp[i][j] < 0) continue;
        dp[i + 1][ma] = max(dp[i + 1][ma], ans + dp[i][j]);
      }
    }
    for (int j = 0; j < n; j++) c[j] = p[j];
  }
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      an = max(an, dp[i][j]);
    }
  }
  cout << an;
  return 0;
}
