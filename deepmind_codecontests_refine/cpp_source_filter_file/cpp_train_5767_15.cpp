#include <bits/stdc++.h>
using namespace std;
double err = 0.0000001;
int n;
int x, y, s1, s2;
string s;
int main() {
  cin >> n >> x >> y >> s1 >> s2;
  cin >> s;
  int i = 0;
  while ((x != s1 || y != s2) && i < n) {
    if (s[i] == 'S') {
      if (s2 < y) y--;
    } else if (s[i] == 'N') {
      if (s2 > y) y++;
    } else if (s[i] == 'E') {
      if (s1 > x) x++;
    } else {
      if (s1 < x) x--;
    }
    i++;
  }
  if (x == s1 && y == s1)
    cout << i << endl;
  else
    cout << -1 << endl;
}
