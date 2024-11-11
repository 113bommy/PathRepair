#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  cin >> t;
  while (t--) {
    int cnto = 0, cntz = 0;
    string s;
    cin >> s;
    for (int i = 0; i < (s.size()); i++) {
      if (s[i] == '1')
        cnto++;
      else
        cntz++;
    }
    if (min(cnto, cntz) % 2 == 0)
      cout << "NET" << endl;
    else
      cout << "DA" << endl;
  }
  return 0;
}
