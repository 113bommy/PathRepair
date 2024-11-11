#include <bits/stdc++.h>
using namespace std;
int cmp(string s1, string s2) {
  if (s1.length() > s2.length()) return 1;
  if (s1.length() < s2.length()) return -1;
  if (s1 >= s2)
    return 1;
  else
    return -1;
}
int main() {
  string p;
  cin >> p;
  string a, b;
  int ans = 1;
  for (int i = 0; i < p.length(); i++) {
    string tmp;
    while (i < p.length() - 1 && p[i + 1] == '0') {
      tmp += p[i];
      i++;
    }
    tmp += p[i];
    if (a == "")
      a = tmp;
    else {
      b = tmp;
      if (cmp(a, b) == 1) {
        ans++;
        a = a + b;
      } else {
        ans = 1;
        a = a + b;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
