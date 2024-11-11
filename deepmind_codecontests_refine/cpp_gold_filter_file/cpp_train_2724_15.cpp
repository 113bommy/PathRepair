#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename... T>
void print1(T... t) {
  ((cout << t << " "), ...);
}
template <typename... T>
void print2(T... t) {
  vector<vector<long long>> ans = {t...};
  for (long long i = 0; i < (long long)ans.size(); i++) {
    if (i != 0)
      cout << "\t\t";
    else
      cout << "\t";
    for (long long j = 0; j < (long long)ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    if (i != (long long)ans.size() - 1) cout << endl;
  }
}
template <typename T>
void printV(T vec) {
  for (int i = 0; i < (long long)vec.size(); i++)
    cout << vec[i] << " " << flush;
  cout << endl;
}
const int INF = 1e9 + 5;
template <typename T>
void itR(T map) {
  for (auto itr = map.begin(); itr != map.end(); itr++) {
    cout << " [ "
            "itr->first, itr->second"
         << " : ";
    print1(itr->first, itr->second);
    cout << "]" << endl;
    ;
  }
  cout << endl;
}
long long solve() {
  long long n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  long long dp[n1 + 1][n2 + 1][2];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  dp[0][0][1] = 1;
  for (long long i = 0; i <= n1; i++) {
    for (long long j = 0; j <= n2; j++) {
      if (i == 0 and j == 0) {
        dp[i][j][0] = 1;
        dp[i][j][1] = 1;
      } else {
        for (long long temp = 1; temp <= min(i, k1); temp++) {
          dp[i][j][0] += dp[i - temp][j][1] % 100000000;
        }
        for (int temp = 1; temp <= min(j, k2); temp++) {
          dp[i][j][1] += dp[i][j - temp][0] % 100000000;
        }
      }
    }
  }
  return (dp[n1][n2][0] + dp[n1][n2][1]) % 100000000;
}
int main() {
  cout << setprecision(50);
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long ans = solve();
  cout << ans << endl;
  return 0;
}
