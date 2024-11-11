#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.size(), l = 0, r = 0, ans = 0;
  for (int i = 0; i < len; ++i) {
    l = 0, r = 0;
    if (s[i] == 'A') {
      for (int j = 0; j < i; ++j)
        if (s[j] == 'Q') ++l;
      for (int j = i + 1; j < len; ++j)
        if (s[j] == 'Q') ++r;
      if (l && r) ans += max(l, r);
    }
  }
  cout << ans << endl;
  return 0;
}
