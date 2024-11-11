#include <bits/stdc++.h>
const long long int INF = 9999999999999999, MOD = 1e9 + 7, MAXN = 10000;
const long double EPS = 0.000000000001;
using namespace std;
long long int dp[4000][4000], sum[4000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<int> good(1001);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    good[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if (a == 1) {
        good[i] = 0;
      }
      if (a == 2) {
        good[j] = 0;
      }
      if (a == 3) {
        good[i] = good[j] = 0;
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (good[i]) {
      ans.push_back(i);
    }
  }
  cout << (long long int)ans.size() << "\n";
  for (int i = 0; i < (long long int)ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  return 0;
}
