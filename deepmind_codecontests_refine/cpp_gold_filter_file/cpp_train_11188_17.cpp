#include <bits/stdc++.h>
using namespace std;
struct d {
  string source;
  string cur;
  string next;
};
int main() {
  int n;
  cin >> n;
  map<string, string> m;
  map<string, string>::iterator it;
  while (n) {
    n--;
    string tmp, tmp1;
    cin >> tmp >> tmp1;
    if (m.end() != m.find(tmp)) {
      string s2 = m[tmp];
      m.erase(tmp);
      m[tmp1] = s2;
    } else {
      m[tmp1] = tmp;
    }
  }
  cout << m.size() << "\n";
  for (it = m.begin(); it != m.end(); it++) {
    cout << it->second << " " << it->first << "\n";
  }
  return 0;
}
