#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1e9 + 7;
vector<vector<int>> a;
vector<vector<vector<unsigned long long>>> dp;
vector<unsigned long long> summ;
int n, k;
void dfs(int v, int p) {
  for (int i = 0; i < a[v].size(); i++) {
    if (a[v][i] == p) continue;
    dfs(a[v][i], v);
  }
  dp[v][k][0] = 1;
  dp[v][0][k] = 1;
  unsigned long long x = 1;
  for (int q = 0; q < a[v].size(); ++q) {
    if (a[v][q] == p) continue;
    int v1 = a[v][q];
    x = (x * summ[v1]) % mod;
    vector<vector<unsigned long long>> tmp(21, vector<unsigned long long>(21));
    for (int i = 0; i <= k; i++)
      for (int j = 0; j <= k; ++j) {
        for (int l = 0; l <= k; ++l) {
          if (l == k - 1) continue;
          for (int r = 0; r <= k; ++r) {
            int new_i;
            if (l == k)
              new_i = i;
            else
              new_i = (i == k ? l + 1 : max(i, l + 1));
            if (l == k && i == k) new_i = k;
            int new_j = min(r + 1, j);
            if (r == k - 1 && i == 0 && l == k) new_i = k;
            if (new_j < k && new_j + new_i <= k) new_i = k;
            tmp[new_i][new_j] =
                (tmp[new_i][new_j] + dp[v][i][j] * dp[v1][l][r]) % mod;
          }
        }
      }
    swap(dp[v], tmp);
  }
  dp[v][k][0] = x;
  summ[v] = 0;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= k; j++) summ[v] = (summ[v] + dp[v][i][j]) % mod;
  }
}
int main() {
  cin >> n >> k;
  a.resize(n);
  summ.resize(n);
  dp.assign(102, vector<vector<unsigned long long>>(
                     21, vector<unsigned long long>(21)));
  for (int i = 0; i < n - 1; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    a[l].push_back(r);
    a[r].push_back(l);
  }
  dfs(0, -1);
  unsigned long long ans = 0;
  for (int i = 0; i <= k; ++i) {
    ans = (ans + dp[0][k][i]) % mod;
  }
  cout << ans;
}
