#include <bits/stdc++.h>
using namespace std;
inline bool div(char c1, char c2) {
  return (10 * (c1 - '0') + (c2 - '0')) % 4 == 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.length();
  int ans = 0;
  for (int i = 0; s[i]; i++)
    if (s[i] == '4' || s[i] == '0' || s[i] == '8') ans++;
  for (int i = 0; i < n; i += 2) {
    if (i == n - 1) continue;
    if (div(s[i], s[i + 1])) ans += i + 1;
  }
  for (int i = 1; i < n; i += 2) {
    if (i == n - 1) continue;
    if (div(s[i], s[i + 1])) ans += i + 1;
  }
  cout << ans;
  return 0;
}
