#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, i, j, k, x, y, z, ans = 0;
  string s;
  cin >> s;
  cin >> k;
  string s1[k + 1];
  for (i = 1; i <= k; i++) {
    cin >> s1[i];
    x = 0;
    y = 0;
    for (j = 0; j < s.size(); j++) {
      if (s[j] == s1[i][0])
        x += 1;
      else if (s[j] == s1[i][1])
        y += 1;
      else {
        ans += min(x, y);
        x = 0;
        y = 0;
      }
    }
    ans += min(x, y);
  }
  cout << ans;
  return 0;
}
