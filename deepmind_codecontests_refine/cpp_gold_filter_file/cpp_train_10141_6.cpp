#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  int ans = 0;
  int nr = s.size();
  if (nr == 2) {
    cout << 1;
    return 0;
  }
  s += s;
  for (int i = 0; i < nr; i++) {
    if (s[i] != s[i + 1]) {
      if (s[i] != s[i + 2])
        ans++;
      else if (s[i] != s[i + 3]) {
        ans++;
        i++;
      }
    }
  }
  cout << ans;
  return 0;
}
