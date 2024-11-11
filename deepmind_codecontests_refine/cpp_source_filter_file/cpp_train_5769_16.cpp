#include <bits/stdc++.h>
using namespace std;
const long long BIG_INF = 2e18;
const long long INF = 2e9;
const int MAXN = 1e3 + 7;
const double PI = 3.1415926535897932384626433832795028841971;
const int LOG = 25;
double f(vector<long long>& dp, vector<long long>& b, int i, int j) {
  return double(double(dp[i] - dp[j]) / double(b[j] - b[i]));
}
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<long long> dp(n, BIG_INF);
  dp[0] = 0;
  vector<int> q(2 * n);
  int start = 0, end = 0;
  q[end++] = 0;
  for (int i = 1; i < n; ++i) {
    while (start + 1 < end && f(dp, b, q[start], q[start + 1]) < double(a[i])) {
      start++;
    }
    dp[i] = dp[q[start]] + a[i] * b[q[start]];
    while (start + 1 < end &&
           f(dp, b, q[end - 2], q[end - 1]) > f(dp, b, q[end - 1], 1)) {
      end--;
    }
    q[end++] = i;
  }
  cout << dp[n - 1] << '\n';
  ;
  return 0;
}
