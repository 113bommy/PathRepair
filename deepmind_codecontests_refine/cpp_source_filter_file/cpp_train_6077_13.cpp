#include <bits/stdc++.h>
using namespace std;
long long int last_occurence[100005], pr[100005], arr[100005], dp[100005];
vector<long long int> divi[100005];
void precompute() {
  long long int i, j;
  for (i = 2; i * i <= 100000; i++) {
    for (j = 2 * i; j <= 100000; j += i) {
      divi[j].push_back(i);
      pr[j] = 1;
    }
  }
  for (i = 2; i <= 100000; i++) {
    if (pr[i] == 0) divi[i].push_back(i);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n, i, j, ans = 1, k;
  cin >> n;
  precompute();
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (i = 1; i <= n; i++) {
    j = arr[i];
    for (k = 0; k < divi[j].size(); k++) {
      dp[i] = max(dp[i], 1 + dp[last_occurence[divi[j][k]]]);
      last_occurence[divi[j][k]] = i;
      ans = max(ans, dp[i]);
    }
  }
  cout << ans;
  return 0;
}
