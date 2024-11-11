#include <bits/stdc++.h>
using namespace std;
string vow = "aeiou";
const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
const long double pie = 3.14159265358979;
const long long mod = 1e9 + 7;
void solve(int test_case) {
  int n;
  cin >> n;
  vector<long long> p(4);
  for (int i = 1; i < 4; i++) cin >> p[i];
  vector<long long> v(n + 1);
  for (int i = 1; i < n + 1; i++) cin >> v[i];
  vector<vector<long long> > dp(4, vector<long long>(n + 1));
  for (int i = 0; i < 3; i++) dp[i][0] = LLONG_MIN;
  for (int j = 1; j < n + 1; j++) {
    for (int i = 1; i < 4; i++)
      dp[i][j] = max(dp[i][j - 1], dp[i - 1][j] + p[i] * v[j]);
  }
  cout << dp[3][n];
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 0; i < t; i++) solve(i);
  return 0;
}
