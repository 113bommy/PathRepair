#include <bits/stdc++.h>
using namespace std;
int main() {
  string txt;
  cin >> txt;
  if (txt.size() < 5) {
    cout << "Too weak" << endl;
    return 0;
  }
  int helpu = 0, helpl = 0, helpc = txt.size(), helpd = 0;
  for (int i = 0; i < helpc; i++) {
    if (int(txt[i]) >= int('A') and int(txt[i]) < int('a'))
      helpu++;
    else if (int(txt[i]) >= int('a') and int(txt[i]) <= int('z'))
      helpl++;
    else if (int(txt[i]) >= 48 and int(txt[i]) <= 57)
      helpd++;
  }
  if (helpl >= 1 and helpu >= 1 and helpd >= 1)
    cout << "Correct" << endl;
  else
    cout << "Too weak" << endl;
}
