#include <bits/stdc++.h>
using namespace std;
string s, s1, s2;
bool fn() {
  int i, j, k, flag = 0;
  int len = s.size();
  int len1 = s1.size();
  int len2 = s2.size();
  for (i = 0; i < len; i++) {
    for (j = i, k = 0; k < len1; j++, k++) {
      if (s[j] != s1[k] || j >= len) break;
    }
    if (k == len1) {
      flag++;
      break;
    }
  }
  for (i = i; i < len; i++) {
    for (j = i, k = 0; k < len2; j++, k++) {
      if (s[j] != s2[k] || i >= len) break;
    }
    if (k == len2) {
      flag++;
      break;
    }
  }
  if (flag == 2)
    return true;
  else
    return false;
}
int main() {
  cin >> s >> s1 >> s2;
  bool Forward = false;
  if (fn() == true) Forward = true;
  reverse(s.begin(), s.end());
  bool Backward = false;
  if (fn() == true) Backward = true;
  if (Forward && Backward)
    cout << "both" << endl;
  else if (Forward)
    cout << "forward" << endl;
  else if (Backward)
    cout << "backward" << endl;
  else
    cout << "fantasy" << endl;
  return 0;
}
