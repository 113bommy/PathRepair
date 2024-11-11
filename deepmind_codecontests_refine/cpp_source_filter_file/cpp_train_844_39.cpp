#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int i, j, k;
  int n;
  cin >> n;
  int x = n / 4;
  string s = "abcd";
  string ans = "";
  if (n % 4 == 0)
    for (i = 0; i < n; i++) ans += s;
  else {
    if (n % 4 == 1) {
      for (i = 0; i < x; i++) ans += s;
      ans += 'a';
    }
    if (n % 4 == 2) {
      for (i = 0; i < x; i++) ans += s;
      ans += "ab";
    }
    if (n % 4 == 3) {
      for (i = 0; i < x; i++) ans += s;
      ans += "abc";
    }
  }
  cout << ans << endl;
  return 0;
}
