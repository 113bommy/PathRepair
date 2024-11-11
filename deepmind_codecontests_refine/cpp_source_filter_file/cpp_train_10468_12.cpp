#include <bits/stdc++.h>
using namespace std;
int k, d, v2, v1, b;
string s;
int main() {
  cin >> s;
  if (s[0] == 'a' || s[0] == 'h') {
    if (s[1] != '1' && s[1] != '8')
      k = 6;
    else
      k = 3;
  } else if (s[1] == '8' || s[1] == '1')
    k = 6;
  else
    k = 8;
  cout << k;
  return 0;
}
