#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int x = 0, y = 0, ans = 0;
  for (int i = 0; i < s.length() - 1; i++) {
    for (int j = i; j < s.length(); j++) {
      swap(s[i], s[j]);
      int zr = 0, mn = 0, c = 0;
      for (int k = 0; k < s.length(); k++) {
        s[k] == '(' ? zr++ : zr--;
        if (zr == mn) c++;
        if (zr < mn) mn = zr, c = 1;
      }
      if (!zr && c > ans) ans = c, x = i, y = j;
      swap(s[i], s[j]);
    }
  }
  cout << ans << "\n" << x + 1 << " " << y + 1;
  return 0;
}
