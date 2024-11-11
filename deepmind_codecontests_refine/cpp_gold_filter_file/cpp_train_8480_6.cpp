#include <bits/stdc++.h>
using namespace std;
void printMat(vector<vector<long long> > mat) {
  cout << "--------------------" << '\n';
  for (auto vec : mat) {
    for (auto v : vec) {
      cout << v << " ";
    }
    cout << '\n';
  }
  cout << "--------------------" << '\n';
}
void printVec(vector<long long> vec) {
  cout << "--------------------" << '\n';
  for (auto v : vec) {
    cout << v << " ";
  }
  cout << '\n';
  cout << "--------------------" << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, d;
  cin >> n >> d;
  map<long long, long long> m;
  long long v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    m[v]++;
  }
  long long l = d, h = d;
  long long sum = 0;
  while (sum + l <= 30000 && l > 1) {
    sum += l;
    l--;
  }
  sum = 0;
  while (sum + h <= 30000) {
    sum += h;
    h++;
  }
  vector<vector<long long> > dp(30001, vector<long long>((h - l) + 5, -1));
  dp[d][d - l + 1] = m[d];
  long long maxi = m[d];
  for (int i = d + 1; i <= 30000; i++) {
    for (int j = l; j <= h; j++) {
      if (j > i) break;
      long long k = j - l + 1;
      long long temp = dp[i - j][k];
      temp = dp[i][k + 1];
      if (k + 1 <= h) dp[i][k] = max(dp[i][k], dp[i - j][k + 1]);
      dp[i][k] = max(dp[i][k], dp[i - j][k]);
      if (k != 1) dp[i][k] = max(dp[i][k], dp[i - j][k - 1]);
      if (dp[i][k] == -1) continue;
      dp[i][k] += m[i];
      maxi = max(dp[i][k], maxi);
    }
  }
  cout << maxi << '\n';
  return 0;
}
