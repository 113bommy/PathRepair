#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int solve(vector<pair<int, int>>& S, int t) {
    const int M = 1000000007;
    int n = S.size();
    int G = 3;
    vector<int> cnts(G, 0);
    for (int i = 0; i < n; ++i) {
      ++cnts[S[i].second];
    }
    int mc = 0;
    for (int i = 0; i < G; ++i) {
      if (cnts[mc] > cnts[i]) {
        mc = i;
      }
    }
    assert(cnts[mc] * 3 <= n);
    vector<int> indices(G, -1);
    for (int i = 0, j = 0; i < G; ++i) {
      if (i != mc) {
        indices[i] = j++;
      }
    }
    vector<pair<int, int>> L;
    vector<pair<int, int>> R;
    for (int i = 0; i < n; ++i) {
      if (S[i].second == mc) {
        L.push_back(S[i]);
      } else {
        R.push_back(S[i]);
      }
    }
    int m = L.size();
    assert(m == cnts[mc]);
    vector<vector<int>> dpL(t + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dpL2(t + 1);
    for (int i = (1 << m) - 1; i >= 0; --i) {
      int sum = 0, cnt = 0;
      for (int j = 0; j < m; ++j) {
        if (i & (1 << j)) {
          sum += L[j].first;
          ++cnt;
        }
      }
      if (sum <= t) {
        ++dpL[sum][cnt];
      }
    }
    for (int i = 0; i <= t; ++i) {
      for (int j = 0; j <= m; ++j) {
        if (dpL[i][j] > 0) {
          dpL2[i].push_back(j);
        }
      }
    }
    vector<vector<vector<int>>> dpR(
        n + 1, vector<vector<int>>(n + 1, vector<int>(t + 1, 0)));
    dpR[0][0][0] = 1;
    m = R.size();
    vector<int> limits(G, 0);
    int sum = 0;
    for (int _ = 0; _ < m; ++_) {
      int c = indices[R[_].second];
      int d = R[_].first;
      for (int i = limits[0]; i >= 0; --i) {
        for (int j = limits[1]; j >= 0; --j) {
          for (int k = min(sum, t - d); k >= 0; --k) {
            int nk = k + d;
            int ni = i, nj = j;
            if (c == 0) {
              ni += 1;
            } else {
              nj += 1;
            }
            dpR[ni][nj][nk] += dpR[i][j][k];
            if (dpR[ni][nj][nk] >= M) {
              dpR[ni][nj][nk] -= M;
            }
          }
        }
      }
      ++limits[c];
      sum += d;
    }
    vector<vector<vector<vector<int>>>> dp(
        G, vector<vector<vector<int>>>(
               n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0))));
    dp[0][0][0][0] = 1;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n; ++k) {
          if (i - 1 >= 0) {
            long long cnt = 0;
            cnt += dp[1][i - 1][j][k];
            if (cnt >= M) {
              cnt -= M;
            }
            if (i + j + k == 1) {
              cnt += dp[0][i - 1][j][k];
              if (cnt >= M) {
                cnt -= M;
              }
            }
            cnt += dp[2][i - 1][j][k];
            if (cnt >= M) {
              cnt -= M;
            }
            cnt = (cnt * i) % M;
            dp[0][i][j][k] += cnt;
            if (dp[0][i][j][k] >= M) {
              dp[0][i][j][k] -= M;
            }
          }
          if (j - 1 >= 0) {
            long long cnt = 0;
            cnt += dp[0][i][j - 1][k];
            if (cnt >= M) {
              cnt -= M;
            }
            cnt += dp[2][i][j - 1][k];
            if (cnt >= M) {
              cnt -= M;
            }
            cnt = (cnt * j) % M;
            dp[1][i][j][k] += cnt;
            if (dp[1][i][j][k] >= M) {
              dp[1][i][j][k] -= M;
            }
          }
          if (k - 1 >= 0) {
            long long cnt = 0;
            cnt += dp[0][i][j][k - 1];
            if (cnt >= M) {
              cnt -= M;
            }
            cnt += dp[1][i][j][k - 1];
            if (cnt >= M) {
              cnt -= M;
            }
            cnt = (cnt * k) % M;
            dp[2][i][j][k] += cnt;
            if (dp[2][i][j][k] >= M) {
              dp[2][i][j][k] -= M;
            }
          }
        }
      }
    }
    auto count = [&](int x, int y, int z) {
      long long res = 0;
      for (int i = 0; i < G; ++i) {
        res += dp[i][x][y][z];
        if (res >= M) {
          res -= M;
        }
      }
      return res;
    };
    long long res = 0;
    for (int i = 0; i <= t; ++i) {
      if (dpL2[t - i].empty()) {
        continue;
      }
      for (int j = 0; j <= limits[0]; ++j) {
        for (int k = 0; k <= limits[1]; ++k) {
          if (dpR[j][k][i] == 0) {
            continue;
          }
          for (auto l : dpL2[t - i]) {
            long long cnt = count(l, j, k);
            if (cnt != 0) {
              cnt = (cnt * (dpR[j][k][i] * 1LL * dpL[t - i][l]) % M) % M;
              res += cnt;
              if (res >= M) {
                res -= M;
              }
            }
          }
        }
      }
    }
    return res;
  }
};
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution sol;
  int n, t;
  cin >> n >> t;
  vector<pair<int, int>> S(n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i].first >> S[i].second;
    --S[i].second;
  }
  cout << sol.solve(S, t) << "\n";
  return 0;
}
