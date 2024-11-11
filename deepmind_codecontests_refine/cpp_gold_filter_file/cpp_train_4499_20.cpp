#include <bits/stdc++.h>
using namespace std;
long long int const MAXN = 1e2 + 8;
long long int const INF = 1e18 + 8;
long long int const delta = 1000000007;
vector<long long int> fib;
long long int dp1[MAXN];
long long int dp2[MAXN];
void pre() {
  fib.push_back(1);
  ;
  fib.push_back(2);
  ;
  for (long long int i = 2; i < 90; i++) {
    fib.push_back(fib[i - 1] + fib[i - 2]);
    ;
  }
}
long long int ans(long long int n) {
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));
  vector<long long int> temp;
  for (long long int i = fib.size() - 1; i >= 0; i--) {
    if (n >= fib[i]) {
      n -= fib[i];
      temp.push_back(i);
      ;
    }
  }
  reverse(temp.begin(), temp.end());
  dp1[0] = 1;
  dp2[0] = temp[0] / 2;
  for (long long int i = 1; i < temp.size(); i++) {
    dp1[i] = dp2[i - 1] + dp1[i - 1];
    dp2[i] = (dp1[i - 1] * ((temp[i] - temp[i - 1] - 1) / 2)) +
             (dp2[i - 1] * ((temp[i] - temp[i - 1]) / 2));
  }
  return dp1[temp.size() - 1] + dp2[temp.size() - 1];
}
int main() {
  std::ios::sync_with_stdio(0);
  ;
  cin.tie(0);
  cout.tie(0);
  pre();
  long long int n;
  cin >> n;
  long long int t;
  for (long long int i = 0; i < n; i++) {
    cin >> t;
    cout << ans(t) << endl;
  }
  return 0;
}
