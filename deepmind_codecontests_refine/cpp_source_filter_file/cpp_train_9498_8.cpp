#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int a[101], c, ans;
  getline(cin, s);
  for (int i = 0; i <= s.length(); i++) a[i] = 0;
  for (int i = 0; i < s.length(); i++) {
    c = (int)s[i];
    for (int j = 0; j < 8; j++)
      if ((c & (int)pow(2, j)) != 0) a[i + 1] += (int)pow(2, 7 - j);
    ans = (a[i] - a[i + 1]) % 256;
    if (ans < 0) ans += 256;
    cout << ans << "1n";
  }
  return 0;
}
