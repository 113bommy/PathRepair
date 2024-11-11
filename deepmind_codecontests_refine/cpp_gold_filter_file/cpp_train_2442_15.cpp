#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = INT_MAX, MIN = INT_MIN;
inline int input() {
  int x;
  cin >> x;
  return x;
}
int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
const int N = 1e4 + 20;
int a[6][N], dp[N], nums[6][N];
bool checked[N];
vector<int> e[N];
int path(int v) {
  if (checked[v]) return dp[v];
  dp[v] = 1;
  for (int i = 0; i < e[v].size(); i++) dp[v] = max(dp[v], path(e[v][i]) + 1);
  checked[v] = true;
  return dp[v];
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, l;
  cin >> n >> l;
  for (int i = 1; i < l + 1; i++)
    for (int j = 1; j < n + 1; j++) {
      cin >> nums[i][j];
      a[i][nums[i][j]] = j;
    }
  for (int i = 1; i < n + 1; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      bool itoj, jtoi;
      itoj = jtoi = true;
      for (int k = 1; k < l + 1; k++) {
        if (a[k][i] > a[k][j]) itoj = false;
        if (a[k][i] < a[k][j]) jtoi = false;
      }
      if (jtoi) e[i].push_back(j);
      if (itoj) e[j].push_back(i);
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < e[nums[1][i]].size(); j++)
      dp[nums[1][i]] = max(dp[e[nums[1][i]][j]] + 1, dp[nums[1][i]]);
  }
  int mx = MIN;
  for (int i = 1; i < n + 1; i++) mx = max(mx, dp[i] + 1);
  cout << mx << "\n";
  return 0;
}
