#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  string ret = (s[0] == s[1] && s[1] != s[2] && s[2] == s[2]) ? "Yes" : "No";
  cout << ret << endl;
  return 0;
}
