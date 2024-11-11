#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int x = 0, it = 0;
  if (s[0] == '-') it = 1, cout << '(';
  cout << '$';
  for (int i = it; i < s.size(); i++) {
    if (s[i] == '.') break;
    x = i;
  }
  int d = (x + 1 - it) % 3;
  for (int i = it; i < it + d; i++) cout << s[i];
  if (it + d < x && d > 0) cout << ',';
  for (int i = it + d; i < x; i++) {
    cout << s[i];
    if ((i - it - d + 1) % 3 == 0) cout << ',';
  }
  if (it + d < x) cout << s[x];
  cout << '.';
  it = 0, d = s.size();
  for (int i = x + 2; i < min(x + 4, d); i++) {
    cout << s[i];
    it++;
  }
  for (int i = 1; i <= 2 - it; i++) cout << 0;
  if (s[0] == '-') cout << ')';
}
