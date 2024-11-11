#include <bits/stdc++.h>
using namespace std;
bool issub(string a, string b) {
  if (a.find(b) == string::npos)
    return false;
  else
    return true;
}
int main() {
  string s1 = "31 28 31 30 31 30 31 31 31 30 31 30 31 ";
  string s2 = "31 29 31 30 31 30 31 31 31 30 31 30 31 ";
  string c1 = s1 + s1 + s1, c2 = s1 + s1 + s2, c3 = s1 + s2 + s1,
         c4 = s2 + s1 + s1;
  int t;
  string s;
  getline(cin, s);
  string str;
  getline(cin, str);
  if (issub(c1, str) || issub(c2, str) || issub(c3, str) || issub(c4, str))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
