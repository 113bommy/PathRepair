#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  int i, j, t, tc = 1, a, b;
  cin >> s;
  int l = s.length();
  long long ans = 0;
  for (i = 0; i < l; i++) {
    if (s[i] == '7')
      ans += 2 * pow(2, l - 1 - i);
    else
      ans += 1 * pow(2, l - 1 - i);
  }
  cout << ans << endl;
  return 0;
}
