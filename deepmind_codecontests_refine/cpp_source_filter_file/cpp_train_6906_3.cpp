#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
char linie[1 + N], s[1 + N];
int nl, ns;
bool ultimampl = true;
bool amplifica() {
  int i = 0;
  while (linie[i] == ' ') {
    i++;
  }
  if (linie[i] == '#') {
    return true;
  }
  nl = 0;
  for (i = 0; linie[i] >= 32 && linie[i] < 128; i++) {
    if (linie[i] != ' ') {
      linie[nl++] = linie[i];
    }
  }
  linie[nl] = 0;
  return false;
}
int main() {
  cin.getline(linie, 1 + N);
  while (!cin.eof()) {
    if (!amplifica()) {
      strcpy(s + ns, linie);
      ns += nl;
      ultimampl = false;
    } else {
      if (!ultimampl) {
        cout << s << "\r\n";
      }
      cout << linie << "\r\n";
      s[0] = 0;
      ns = 0;
      ultimampl = true;
    }
    cin.getline(linie, 1 + N);
  }
  if (!ultimampl) {
    cout << s << "\r\n";
  }
  return 0;
}
