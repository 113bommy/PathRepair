#include <bits/stdc++.h>
using namespace std;
int t, i;
string s;
int main() {
  cin >> t;
  while (t--) {
    cin >> s;
    int k0 = 0, k1 = 0;
    for (i = 0; i < s.length(); i++)
      if (s[i] == '0')
        k0++;
      else
        k1++;
    if (min(k0, k1) % 2 != 0)
      cout << "DA\n";
    else
      cout << "NET\n";
  }
}
