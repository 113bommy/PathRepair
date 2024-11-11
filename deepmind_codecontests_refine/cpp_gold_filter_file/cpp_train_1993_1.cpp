#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 1;
int a[200005], L[200005], dp[5005][5005] = {0};
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i], v.push_back(a[i]);
  sort(a + 1, a + 1 + n);
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; i++) {
    for (int j = i; j >= 1; j--)
      if (a[i] - a[j] <= 5) L[i]++;
    for (int j = 1; j <= k; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i - L[i]][j - 1] + L[i]);
    }
  }
  cout << dp[n][k] << endl;
}
