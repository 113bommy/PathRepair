#include <bits/stdc++.h>
using namespace std;
set<string> ss;
string s;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    ss.insert(s.substr(s.size() - i, i) + s.substr(0, s.size() - i));
  }
  cout << ss.size() << endl;
  return 0;
}
