#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n = 0, l = 0;
  while (getline(cin, s)) {
    if (s[0] == '+')
      n++;
    else if (s[0] == '-')
      n--;
    else
      l += s.length() - s.find(':') - 1;
  }
  cout << l;
}
