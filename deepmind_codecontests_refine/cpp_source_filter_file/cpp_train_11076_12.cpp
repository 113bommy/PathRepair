#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int t = s.size(), c = 0, cnt = 0;
  for (int i = 0; i < t - 4; ++i) {
    if (s[i] == 'h' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'v' &&
        s[i + 4] == 'y')
      c++;
    if (s[i] == 'm' && s[i + 1] == 'e' && s[i + 2] == 't' && s[i + 3] == 'a' &&
        s[i + 4] == 'l')
      cnt += c;
  }
  cout << cnt << '\n';
}
