#include <bits/stdc++.h>
using namespace std;
string s, s1, s2, q = "rock", w = "paper", e = "scissors";
int main() {
  cin >> s >> s1 >> s2;
  if (s != s1 && s1 == s2 && s == q && s1 == e ||
      s != s1 && s1 == s2 && s == w && s1 == q ||
      s != s1 && s1 == s2 && s == e && s1 == w)
    cout << "F";
  else if (s1 != s && s == s2 && s1 == q && s == e ||
           s1 != s && s == s2 && s1 == w && s == q ||
           s1 != s && s == s2 && s1 == e && s == w)
    cout << "M";
  else if (s2 != s && s == s1 && s2 == q && s == e ||
           s2 != s && s == s1 && s2 == w && s == q ||
           s2 != s && s == s1 && s1 == e && s == w)
    cout << "S";
  else
    cout << "?";
}
