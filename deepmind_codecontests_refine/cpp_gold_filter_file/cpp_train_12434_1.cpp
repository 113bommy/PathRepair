#include <bits/stdc++.h>
using namespace std;
int n, m, s, e;
vector<int> b[100001];
vector<int> a;
int dp[301][100001];
int sol(int i, int j) {
  if (i == 0) return -1;
  if (j < 0) return m;
  return dp[i][j];
}
int main() {
  cin >> n >> m >> s >> e;
  a = vector<int>(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b[x].push_back(i);
  }
  for (int i = 0; i < n; i++) dp[0][i] = -1;
  for (int i = 1; i < 301; i++) {
    for (int j = 0; j < n; j++) {
      int pv = sol(i - 1, j - 1);
      vector<int>::iterator it =
          upper_bound(b[a[j]].begin(), b[a[j]].end(), pv);
      if (it == b[a[j]].end())
        dp[i][j] = m;
      else {
        dp[i][j] = *it;
      }
      if (j) dp[i][j] = min(dp[i][j], sol(i, j - 1));
    }
  }
  int mx = 0;
  for (int i = 0; i < 301; i++) {
    for (int j = 0; j < n; j++) {
      if (dp[i][j] >= m) continue;
      if (j + 2 + dp[i][j] + i * e > s) continue;
      mx = i;
    }
  }
  cout << mx << endl;
}
