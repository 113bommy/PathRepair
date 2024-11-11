#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int MOD;
int NN;
long long dp[N][N], cnp[N][N], ma[N][N], c[N];
void NchooseK() {
  for (int i = 0; i < N; ++i) {
    cnp[i][0] = cnp[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      cnp[i][j] = cnp[i - 1][j - 1] + cnp[i - 1][j];
    }
  }
}
long long dfs(int i, int j) {
  long long& res = dp[i][j];
  if (res == -1) {
    if (i == NN - 1) {
      res = 1;
    } else {
      res = 0;
      assert(j % 2 == 0);
      int twos = max(0, (max(0, i - 1) - j / 2));
      int free = NN - twos - j;
      if (j >= 2 && (free == 0 || NN - 2 != i)) {
        res = (cnp[j][2] * dfs(i + 1, j - 2)) % MOD;
      }
      if (j >= 1 && free >= 1) {
        res = (res + cnp[j][1] * cnp[free][1] * dfs(i + 1, j)) % MOD;
      }
      if (free >= 2) {
        res = (res + cnp[free][2] * dfs(i + 1, j + 2)) % MOD;
      }
    }
  }
  return res;
}
int main() {
  int n, m;
  cin >> n >> m >> MOD;
  NN = n;
  memset(c, 0, sizeof(c));
  memset(dp, -1, sizeof(dp));
  NchooseK();
  vector<string> vs;
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    vs.push_back(s);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      c[j] += (int)(vs[i][j] - '0');
    }
  }
  int ones = 0;
  for (int i = 0; i < n; ++i) {
    if (c[i] == 1) ++ones;
  }
  if (n == m) {
    cout << 1 << endl;
  } else {
    cout << dfs(m, ones) << endl;
  }
  return 0;
}
