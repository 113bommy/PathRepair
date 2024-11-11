#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  char c = 'a';
  for (int i = 0; i < s.size(); i++) {
    if (s[i] <= c) {
      s[i] = c;
      c++;
      if (c - 1 == 'z') break;
    }
  }
  if (c - 1 == 'z')
    cout << s;
  else
    cout << -1;
  return 0;
}
