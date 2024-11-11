#include <bits/stdc++.h>
using namespace std;
int kolvo[200000], n;
string s;
bool check(string s1, string s2) {
  if (s1.length() != s2.length())
    return s1.length() < s2.length();
  else
    return s1 <= s2;
}
int main() {
  getline(cin, s);
  string bute = "127";
  string shor = "32767";
  string integ = "2147483647";
  string lon = "9223372036854775807";
  if (check(s, bute))
    cout << "byte";
  else if (check(s, shor))
    cout << "short";
  else if (check(s, integ))
    cout << "int";
  else if (check(s, lon))
    cout << "long";
  else
    cout << "BigInteger";
}
