#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
vector<int> arr;
int solve(int i, vector<int> &total, vector<int> &dp) {
  if (i == arr.size()) return 0;
  if (dp[i] != -1) return dp[i];
  dp[i] = max(arr[i] + total[i + 1] - solve(i + 1, total, dp),
              solve(i + 1, total, dp));
  return dp[i];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  arr.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> total(n + 1, 0);
  vector<int> dp(n, -1);
  total[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) total[i] = arr[i] + total[i + 1];
  int bob = solve(0, total, dp);
  int alice = total[0] - bob;
  cout << alice << " " << bob << "\n";
}
