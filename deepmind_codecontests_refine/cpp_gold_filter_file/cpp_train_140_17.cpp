#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, res;
  int a;
  cin >> s >> a;
  res = s;
  int i;
  for (i = 0; i < s.length(); i++) {
    int c = (int)(s[i]);
    if (c > 96) c -= 32;
    if (c >= a + 65)
      res[i] = (char)(c + 32);
    else
      res[i] = (char)c;
  }
  cout << res;
  return 0;
}
