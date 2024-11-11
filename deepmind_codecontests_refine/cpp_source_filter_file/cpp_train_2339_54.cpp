#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, r = "rock", p = "paper", s = "scissors";
bool c(string a, string b) {
  if ((a == r && b == s) || (a == s && b == p) || (a == p && b == s))
    return true;
  return false;
}
int main() {
  cin >> s1 >> s2 >> s3;
  if (s1 == s2 && s2 == s3) return cout << "?", 0;
  if (s1 != s2 && s2 != s3 && s3 != s1) return cout << "?", 0;
  if ((s1 == s2 && c(s1, s3)) || (s1 == s3 && c(s1, s2)) ||
      (s2 == s3 && c(s2, s1)))
    cout << "?";
  else if (s1 == s2)
    cout << "S";
  else if (s1 == s3)
    cout << "M";
  else if (s2 == s3)
    cout << "F";
}
