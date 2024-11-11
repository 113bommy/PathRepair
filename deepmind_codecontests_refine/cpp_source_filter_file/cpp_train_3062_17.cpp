#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 1e9 + 7;
const int sq = 800;
int ans;
int n, k;
int c[maxn];
int r[maxn];
int dp[2][sq];
unordered_set<int> bois[maxn];
void in();
void solve();
int q2(int);
void out();
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  in();
  solve();
  out();
}
void in() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> c[i] >> r[i];
    if (n - c[i] >= sq)
      ans += 3;
    else
      bois[r[i]].insert(n - c[i]);
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    int all3 = 0;
    int tofmof = inf;
    for (int j = min(sq - 1, i); j >= 0; j--) {
      tofmof = min(tofmof, all3 + q2(j) + dp[1 - i % 2][j]);
      if (j == min(sq - 1, i))
        dp[i % 2][j] = dp[1 - i % 2][j - 1];
      else {
        if (bois[n - i + 1].find(j) != bois[n - i + 1].end()) all3 += 3;
        dp[i % 2][j] = min(dp[1 - i % 2][max(0, j - 1)] + all3, tofmof);
      }
    }
  }
  ans += dp[n % 2][0];
}
int q2(int h) { return 2 + (h + 1) * (h + 2) / 2; }
void out() { cout << ans; }
