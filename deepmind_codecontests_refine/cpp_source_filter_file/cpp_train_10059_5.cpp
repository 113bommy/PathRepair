#include <bits/stdc++.h>
using namespace std;
int a[5010], b[5010];
int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 1; i <= s.length(); i++) {
    if (s[i - 1] == 'a')
      a[i] = a[i - 1] + 1;
    else
      a[i] = a[i - 1];
    if (s[i - 1] == 'b')
      b[i] = b[i - 1] + 1;
    else
      b[i] = b[i - 1];
  }
  for (int i = 0; i <= s.length(); i++)
    for (int j = 0; j <= s.length(); j++)
      ans = max(ans, a[i] + b[j] - b[i] + a[s.length()] - a[j]);
  cout << ans;
}
