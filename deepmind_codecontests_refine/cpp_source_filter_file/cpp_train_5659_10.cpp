#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int space = 0;
  for (int i = 0; i < s.size() - 2; i++) {
    if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
      i += 2;
      if (space) {
        space = 0;
        cout << ' ';
      }
    } else {
      space = 1;
      cout << s[i];
    }
  }
  return 0;
}
