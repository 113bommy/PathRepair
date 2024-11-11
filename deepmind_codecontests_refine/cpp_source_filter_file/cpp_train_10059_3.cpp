#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 5;
int sum[maxn][2];
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    sum[i + 1][0] = sum[i][0];
    sum[i + 1][1] = sum[i][1];
    sum[i + 1][s[i] - 'a']++;
  }
  int ans = 0;
  for (int i = 0; i <= s.length(); i++) {
    for (int j = 0; j <= s.length(); j++) {
      int cur =
          sum[i][0] + sum[j][1] - sum[i][1] + sum[s.length()][0] - sum[j][0];
      ans = max(cur, ans);
    }
  }
  cout << ans << endl;
}
