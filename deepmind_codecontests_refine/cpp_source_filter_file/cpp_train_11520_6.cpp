#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 69;
const int INF = 10;
vector<int> pr, suf;
int n, m;
pair<int, int> a[MAXN];
int beg[MAXN], en[MAXN];
int c[MAXN];
int dp[2][MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    beg[a[i].first]++;
    en[a[i].second]++;
  }
  int bal = 0;
  for (int i = 1; i <= m; ++i) {
    bal += beg[i];
    c[i] = bal;
    bal -= en[i];
  }
  pr.resize(MAXN);
  for (int i = 0; i < MAXN; ++i) pr[i] = INF;
  pr[1] = c[1];
  dp[0][1] = 1;
  for (int i = 2; i <= m; ++i) {
    int up = upper_bound(pr.begin(), pr.end(), c[i]) - pr.begin();
    pr[up] = c[i];
    dp[0][i] = up;
  }
  suf.resize(MAXN);
  for (int i = 0; i < MAXN; ++i) suf[i] = INF;
  suf[1] = c[m];
  dp[1][m] = 1;
  for (int i = m - 1; i >= 1; --i) {
    int up = upper_bound(suf.begin(), suf.end(), c[i]) - suf.begin();
    suf[up] = c[i];
    dp[1][i] = up;
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    ans = max(ans, dp[0][i]);
    ans = max(ans, dp[0][i] + dp[1][i] - 1);
  }
  cout << ans;
  return 0;
}
