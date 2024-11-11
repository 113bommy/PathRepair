#include <bits/stdc++.h>
using namespace std;
char beats(char c) {
  if (c == 'p') return 'r';
  if (c == 'r') return 's';
  if (c == 's') return 'p';
  return 'h';
}
int main() {
  vector<char> v(3);
  map<char, int> m;
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    v[i] = s[0];
    m[s[0]];
  }
  if (m.size() == 3 || m.size() == 1) {
    cout << "?" << endl;
    return 0;
  }
  map<char, int>::iterator p = m.begin();
  ++p;
  if (beats(m.begin()->first) == p->first) p = m.begin();
  if (p->second == 1) {
    int n = find(v.begin(), v.end(), p->first) - v.begin();
    if (n == 0)
      cout << "F" << endl;
    else if (n == 1)
      cout << "M" << endl;
    else
      cout << "S" << endl;
  } else
    cout << "?" << endl;
  return 0;
}
