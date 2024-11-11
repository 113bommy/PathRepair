#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  char ch;
  unsigned long long int pl, i, sr = 0, sl = 0;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == '^') break;
  }
  pl = i;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == '=' || s[i] == '^')
      continue;
    else if (i < pl) {
      sl += (int(s[i]) - 48) * (pl - i);
    } else {
      sr += (int(s[i]) - 48) * (i - pl);
    }
  }
  if (sr > sl)
    cout << "right";
  else if (sl > sr)
    cout << "left";
  else
    cout << "balanced";
  return 0;
}
