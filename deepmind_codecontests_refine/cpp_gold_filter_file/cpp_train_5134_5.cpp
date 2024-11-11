#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
int main() {
  long long n;
  cin >> n;
  set<long long> S;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      S.insert(i);
      S.insert(n / i);
    }
  }
  vector<long long> d;
  for (auto x : S) {
    d.push_back(x);
  }
  int l = S.size();
  vector<int> dp(l, 0);
  vector<long long> f(l, 0);
  for (int i = 0; i < l; i++) {
    int cnt = 0;
    for (int j = 1; j < i; j++) {
      if (d[i] % d[j] == 0) {
        if (!dp[j]) {
          dp[i] = 1;
          f[i] = d[j];
        }
        cnt++;
      }
    }
    if (!cnt) dp[i] = 1;
  }
  cout << 2 - dp[l - 1] << endl;
  if (dp[l - 1]) cout << f[l - 1] << endl;
  return 0;
}
