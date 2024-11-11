#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int p, le = 0, ri = 0;
  int l = s.length();
  for (int i = 0; i < l; i++) {
    if (s[i] == '^') p = i;
  }
  for (int i = 0; i < p; i++) {
    if (s[i] != '=') {
      le += (p - i) * (s[i] - '0');
    }
  }
  for (int i = p + 1; i < l; i++) {
    if (s[i] != '=') {
      ri += (i - p) * (s[i] - '0');
    }
  }
  if (ri == le) cout << "balance" << endl;
  if (ri > le) cout << "right" << endl;
  if (le > ri) cout << "left" << endl;
  return 0;
}
