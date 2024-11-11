#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> m;
  vector<char> v(4);
  for (int i = 0; i < 3; i++) {
    char a, b, c;
    cin >> a >> b >> c;
    if (b == '<') {
      m[c] += 1;
    } else if (b == '>') {
      m[a] += 1;
    }
  }
  if ((m['A'] == 1 && m['B'] == 1) || (m['C'] == 1 && m['B'] == 1) ||
      (m['A'] == 1 && m['C'] == 1) ||
      (m['A'] == 1 && m['B'] == 1 && m['C'] == 1))
    cout << "Impossible";
  else {
    for (auto it = m.begin(); it != m.end(); it++) {
      if (m[it->first == 5])
        ;
      if (it->second == 0) {
        v[0] = it->first;
      }
      if (it->second == 1) {
        v[1] = it->first;
      }
      if (it->second == 2) {
        v[2] = it->first;
      }
    }
    cout << v[0] << v[1] << v[2];
  }
  return 0;
}
