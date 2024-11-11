#include <bits/stdc++.h>
using namespace std;
bool compare(string s1, string s2) {
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] != s2[i]) return false;
  }
  return true;
}
int main() {
  string s;
  string real = "CODEFORCES";
  cin >> s;
  bool f1 = 0, f2 = 0, f3 = 0;
  if (s.length() < 10) {
    cout << "No" << endl;
    return 0;
  }
  string s1 = s.substr(s.length() - 10, 10);
  string s2 = s.substr(0, 10);
  if (compare(s1, "CODEFORCES")) f1 = true;
  if (compare(s2, "CODEFORCES")) f3 = true;
  for (int i = 1; i <= 9; i++) {
    if (compare(s.substr(0, i), real.substr(0, i)) &&
        compare(s.substr(s.length() - 10 + i, 10 - i),
                real.substr(real.length() - 10 + i, 10 - i)))
      f2 = true;
  }
  if (f1 || f2 || f3) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
