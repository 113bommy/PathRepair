#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char m;
  cin >> m;
  if (m == 'L') {
    map<char, char> l;
    l['q'] = 'w';
    l['w'] = 'e';
    l['e'] = 'r';
    l['r'] = 't';
    l['t'] = 'y';
    l['y'] = 'u';
    l['u'] = 'i';
    l['i'] = 'o';
    l['o'] = 'p';
    l['p'] = 'p';
    l['a'] = 's';
    l['s'] = 'd';
    l['d'] = 'f';
    l['f'] = 'g';
    l['g'] = 'h';
    l['h'] = 'j';
    l['j'] = 'k';
    l['k'] = 'l';
    l['l'] = ';';
    l[';'] = ';';
    l['z'] = 'x';
    l['x'] = 'c';
    l['c'] = 'v';
    l['v'] = 'b';
    l['b'] = 'n';
    l['n'] = 'm';
    l['m'] = ',';
    l[','] = '.';
    l['.'] = '/';
    l['/'] = '/';
    string s;
    cin >> s;
    for (auto c : s) {
      cout << l[c];
    }
  } else {
    map<char, char> l;
    l['q'] = 'q';
    l['w'] = 'q';
    l['e'] = 'w';
    l['r'] = 'e';
    l['t'] = 'r';
    l['y'] = 't';
    l['u'] = 'y';
    l['i'] = 'u';
    l['o'] = 'i';
    l['p'] = 'o';
    l['a'] = 'a';
    l['s'] = 'a';
    l['d'] = 's';
    l['f'] = 'd';
    l['g'] = 'h';
    l['h'] = 'g';
    l['j'] = 'h';
    l['k'] = 'j';
    l['l'] = 'k';
    l[';'] = 'l';
    l['z'] = 'z';
    l['x'] = 'z';
    l['c'] = 'x';
    l['v'] = 'c';
    l['b'] = 'v';
    l['n'] = 'b';
    l['m'] = 'n';
    l[','] = 'm';
    l['.'] = ',';
    l['/'] = '.';
    string s;
    cin >> s;
    for (auto c : s) {
      cout << l[c];
    }
  }
  return 0;
}
