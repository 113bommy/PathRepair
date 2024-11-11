#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int x = s.length(), res = 0;
  sort(s.begin(), s.end());
  for (int i = 0; i < x - 1; i++) {
    if (s[i] == s[x - 1] && s[i - 1] != s[x - 1]) {
      res = i;
    }
  }
  for (int i = res; i < x; i++) {
    cout << s[i];
  }
  return 0;
}
