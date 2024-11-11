#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int ans1, ans2;
  for (int i = 0; s.length() > i; i++) {
    if (s[i] == '4' and t[i] == '7') {
      ans1++;
    }
    if (s[i] == '7' and t[i] == '4') {
      ans2++;
    }
  }
  cout << max(ans1, ans2);
}
