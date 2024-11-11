#include <bits/stdc++.h>
using namespace std;
int m, lu, i, p, po, j, mr;
char in, st[100010];
bool mrk[100010], ok;
int main() {
  ifstream f("a.in");
  ofstream g("a.out");
  cin >> m;
  cin >> st;
  if (m == 1) {
    lu = strlen(st);
    sort(st, st + lu);
    cout << st;
  } else {
    lu = strlen(st);
    for (in = 'a'; in <= 'z'; ++in) {
      ok = true;
      p = 0;
      mr = 0;
      for (i = 0; i < m; ++i)
        if (st[i] == in) {
          mrk[i] = true;
          mr++;
        } else if (mrk[i])
          mr++;
      if (mr == 0) ok = false;
      j = 0;
      for (i = m; i < lu; ++i) {
        if (st[i] == in)
          mrk[i] = true, ++mr;
        else if (mrk[i])
          mr++;
        if (mrk[j]) --mr;
        ++j;
        if (mr == 0) ok = false;
      }
      if (ok) {
        for (i = 0; i < lu; ++i)
          if (st[i] == in) mrk[i] = false;
        p = 0;
        mr = 0;
        ok = false;
        for (i = 0; i < m; ++i)
          if (st[i] == in)
            p = i;
          else if (mrk[i])
            mr++;
        j = 0;
        for (i = m; i < lu; ++i) {
          if (st[i] == in)
            p = i;
          else if (mrk[i])
            mr++;
          if (mrk[j]) --mr;
          ++j;
          if (mr == 0) {
            ok = true;
            mrk[p] = true;
            if (p >= j) ++mr;
            g << in;
          }
        }
        if (m == lu || !ok) cout << in;
        return 0;
      } else
        for (i = 0; i < lu; ++i)
          if (st[i] == in) cout << in;
    }
  }
  return 0;
}
