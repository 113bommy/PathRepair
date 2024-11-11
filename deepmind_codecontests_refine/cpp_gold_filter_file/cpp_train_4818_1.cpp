#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> solve(vector<int>& A) {
    int n = A.size();
    int N = n * (n - 1) / 2;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
      if (A[i] == 1) {
        pos.push_back(i + 1);
      }
    }
    int m = pos.size();
    if (m == 0 || m >= n - 1) {
      return vector<int>(N + 1, 0);
    }
    const int INF = 1 << 24;
    vector<vector<int>> dp(N + 1, vector<int>(n + 1, INF));
    auto ndp = dp;
    dp[0][0] = 0;
    for (int i = 0; i < m; ++i) {
      for (auto& V : ndp) {
        fill(V.begin(), V.end(), INF);
      }
      for (int j = 0; j <= N; ++j) {
        for (int k = 0; k <= n; ++k) {
          if (dp[j][k] >= INF) {
            continue;
          }
          for (int nk = k + 1; nk <= n; ++nk) {
            int nj = j + abs(nk - pos[i]);
            if (nj > N) {
              continue;
            }
            int d = nk - k - 1;
            int ans = dp[j][k] + (d * (d - 1) / 2);
            ndp[nj][nk] = min(ndp[nj][nk], ans);
          }
        }
      }
      swap(ndp, dp);
    }
    vector<int> res(N + 1, INF);
    for (int i = 0; i <= N; ++i) {
      for (int j = 0; j <= n; ++j) {
        int x = n + 1 - j - 1;
        x = x * (x - 1) / 2;
        res[i] = min(res[i], dp[i][j] + x);
      }
      if (i - 1 >= 0) {
        res[i] = min(res[i], res[i - 1]);
      }
    }
    int mx = (n - m) * (n - m - 1) / 2;
    for (auto& x : res) {
      x = mx - x;
    }
    return res;
  }
};
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution sol;
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  auto res = sol.solve(A);
  for (auto x : res) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}
