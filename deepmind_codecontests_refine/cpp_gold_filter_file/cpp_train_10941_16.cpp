#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int a = 300001, b = 300001, c = 300001, abc, min = 300001, i, j, k, q;
  bool x, y, z;
  vector<string> p;
  vector<int> m;
  string s;
  cin >> t;
  while (t > 0) {
    cin >> q;
    m.push_back(q);
    cin >> s;
    p.push_back(s);
    if (s == "A" && a > q)
      a = q;
    else if (s == "B" && b > q)
      b = q;
    else if (s == "C" && c > q)
      c = q;
    else {
      x = false;
      y = false;
      z = false;
      for (i = 0; i < s.length(); i++) {
        if (s[i] == 'A') x = true;
        if (s[i] == 'B') y = true;
        if (s[i] == 'C') z = true;
      }
      if (x && y && z) {
        if (q < min) min = q;
        p.pop_back();
        m.pop_back();
      }
    }
    t--;
  }
  if (a + b + c < min) min = a + b + c;
  for (i = 0; i < p.size(); i++) {
    for (j = 0; j < p.size(); j++) {
      if (i != j) {
        s = p[i];
        x = false;
        y = false;
        z = false;
        for (k = 0; k < s.length(); k++) {
          if (s[k] == 'A') x = true;
          if (s[k] == 'B') y = true;
          if (s[k] == 'C') z = true;
        }
        s = p[j];
        for (k = 0; k < s.length(); k++) {
          if (s[k] == 'A') x = true;
          if (s[k] == 'B') y = true;
          if (s[k] == 'C') z = true;
        }
        if (x && y && z) {
          if (m[i] + m[j] < min) min = m[i] + m[j];
        }
      }
    }
  }
  if (min <= 300000)
    cout << min;
  else
    cout << "-1";
  return 0;
}
