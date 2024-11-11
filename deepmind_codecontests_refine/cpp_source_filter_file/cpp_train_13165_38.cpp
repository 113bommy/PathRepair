#include <bits/stdc++.h>
using namespace std;
int main() {
  string c;
  while (cin >> c) {
    map<char, int> m;
    m['0'] = 2;
    m['1'] = 6;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 3;
    m['5'] = 2;
    m['6'] = 2;
    m['7'] = 5;
    m['8'] = 1;
    m['9'] = 2;
    cout << m[c[0]] * m[c[1]] << endl;
  }
  return 0;
}
