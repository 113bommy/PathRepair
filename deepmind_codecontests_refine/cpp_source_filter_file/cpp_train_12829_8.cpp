#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, A = 205;
int n;
int a[N];
int cnt[A][N];
vector<int> pos[A];
void reset() {
  for (int i = 0; i < A; i++) pos[i].clear();
  for (int i = 1; i < A; i++) {
    for (int j = 0; j <= n; j++) cnt[i][j] = 0;
  }
}
void read() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
}
void solve() {
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i < A; i++) cnt[i][j] = cnt[i][j - 1];
    pos[a[j]].push_back(j);
    cnt[a[j]][j]++;
  }
  int ans = 0;
  for (int i = 1; i < A; i++) {
    ans = max(ans, (int)pos[i].size());
    for (int k = 1; k <= pos[i].size() / 2; k++) {
      int l = pos[i][k - 1] + 1;
      int r = pos[i][pos[i].size() - k] - 1;
      for (int j = 1; j < A && l < r; j++) {
        if (i == j) continue;
        int m = cnt[j][r] - cnt[j][l - 1];
        ans = max(ans, 2 * k + m);
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    read();
    reset();
    solve();
  }
  return 0;
}
