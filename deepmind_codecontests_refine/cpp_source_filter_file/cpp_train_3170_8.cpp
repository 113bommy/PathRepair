#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int inta = 0, intb = 0;
  string stringa, stringb;
  string c;
  cin >> c;
  stringa = c;
  inta++;
  for (int i = 2; i <= n; i++) {
    cin >> c;
    if (c == stringa)
      inta++;
    else
      intb++, stringb = intb;
  }
  if (inta > intb)
    cout << stringa;
  else
    cout << stringb;
  return 0;
}
