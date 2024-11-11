#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, a;
  cin >> s;
  long long n = s.size();
  long long sol = 1;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'a' || s[i] == 'b') {
      a.push_back(s[i]);
    }
  }
  vector<long long> dp;
  long long k = 0;
  for (long long i = 0; i < a.size(); i++) {
    if (a[i] == 'a') {
      k++;
    } else {
      if (k != 0) dp.push_back(k + 1);
      k = 0;
    }
  }
  if (k != 0) dp.push_back(k + 1);
  for (long long i = 0; i < dp.size(); i++) {
    sol = (sol * dp[i]) % 1000000007;
  }
  cout << sol - 1;
  return 0;
}
