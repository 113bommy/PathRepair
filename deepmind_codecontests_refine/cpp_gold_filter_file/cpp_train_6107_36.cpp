#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int coun = 0;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) {
      coun++;
      if (coun == 6) break;
    } else
      coun = 0;
  }
  if (coun == 6)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
