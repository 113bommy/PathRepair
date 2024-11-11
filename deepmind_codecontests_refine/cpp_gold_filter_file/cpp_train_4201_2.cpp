#include <bits/stdc++.h>
using namespace std;
int dp1[100005], dp2[100005];
int main() {
  string s;
  cin >> s;
  int l = 0, u = 0, n = s.length();
  if (islower(s[0]))
    l = dp1[0] = 1;
  else
    u = dp2[0] = isupper(s[0]);
  for (int i = 1; i < n; i++) {
    if (islower(s[i]))
      l++;
    else
      u++;
    if (islower(s[i]))
      dp1[i] += islower(s[i]) - 1 + dp1[i - 1];
    else
      dp1[i] += dp1[i - 1];
    dp2[i] += isupper(s[i]) + dp2[i - 1];
  }
  int res = min(n - l, n - u);
  for (int i = 0; i < n; i++) {
    res = min(res, dp1[i] + dp2[n - 1] - dp2[i]);
  }
  cout << res;
  return 0;
}
