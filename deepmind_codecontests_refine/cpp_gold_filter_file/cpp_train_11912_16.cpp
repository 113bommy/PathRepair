#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool q1 = true;
  bool q2 = true;
  bool q3 = true;
  bool q4 = true;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1' && q1) {
      s.erase(i, 1);
      q1 = false;
      i--;
    } else if (s[i] == '6' && q2) {
      s.erase(i, 1);
      q2 = false;
      i--;
    } else if (s[i] == '8' && q3) {
      s.erase(i, 1);
      q3 = false;
      i--;
    } else if (s[i] == '9' && q4) {
      s.erase(i, 1);
      q4 = false;
      i--;
    }
  }
  int nasht = 0;
  int nash10 = 1;
  for (int i = 0; i < s.length(); i++) {
    nasht = (nasht + (s[s.length() - i - 1] - '0') * nash10) % 7;
    nash10 = (nash10 * 10) % 7;
  }
  std::vector<int> v;
  v.push_back(1);
  v.push_back(6);
  v.push_back(9);
  v.push_back(8);
  for (int i1 = 0; i1 < v.size(); i1++)
    for (int i2 = 0; i2 < v.size(); i2++)
      for (int i3 = 0; i3 < v.size(); i3++)
        for (int i4 = 0; i4 < v.size(); i4++) {
          if (i1 - i2 != 0 && i1 - i3 != 0 && i1 - i4 != 0 && i2 != i3 &&
              i2 != i4 && i3 != i4) {
            int a = 1000 * v[i1] + 100 * v[i2] + 10 * v[i3] + v[i4];
            if ((a * nash10 + nasht) % 7 == 0) {
              cout << a << s << endl;
              return 0;
            }
          }
        }
  return 0;
}
