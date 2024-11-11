#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
using ii = pair<int, int>;
using ll = long long;
const int N = 5e4 + 5;
const int mod = 1e9 + 7;
int get(int x) {
  if ((x & 3) == 0) return x;
  if ((x & 3) == 1) return 1;
  if ((x & 3) == 2) return x + 1;
  return 0;
}
int n, m;
int a[N], ans[N], L[N], R[N];
vector<int> cry[N];
int dp[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    cin >> L[i] >> R[i];
    cry[R[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = max(dp[i], a[i]);
    for (int j = i - 1; j; --j) {
      dp[j] = max(dp[j], dp[j + 1]);
      dp[j] = max(dp[j], get(a[i]) ^ get(a[j]) ^ min(a[i], a[j]));
    }
    for (auto x : cry[i]) ans[x] = dp[L[x]];
  }
  for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
  return 0;
}
