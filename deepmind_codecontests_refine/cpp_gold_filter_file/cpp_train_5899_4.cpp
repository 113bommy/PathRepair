#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0, a = 0, b = 0, c = 0;
  while (s[i] == 'a' && i != s.size()) {
    a++;
    i++;
  }
  while (s[i] == 'b' && i != s.size()) {
    b++;
    i++;
  }
  while (s[i] == 'c' && i != s.size()) {
    c++;
    i++;
  }
  if ((c == a || c == b) && c != 0 && b != 0 && a != 0 && i == s.size())
    cout << "YES";
  else
    cout << "NO";
}
