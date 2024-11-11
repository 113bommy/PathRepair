#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<int, int> u, d, r, l, c;
  u.first = 0;
  u.second = 1;
  d.first = 0;
  d.second = -1;
  r.first = 1;
  r.second = 0;
  l.first = -1;
  l.second = 0;
  int ans = 0, n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'U') {
      c.first += u.first;
      c.second += u.second;
    } else if (s[i] == 'D') {
      c.first += d.first;
      c.second += d.second;
    } else if (s[i] == 'L') {
      c.first += l.first;
      c.second += l.second;
    } else {
      c.first += r.first;
      c.second += r.second;
    }
    for (int j = i + 1; j < n; j++) {
      if (s[j] == 'U') {
        c.first += u.first;
        c.second += u.second;
      } else if (s[j] == 'D') {
        c.first += d.first;
        c.second += d.second;
      } else if (s[j] == 'L') {
        c.first += l.first;
        c.second += l.second;
      } else {
        c.first += r.first;
        c.second += r.second;
      }
      if (c.first == 0 && c.second == 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
