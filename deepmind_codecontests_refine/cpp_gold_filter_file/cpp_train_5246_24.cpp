#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int f = s.find_first_of("RL");
  int l = s.find_last_of("RL");
  if (s[f] == 'R' && s[l] == 'R')
    cout << f + 1 << " " << l + 1 + 1;
  else if (s[f] == 'L' && s[l] == 'L')
    cout << l + 1 << " " << f - 1 + 1;
  else if (s[f] == 'R' && s[l] == 'L') {
    for (int i = f; i < n; i++) {
      l = i;
      if (s[i] == 'L') {
        break;
      }
    }
    cout << f + 1 << " " << l - 1 + 1;
  }
  return 0;
}
