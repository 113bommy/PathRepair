#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  char c = s[0];
  int d = s[1] - '0', m = 8;
  if (s == "a8" || s == "h8" || s == "a1" || s == "h1")
    m = 3;
  else if (c == 'a' || c == 'h' || d == 1 || d == 8)
    m = 5;
  cout << m;
}
