#include <bits/stdc++.h>
using namespace std;
int main() {
  int counta = 0;
  int people = 0;
  string s;
  while (getline(cin, s)) {
    if (s[0] == '+')
      people++;
    else if (s[0] == '-')
      people--;
    else {
      int pos = s.find(':');
      int l = s.length() - pos;
      counta = counta + people * l;
    }
  }
  cout << counta;
  return 0;
}
