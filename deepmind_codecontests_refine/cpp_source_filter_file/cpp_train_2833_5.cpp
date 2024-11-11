#include <bits/stdc++.h>
using namespace std;
string gen(string s, int x) {
  string ans = s;
  long long rem = max(0, x - int(s.size()));
  long long now = 0;
  for (int i = 0, ThxDem = x; i < ThxDem; ++i) {
    if (!rem) break;
    now = ans[i] - '0' - 1;
    long long len = int(ans.size()) - i - 1;
    for (int j = 0, ThxDem = min(rem, now * len); j < ThxDem; ++j) {
      ans.push_back(ans[i + 1 + j]);
    }
    rem -= min(rem, now * len);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long now = 0, x, MOD = 1e9 + 7;
    cin >> x;
    string s;
    cin >> s;
    long long ans = int(s.size());
    for (int i = 0, ThxDem = x; i < ThxDem; ++i) {
      now = s[i] - '0';
      long long len = (ans - i - 1 + MOD) % MOD;
      long long add = (now - 1 + MOD) % MOD * len % MOD;
      if (int(s.size()) < x) {
        string now = string(s.begin() + i + 1, s.end());
        for (int i = 0, ThxDem = add; i < ThxDem; ++i) s += now;
      }
      ans = (ans + add) % MOD;
    }
    cout << ans << "\n";
  }
}
