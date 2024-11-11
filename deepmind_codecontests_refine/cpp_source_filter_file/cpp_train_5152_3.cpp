#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> m;
  string s;
  cin >> s;
  int n;
  cin >> n;
  string temp;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    string str = temp.substr(0, s.length());
    if (str == s) {
      m[temp] = 1;
    }
  }
  if (m.begin() != m.end()) {
    cout << (*(m.begin())).first << endl;
  } else {
    cout << endl;
  }
  return 0;
}
