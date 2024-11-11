#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using ld = long double;
void base(int x, int b, int y) {
  int d = 1;
  int num = 0;
  while (x > 0) {
    num = (x % b) * d + num;
    x /= b;
    d *= 10;
  }
  if (num < 10 && y > 1) cout << ' ';
  cout << num << ' ';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  string t;
  cin >> t;
  string s;
  cin >> s;
  vector<int> dp(10, 0);
  for (int i = 0; i < t.size(); ++i) {
    if (t[i] == '5') t[i] = '2';
    if (t[i] == '9') t[i] = '6';
    dp[t[i] - '0']++;
  }
  vector<int> dem(10, 0);
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '5') s[i] = '2';
    if (s[i] == '9') s[i] = '6';
    dem[s[i] - '0']++;
  }
  int ans = t.size();
  for (int i = 0; i < t.size(); ++i) {
    ans = min(ans, dem[t[i] - '0'] / dp[t[i] - '0']);
  }
  cout << ans;
  return 0;
}
