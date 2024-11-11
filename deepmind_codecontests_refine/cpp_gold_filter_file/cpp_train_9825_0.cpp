#include <bits/stdc++.h>
using namespace std;
int n, q;
const int maxn = 100100;
int col[maxn];
long long int val[maxn], dp[maxn];
long long int inf = (long long int)(1e18);
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> col[i];
  }
  while (q > 0) {
    long long int a, b;
    cin >> a >> b;
    pair<long long int, int> mx1 = make_pair(0, -1), mx2 = make_pair(0, -1);
    for (int i = 1; i <= n; i++) dp[i] = -inf;
    for (int i = 0; i < n; i++) {
      if (col[i] != mx1.second) {
        dp[col[i]] = max(dp[col[i]], dp[col[i]] + val[i] * a);
        dp[col[i]] = max(dp[col[i]], mx1.first + val[i] * b);
      } else {
        dp[col[i]] = max(dp[col[i]], dp[col[i]] + val[i] * a);
        dp[col[i]] = max(dp[col[i]], mx2.first + val[i] * b);
      }
      if (dp[col[i]] >= mx1.first) {
        if (col[i] != mx1.second) {
          mx2 = mx1;
        }
        mx1 = make_pair(dp[col[i]], col[i]);
      } else if (dp[col[i]] > mx2.first) {
        mx2 = make_pair(dp[col[i]], col[i]);
      }
    }
    cout << mx1.first << endl;
    q--;
  }
  return 0;
}
