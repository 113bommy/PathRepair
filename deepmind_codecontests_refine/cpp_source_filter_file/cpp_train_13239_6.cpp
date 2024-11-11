#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ans = 0;
  int cnt1 = 0;
  for (int i = s.size() - 1; i >= 0; i -= 2) {
    if (s[i] == '1') {
      cnt1 += 1;
    }
  }
  if (cnt1 == 1)
    ans = (s.size() - 1) / 2;
  else
    ans = (s.size() - 1) / 2 + 1;
  if (cnt1 == 0) ans = 0;
  cout << ans << endl;
  return 0;
}
