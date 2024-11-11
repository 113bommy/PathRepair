#include <bits/stdc++.h>
using namespace std;
int main() {
  set<string> myset;
  int n;
  cin >> n;
  string s;
  string::size_type pos;
  while (n--) {
    cin >> s;
    while ((pos = s.find("oo")) != string::npos) {
      s = s.substr(0, pos) + 'u' + s.substr(pos + 2);
    }
    while ((pos = s.find("kh")) != string::npos) {
      s.erase(pos, 1);
    }
    myset.insert(s);
  }
  cout << myset.size() << endl;
  return 0;
}
