#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  string re = s;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == 'z')
      re[i] = 'a';
    else {
      re[i]++;
      break;
    }
  }
  if (re == t)
    cout << "No such string";
  else
    cout << re;
  return 0;
}
