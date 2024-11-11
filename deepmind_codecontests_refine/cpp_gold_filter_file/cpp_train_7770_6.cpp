#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> symb[27];
  string s1, s2;
  char c;
  int a, i, j, count = 1;
  cin >> s1 >> s2;
  int l1 = s1.length(), l2 = s2.length();
  for (i = 0; i < l1; ++i) {
    a = (int)s1[i] - 96;
    symb[a].push_back(i);
  }
  vector<int>::iterator it;
  int now_last = -1, flag = 0;
  for (i = 0; i < l2; ++i) {
    a = (int)s2[i] - 96;
    if (symb[a].empty()) {
      flag = 1;
      break;
    } else {
      it = upper_bound(symb[a].begin(), symb[a].end(), now_last);
      if (it == symb[a].end()) {
        ++count;
        now_last = symb[a][0];
      } else
        now_last = *it;
    }
  }
  if (flag == 1)
    cout << -1;
  else {
    if (s1 == s2 && s1.length() > 1)
      cout << 1;
    else if (s1.length() == 1)
      cout << s2.length();
    else if (s1.length() != 1 && s1 != s2)
      cout << count;
  }
  return 0;
}
