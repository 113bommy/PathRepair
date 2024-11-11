#include <bits/stdc++.h>
using namespace std;
int dp[11][11];
int lcs(const string& power, const string& orig) {
  int count = 0;
  for (int i = 0; i < orig.size(); ++i)
    if (count < power.size() && power[count] == orig[i]) ++count;
  return power.size() + orig.size() - count * 2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int res = INT_MAX;
    for (long long i = 1; i < 64; ++i) {
      long long power = (long long)1 << i;
      res = min(res, lcs(to_string(power), s));
    }
    cout << res << endl;
  }
}
