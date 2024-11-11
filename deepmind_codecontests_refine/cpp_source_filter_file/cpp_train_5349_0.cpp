#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  string sEnd = s.substr(2, s.length());
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  cout << s[0] << sEnd;
  return 0;
}
