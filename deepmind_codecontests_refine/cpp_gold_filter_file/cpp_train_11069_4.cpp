#include <bits/stdc++.h>
using namespace std;
int main() {
  string x, s, u;
  int ans = 2001;
  cin >> s >> u;
  for (int i = 0; i < u.length(); i++) x += '*';
  s = x + s + x;
  for (int i = 0; i < s.length(); i++) {
    int temp = u.length();
    for (int j = 0; j < u.length() && i + j < s.length(); j++) {
      if (s[i + j] == u[j]) temp--;
    }
    ans = min(temp, ans);
  }
  cout << ans;
  return 0;
}
