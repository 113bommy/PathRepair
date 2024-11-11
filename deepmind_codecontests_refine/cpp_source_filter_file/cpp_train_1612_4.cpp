#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T> readVector(int n) {
  vector<T> res(n);
  for (int i = 0; i < n; i++) cin >> res[i];
  return res;
}
template <typename T>
void printVector(vector<T> in) {
  int n = in.size();
  for (int i = 0; i < n; i++) {
    cout << in[i] << " \n"[i == n - 1];
  }
}
const long long int mod = 1e8;
long double dp[2010][2010];
int main() {
  int n, t;
  long double p;
  cin >> n >> p >> t;
  dp[0][1] = 1;
  for (int i = 0; i <= t; i++) {
    for (int j = 1; j <= n; j++) {
      if (dp[i][j] > 1e-9) {
        dp[i + 1][j] += (1 - p) * dp[i][j];
        dp[i + 1][j + 1] += p * dp[i][j];
      }
    }
  }
  long double ans = 0;
  for (int j = 1; j <= n + 1; j++) {
    ans += dp[t][j] * (j - 1);
  }
  for (int i = 1; i < t; i++) {
    ans += dp[i][n + 1] * (n);
  }
  cout << setprecision(10) << fixed << ans << endl;
}
