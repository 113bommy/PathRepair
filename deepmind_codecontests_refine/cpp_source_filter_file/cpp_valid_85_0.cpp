#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k1 = 0, k2 = 0;
    string s;
    cin >> s;
    if (s[0] == '0') k2++;
    if (s[0] == '1') k1++;
    for (int i = 1; i < s.size(); i++) {
      if (s[i - 1] != s[i]) {
        if (s[i] == '1') k1++;
        if (s[i] == '0') k2++;
      }
    }
    if (k1 > 3)
      cout << 2 << endl;
    else if (k1 == 0)
      cout << 1 << endl;
    else if (k2 == 0)
      cout << 0 << endl;
    else if (k2 > 2)
      cout << 2;
    else
      cout << k2 << endl;
  }
}
