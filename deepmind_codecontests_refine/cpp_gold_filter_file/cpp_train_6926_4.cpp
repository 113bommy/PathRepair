#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> m;
  for (int i = 1989; i <= 3098; i++) {
    string tmp;
    int ti = i;
    while (ti) {
      tmp = char(ti % 10 + '0') + tmp;
      ti /= 10;
      if (!m.count(tmp)) {
        m[tmp] = i;
        break;
      }
    }
  }
  int n;
  scanf("%d", &n);
  while (n--) {
    string s;
    cin >> s;
    s.erase(0, 4);
    if (m.count(s)) {
      cout << m[s] << endl;
      continue;
    }
    string tmp;
    for (int i = 0; i + 4 < s.size(); i++) tmp += '1';
    tmp += "3098";
    if (s <= tmp) cout << "1";
    cout << s << endl;
  }
  return 0;
}
