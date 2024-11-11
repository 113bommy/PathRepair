#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int tm(vector<int> a) {
  sort(begin(a), end(a));
  return a[0] + a[2];
}
int n;
vector<int> a;
bool odd = 0;
vector<vector<int>> dp;
vector<vector<pair<int, int>>> dpFrom, dpWho;
void print(int i, int j) {
  if (i == n - 2 && j == n - 1) return;
  if (dpWho[i][j] == pair<int, int>{0, 0}) {
    cout << "*#&$ NOOOOOOOO $^@&*\n";
    return;
  }
  pair<int, int> x = dpWho[i][j];
  if (x.second == n - 3 && odd) {
    cout << x.first + 1 << "\n";
  } else {
    cout << x.first + 1 << " " << x.second + 1 << "\n";
  }
  x = dpFrom[i][j];
  print(x.first, x.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  n += 2;
  a.push_back(0);
  a.push_back(0);
  if (n % 2 == 1) {
    ++n;
    a.push_back(0);
    odd = 1;
  }
  if (n == 2) {
    cout << max(a[0], a[1]) << "\n";
    if (odd) {
      cout << "1\n";
    } else {
      cout << "1 2\n";
    }
    return 0;
  }
  dp.assign(n + 5, vector<int>(n + 5, INF));
  dpFrom.assign(n, vector<pair<int, int>>(n));
  dpWho.assign(n, vector<pair<int, int>>(n));
  dp[n - 2][n - 1] = max(a[n - 2], a[n - 1]);
  dpWho[n - 2][n - 1] = {n - 2, n - 1};
  dpFrom[n - 2][n - 1] = {0, 0};
  for (int j = n - 2; j >= 0; --j) {
    for (int i = j - 1; i >= 0; --i) {
      if (dp[i][j] > dp[j + 1][j + 2] + max(a[i], a[j])) {
        dp[i][j] = dp[j + 1][j + 2] + max(a[i], a[j]);
        dpFrom[i][j] = {j + 1, j + 2};
        dpWho[i][j] = {i, j};
      }
      if (dp[i][j] > dp[j][j + 2] + max(a[i], a[j + 1])) {
        dp[i][j] = dp[j][j + 2] + max(a[i], a[j + 1]);
        dpFrom[i][j] = {j, j + 2};
        dpWho[i][j] = {i, j + 1};
      }
      if (dp[i][j] > dp[i][j + 2] + max(a[j], a[j + 1])) {
        dp[i][j] = dp[i][j + 2] + max(a[j], a[j + 1]);
        dpFrom[i][j] = {i, j + 2};
        dpWho[i][j] = {j, j + 1};
      }
    }
  }
  cout << dp[0][1] << "\n";
  print(0, 1);
}
