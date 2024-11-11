#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main() {
  cin >> s;
  if (s.size() == 1)
    n = s[0] - '0';
  else
    n = (s[s.size() - 2] - '0') * 10 + s[s.size() - 2] - '0';
  cout << (n % 4 ? 0 : 4);
  return 0;
}
