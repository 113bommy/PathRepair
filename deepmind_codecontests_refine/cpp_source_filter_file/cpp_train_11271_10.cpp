#include <bits/stdc++.h>
using namespace std;
int main() {
  int nrElem;
  cin >> nrElem;
  for (int i = 1; i <= nrElem; i++) {
    int nr, ok = 0, k = 0;
    char s[105];
    cin >> nr;
    cin.get();
    cin >> s;
    for (int i = 0; i < strlen(s); i++) {
      if ((s[i] - '0') == 1) k++;
      if ((s[i] - '0') == 0) ok++;
    }
    if (ok >= k) {
      for (int i = 1; i <= nr; i++) cout << 0;
      cout << "\n";
    } else {
      for (int i = 1; i <= nr; i++) cout << 0;
      cout << "\n";
    }
  }
  return 0;
}
