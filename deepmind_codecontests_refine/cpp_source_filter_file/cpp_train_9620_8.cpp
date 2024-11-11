#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int F = 0, pos = 0;
  bool ok = true;
  for (int i = 0; s[i]; i++) {
    if (s[i] == 'F') {
      if (ok)
        pos = i + (ok = 0);
      else
        pos = max(i - F, pos + (i != 0));
      F++;
    }
  }
  cout << pos << endl;
  return 0;
}
