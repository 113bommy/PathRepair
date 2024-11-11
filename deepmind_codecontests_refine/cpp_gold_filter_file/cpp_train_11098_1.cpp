#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
int main() {
  m['v'] = 0;
  m['<'] = 1;
  m['^'] = 2;
  m['>'] = 3;
  char a, b;
  int n;
  cin >> a >> b >> n;
  n %= 4;
  int x = m[b] - m[a];
  if (x < 0) x += 4;
  if (n == 0 || n == 2)
    cout << "undefined";
  else if (x == n)
    cout << "cw";
  else if (x == 4 - n)
    cout << "ccw";
  else
    cout << "undefined";
}
