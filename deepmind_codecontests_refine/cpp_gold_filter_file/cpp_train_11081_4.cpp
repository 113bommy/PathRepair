#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  char mi, ma;
  int max = 0, min = INT_MAX;
  pair<int, char> p[4];
  for (int i = 0; i < 4; ++i) {
    cin >> s;
    p[i].first = s.length() - 2;
    p[i].second = s[0];
  }
  sort(p, p + 4);
  int flag1 = 0, flag2 = 0;
  for (int j = 1; j < 4; ++j) {
    if (2 * (p[0].first) <= p[j].first) flag1 += 1;
  }
  for (int j = 0; j < 3; ++j) {
    if (p[3].first >= 2 * (p[j].first)) flag2 += 1;
  }
  if (flag1 == 3 && flag2 != 3)
    cout << p[0].second << "\n";
  else if (flag2 == 3 && flag1 != 3)
    cout << p[3].second << "\n";
  else
    cout << "C\n";
  return 0;
}
