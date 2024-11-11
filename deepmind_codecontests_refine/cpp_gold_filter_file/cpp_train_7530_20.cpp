#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s1, s2;
  cin >> s;
  s1 = s;
  sort(s1.begin(), s1.end());
  s2 += s1[0];
  for (int i = 1; i < s1.length(); i++) {
    if (s1[i] != s1[i - 1]) s2 += s1[i];
  }
  int d = 0;
  for (int j = s2.length() - 1; j >= 0; j--) {
    for (int i = d; i < s.length(); i++) {
      if (s2[j] == s[i]) cout << s[i], d = i + 1;
    }
  }
  cout << endl;
  return 0;
}
