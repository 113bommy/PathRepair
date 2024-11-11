#include <bits/stdc++.h>
using namespace std;
string s;
int open, closed, lacosa;
int main() {
  cin >> s;
  open = count(s.begin(), s.end(), '(');
  closed = count(s.begin(), s.end(), ')');
  lacosa = count(s.begin(), s.end(), '#');
  if (open < closed + lacosa) {
    return cout << -1, 0;
  }
  int diff = open - closed;
  int last = diff - (lacosa - 1);
  int a = 0, b = 0, cosa = 0;
  for (char u : s) {
    if (u == '(')
      a++;
    else if (u == ')')
      b++;
    else {
      if (cosa == lacosa - 1)
        b += last;
      else
        b++;
      cosa++;
    }
    if (a < b) return cout << -1, 0;
  }
  for (int i = 0; i < lacosa; i++) {
    if (i == lacosa - 1)
      cout << "1\n";
    else
      cout << last << "\n";
  }
  return 0;
}
