#include <bits/stdc++.h>
using namespace std;
string s;
int ans = 0, now = 0;
int main() {
  cin >> s;
  s += "%";
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1]) {
      if (now % 2) {
        ans++;
        now = 0;
      }
    } else {
      now++;
    }
  }
  cout << ans;
}
