#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0, stl = -1, enl = -1, str = -1, enr = -1;
  string s;
  string::const_iterator it;
  cin >> n;
  cin >> s;
  it = s.begin();
  for (i = 0; i < n; i++) {
    if (*it == 'R' && stl == -1) {
      stl = i;
      enl = i;
    } else if (*it == 'R' && stl != -1)
      enl = i;
    else if (*it == 'L' && str == -1) {
      str = i;
      enr = i;
    } else if (*it == 'L' && enr == -1)
      enr = i;
    it++;
  }
  if (stl != -1 && str != -1)
    cout << stl + 1 << " " << str << endl;
  else if (stl != -1 && str == -1)
    cout << stl + 1 << " " << enl + 2 << endl;
  else if (stl == -1 && str != -1)
    cout << str + 1 << " " << enr << endl;
  return 0;
}
