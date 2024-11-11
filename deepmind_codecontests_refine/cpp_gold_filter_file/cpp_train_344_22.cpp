#include <bits/stdc++.h>
using namespace std;
bool gt(long double a, long double b) { return a > b + 1e-9; }
string a, b;
int fa[26], fb[26];
int main() {
  ios::sync_with_stdio(false);
  cin >> a >> b;
  for (int same = min(((int)(a).size()), ((int)(b).size())); same >= 0;
       same--) {
    memset(fa, 0, sizeof fa);
    memset(fb, 0, sizeof fb);
    for (register int i = (0); i < (int)(same); ++i) fb[b[i] - 'a']++;
    for (register int i = (0); i < (int)(((int)(a).size())); ++i)
      fa[a[i] - 'a']++;
    bool ok = true;
    for (register int i = (0); i < (int)(26); ++i)
      if (fa[i] < fb[i])
        ok = false;
      else
        fa[i] -= fb[i];
    if (!ok) continue;
    string tmp = b.substr(0, same);
    for (register int i = (0); i < (int)(26); ++i)
      if (i + 'a' > b[same] && fa[i] > 0) {
        fa[i]--;
        tmp += char(i + 'a');
        break;
      }
    for (register int i = (0); i < (int)(26); ++i)
      while (fa[i]--) tmp += char(i + 'a');
    if (tmp > b) {
      cout << tmp << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
