#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 0, in_hands = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (i == 0) in_hands++;
    if (s[i] == s[i - 1] && in_hands < 5)
      in_hands++;
    else {
      ans++;
      in_hands = 0;
    }
  }
  cout << ans;
  return 0;
}
