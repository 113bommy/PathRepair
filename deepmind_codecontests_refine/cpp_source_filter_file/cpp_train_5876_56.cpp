#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s1, s2 = "";
  cin >> s >> s1;
  if (s.length() != s1.length()) {
    cout << "No";
    return 0;
  }
  for (int i = s.length() - 1; i >= 0; i--) s2 += s[i];
  if (s2.compare(s1) == 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
