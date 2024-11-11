#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int q = 0, qm = 0, res = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == 'Q') q++;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'Q')
      qm++;
    else if (s[i] == 'A')
      if (qm > 0 && q - qm > 0) res += ((q - qm) * qm);
  }
  cout << res;
  return 0;
}
