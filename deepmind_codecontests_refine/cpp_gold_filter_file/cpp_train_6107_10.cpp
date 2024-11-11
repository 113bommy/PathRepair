#include <bits/stdc++.h>
using namespace std;
int main() {
  string t;
  cin >> t;
  int s = 0, z = 0;
  int n = t.length();
  for (int i = 0; i < n; i++) {
    if (t.at(i) == '0')
      s++;
    else if (t.at(i) == '1')
      z++;
    if (s < 7 && t.at(i) == '1')
      s = 0;
    else if (z < 7 && t.at(i) == '0')
      z = 0;
  }
  if (s >= 7 || z >= 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
