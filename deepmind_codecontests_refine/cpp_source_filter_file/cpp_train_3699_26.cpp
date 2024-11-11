#include <bits/stdc++.h>
using namespace std;
int n, r, g, b;
string s;
int main() {
  cin >> n >> s;
  if (s == string(n, s[0]))
    cout << s[0] << endl;
  else {
    for (auto i = 0; i < s.length(); i++) {
      if (s[i] == 'R') r++;
      if (s[i] == 'G') g++;
      if (s[i] == 'B') b++;
    }
    if (r != n - 1) cout << 'R';
    if (g != n - 1) cout << 'G';
    if (b != n - 1) cout << 'B';
  }
  return 0;
}
