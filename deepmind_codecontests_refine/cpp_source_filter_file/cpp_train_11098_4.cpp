#include <bits/stdc++.h>
using namespace std;
int main() {
  char s, s1;
  cin >> s >> s1;
  long int n;
  cin >> n;
  n %= 4;
  if (n == 0 || n == 2)
    cout << "undefined" << endl;
  else if (((s == 'v' && s1 == '<') || (s == '<' && s1 == '^') ||
            (s == '^' && s1 == '>') || (s == '>' || s1 == 'v')) &&
           n == 1)
    cout << "cw" << endl;
  else if (((s == 'v' && s1 == '<') || (s == '<' && s1 == '^') ||
            (s == '^' && s1 == '>') || (s == '>' || s1 == 'v')) &&
           n == 3)
    cout << "ccw" << endl;
  else if (((s == 'v' && s1 == '>') || (s == '<' && s1 == 'v') ||
            (s == '^' && s1 == '<') || (s == '>' || s1 == '^')) &&
           n == 3)
    cout << "cw" << endl;
  else if (((s == 'v' && s1 == '>') || (s == '<' && s1 == 'v') ||
            (s == '^' && s1 == '<') || (s == '>' || s1 == '^')) &&
           n == 1)
    cout << "ccw" << endl;
  else
    cout << "undefined" << endl;
  return 0;
}
