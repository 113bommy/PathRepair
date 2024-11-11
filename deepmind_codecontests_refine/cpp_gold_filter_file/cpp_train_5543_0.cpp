#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 10;
const long long LNF = 2e18;
int n, k, S[MAX], C[MAX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> S[i];
  for (int i = 1; i <= k; i++) cin >> C[i];
  sort(S + 1, S + n + 1, greater<int>());
  int ans = 0;
  for (int i = k, j = 0; i >= 1; i--) {
    while (j < n && S[j + 1] >= i) j++;
    ans = max(ans, (j + C[i] - 1) / C[i]);
  }
  vector<int> V[MAX];
  for (int i = 1; i <= n; i++) V[i % ans].push_back(S[i]);
  cout << ans << '\n';
  for (int i = 0; i < ans; i++) {
    cout << V[i].size();
    for (int s : V[i]) cout << ' ' << s;
    cout << '\n';
  }
  return 0;
}
