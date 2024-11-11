#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int f = 0;
  for (int i = 0; i < 8; i++) {
    cin >> s;
    if (s.find("BB") != string::npos || s.find("WW") != string::npos) f = 1;
  }
  if (f == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
