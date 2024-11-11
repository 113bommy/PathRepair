#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, q, s, w, l, r;
string t;
char p;
int main() {
  cin >> n;
  l = -1e9;
  l--;
  r = 1e8;
  r++;
  while (n--) {
    cin >> t;
    cin >> s;
    cin >> p;
    if (t.length() == 1 && t[0] == '<') {
      if (p == 'Y')
        r = min(s - 1, r);
      else
        l = max(l, s);
    }
    if (t.length() == 1 && t[0] == '>') {
      if (p == 'Y')
        l = max(l, s + 1);
      else
        r = min(s, r);
    }
    if (t.length() == 2 && t[0] == '<') {
      if (p == 'Y')
        r = min(r, s);
      else
        l = max(l, s + 1);
    }
    if (t.length() == 2 && t[0] == '>') {
      if (p == 'Y')
        l = max(l, s);
      else
        r = min(s - 1, r);
    }
  }
  if (l <= r)
    cout << l << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}
