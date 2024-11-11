#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = (int)s.length();
  if (l < 5)
    cout << "Too weak\n";
  else {
    int f1 = 0, f2 = 0, f3 = 0;
    for (int(i) = (0); (i) < (l); (i)++) {
      if (s[i] >= 'A' && s[i] <= 'Z') f1 = 1;
      if (s[i] >= 'a' && s[i] <= 'z') f2 = 1;
      if (s[i] >= '0' && s[i] <= '9') f3 = 1;
    }
    if (f1 && f2 && f3)
      cout << "Correst\n";
    else
      cout << "Too weak\n";
  }
  return 0;
}
