#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 12;
int n, m, u, v, dp[N][N][M + 1], dp2[N][(1 << M)], dp3[N][(1 << M)];
vector<int> arr, g[N], t[M + 1];
int fres = 1;
int solve() {
  int idx = 0, all = 0, sz, mask, res = 0;
  for (int i = 0; i < (int)arr.size(); i++) {
    for (int node = 1; node <= n; node++) {
      if ((int)t[arr[i]].size() == 0) {
        if (i == (int)arr.size() - 1) {
          res++;
          if (res >= 1000000007) res -= 1000000007;
        }
        for (int j = 0; j < (int)g[node].size(); j++) {
          dp[g[node][j]][node][arr[i]] = 1;
        }
        continue;
      }
      sz = (int)t[arr[i]].size();
      all = (1 << sz);
      for (mask = 0; mask < all; mask++) dp2[(int)g[node].size()][mask] = 0;
      dp2[(int)g[node].size()][0] = 1;
      for (mask = 0; mask < all; mask++) {
        for (int j = (int)g[node].size() - 1; j >= 0; j--) {
          dp2[j][mask] = dp2[j + 1][mask];
          for (int k = 0; k < sz; k++) {
            if (((mask >> k) & 1) == 0) continue;
            dp2[j][mask] += (long long)dp2[j + 1][(mask ^ (1 << k))] *
                            dp[node][g[node][j]][t[arr[i]][k]] % 1000000007;
            if (dp2[j][mask] >= 1000000007) dp2[j][mask] -= 1000000007;
          }
        }
        for (int j = 0; j < (int)g[node].size(); j++) {
          if (j == 0)
            dp3[j][mask] = (mask == 0 ? 1 : 0);
          else
            dp3[j][mask] = dp3[j - 1][mask];
          for (int k = 0; k < sz; k++) {
            if (((mask >> k) & 1) == 0) continue;
            if (j == 0) {
              if ((mask ^ (1 << k)) != 0) continue;
              dp3[j][mask] = dp[node][g[node][j]][t[arr[i]][k]];
              continue;
            }
            dp3[j][mask] += (long long)dp3[j - 1][(mask ^ (1 << k))] *
                            dp[node][g[node][j]][t[arr[i]][k]] % 1000000007;
            if (dp3[j][mask] >= 1000000007) dp3[j][mask] -= 1000000007;
          }
        }
      }
      if (i == (int)arr.size() - 1) {
        res += dp2[0][all - 1];
        if (res >= 1000000007) res -= 1000000007;
        continue;
      }
      for (int j = 0; j < (int)g[node].size(); j++) {
        if (j == 0) {
          dp[g[node][j]][node][arr[i]] = dp2[1][all - 1];
          continue;
        }
        if (j == (int)g[node].size() - 1) {
          dp[g[node][j]][node][arr[i]] = dp3[j - 1][all - 1];
          continue;
        }
        for (int k = 0; k < all; k++) {
          dp[g[node][j]][node][arr[i]] += (long long)dp3[j - 1][k] *
                                          dp2[j + 1][(k ^ (all - 1))] %
                                          1000000007;
          if (dp[g[node][j]][node][arr[i]] >= 1000000007)
            dp[g[node][j]][node][arr[i]] -= 1000000007;
        }
      }
    }
  }
  return res;
}
inline int fastpower(int num, int po) {
  fres = 1;
  while (po > 0) {
    if (po & 1) fres = (long long)fres * num % 1000000007;
    po >>= 1;
    num = (long long)num * num % 1000000007;
  }
  return fres;
}
void fix(int node, int prnt) {
  arr.push_back(node);
  for (int i = 0; i < (int)t[node].size(); i++) {
    if (t[node][i] == prnt) {
      t[node].erase(t[node].begin() + i);
      i--;
      continue;
    }
    fix(t[node][i], node);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scanf("%d", &m);
  for (int i = 0; i < m - 1; i++) {
    scanf("%d%d", &u, &v);
    t[u].push_back(v);
    t[v].push_back(u);
  }
  fix(1, -1);
  reverse(arr.begin(), arr.end());
  int ans = solve();
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < (int)t[i].size(); j++) {
      g[i].push_back(t[i][j]);
      g[t[i][j]].push_back(i);
    }
  }
  n = m;
  ans = (long long)ans * fastpower(solve(), 1000000007 - 2) % 1000000007;
  cout << ans << endl;
  return 0;
}
