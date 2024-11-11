#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000007;
const double eps = 1e-6;
const long long Inf = 1LL << 62;
const long long mod = 1000000007;
const long long pnum = 5761460;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  ;
  err(++it, args...);
}
void solve_with_case(int cas) {}
long long maxCalories(vector<vector<long long>> arr, int n, int m) {
  vector<vector<long long>> dp1(1005, vector<long long>(1005, 0));
  vector<vector<long long>> dp2(1005, vector<long long>(1005, 0));
  vector<vector<long long>> dp3(1005, vector<long long>(1005, 0));
  vector<vector<long long>> dp4(1005, vector<long long>(1005, 0));
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++) {
      dp1[i][j] = arr[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    }
  }
  for (int i = (n); i >= (1); i--) {
    for (int j = (m); j >= (1); j--) {
      dp2[i][j] = arr[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
    }
  }
  for (int i = (n); i >= (1); i--) {
    for (int j = (1); j <= (m); j++) {
      dp3[i][j] = arr[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
    }
  }
  for (int i = (1); i <= (n); i++) {
    for (int j = (m); j >= (1); j--) {
      dp4[i][j] = arr[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);
    }
  }
  long long ans = 0;
  for (int i = (2); i <= (n); i++) {
    for (int j = (2); j <= (m); j++) {
      long long ans1 =
          dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1];
      long long ans2 =
          dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j];
      ans = max({ans, ans1, ans2});
    }
  }
  return ans;
}
void solve_without_case() {
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> arr(1005, vector<long long>(1005, 0));
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++) {
      cin >> arr[i][j];
    }
  }
  cout << maxCalories(arr, n, m) << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  solve_without_case();
  return 0;
}
