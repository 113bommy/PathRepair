#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int c0 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') ++c0;
  }
  int c1 = (int)s.size() - c0;
  int d = min(c0, c1);
  cout << c0 + c1 - 2 * d << endl;
  return 0;
}
