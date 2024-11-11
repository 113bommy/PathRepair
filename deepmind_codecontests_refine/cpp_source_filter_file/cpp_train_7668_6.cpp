#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long averagePower(vector<int>& power, vector<int>& processor) {
    int n = power.size();
    if (n == 0) {
      return 0;
    }
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    auto cmp = [&](int l, int r) { return power[l] > power[r]; };
    sort(indices.begin(), indices.end(), cmp);
    double eps = 1e-7;
    double l = 1e9;
    double r = 0.0;
    double maxV = 1e9;
    for (int i = 0; i < n; ++i) {
      l = min(l, (0.0 + power[i]) / processor[i]);
      r = max(r, (0.0 + power[i]) / processor[i]);
    }
    while (abs(r - l) > eps) {
      double m = (l + r) / 2;
      vector<double> vals(n);
      for (int i = 0; i < n; ++i) {
        vals[indices[i]] = 0.0 + power[indices[i]] - m * processor[indices[i]];
      }
      vector<vector<vector<double>>> dp(
          n, vector<vector<double>>(n, vector<double>(n + 1, maxV)));
      dp[0][0][1] = vals[indices[0]];
      for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          for (int k = 0; k + j <= i; ++k) {
            if (dp[i - 1][j][k] == maxV) {
              continue;
            }
            if (power[indices[i - 1]] == power[indices[i]]) {
              dp[i][j][k + 1] =
                  min(dp[i][j][k + 1], dp[i - 1][j][k] + vals[indices[i]]);
              if (j - (i + 1 - j - k) >= 0) {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
              }
            } else {
              dp[i][j + k][1] =
                  min(dp[i][j + k][1], dp[i - 1][j][k] + vals[indices[i]]);
              if (j + k - (i + 1 - j - k) >= 0) {
                dp[i][j + k][0] = min(dp[i][j + k][0], dp[i - 1][j][k]);
              }
            }
          }
        }
      }
      double minSum = maxV;
      for (auto& v : dp[n - 1]) {
        for (auto& r : v) {
          for (auto& s : v) {
            minSum = min(minSum, s);
          }
        }
      }
      if (minSum <= 0.0) {
        r = m;
      } else {
        l = m;
      }
    }
    long long res = l * 1000;
    res += (l * 1000 - res > 0 ? 1 : 0);
    return res;
  }

 private:
  struct Task {
    Task(int i, int p, int n) : id(i), power(p), num(n) {}
    int id;
    int power;
    int num;
    bool operator<(const Task& other) const {
      if (1LL * power * other.num > 1LL * other.power * num) {
        return true;
      } else if (1LL * power * other.num == 1LL * other.power * num) {
        if (power < other.power) {
          return true;
        } else if (power == other.power) {
          return id < other.id;
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  };
};
int main(int argc, char** argv) {
  int n;
  scanf("%d", &n);
  vector<int> power(n);
  vector<int> processor(n);
  for (int i = 0, p = 0; i < n; ++i) {
    scanf("%d", &p);
    power[i] = p;
  }
  for (int i = 0, p = 0; i < n; ++i) {
    scanf("%d", &p);
    processor[i] = p;
  }
  Solution sol;
  printf("%llu\n", sol.averagePower(power, processor));
  return 0;
}
