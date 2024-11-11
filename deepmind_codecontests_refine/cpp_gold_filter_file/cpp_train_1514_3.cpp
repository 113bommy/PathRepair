#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int c = 0;
  for (int i = 1; i < 7; i++) {
    if (s[i] == '1') {
      c += 10;
    } else
      c += (s[i] - '0');
  }
  cout << ++c << '\n';
  return 0;
}
