#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, a, ta, b, tb, tm, can;
  string s;
  cin >> a >> ta;
  cin >> b >> tb;
  cin >> s;
  tm = (s[0] - '0') * 10 + s[1] - '0';
  tm = tm * 60 + (s[3] - '0') * 10 + s[4] - '0';
  can = 0;
  for (i = 300; i < 1440; i += b) {
    if (i > tm - tb && i < tm + ta) can++;
  }
  cout << can << endl;
}
