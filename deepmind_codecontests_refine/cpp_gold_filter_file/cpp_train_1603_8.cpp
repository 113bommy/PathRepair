#include <bits/stdc++.h>
using namespace std;
int n, m, longest[2200000], k[2200000], first, last, tmp;
bool _[2200000];
int ans;
bool d[220000];
int main(int argc, char *argv[]) {
  int i, x, len;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &len);
    if (longest[x] < len) {
      longest[x] = len;
      k[x] = i;
    }
  }
  for (i = 1; i <= n; i++) first = 1;
  last = 0;
  int tmplast, tmpk;
  while (first <= n) {
    if (longest[first] != 0 && first > last) {
      _[first] = true;
      last = first + longest[first] - 1;
      tmplast = last;
      tmpk = 0;
      while (first <= last + 1) {
        if (first + longest[first] - 1 > tmplast) {
          tmplast = first + longest[first] - 1;
          tmpk = first;
        }
        if (first == last + 1) {
          _[tmpk] = true;
          last = tmpk + longest[tmpk] - 1;
          tmplast = last;
          tmpk = 0;
        }
        first++;
      }
    } else
      first++;
  }
  for (i = 1; i <= n; i++) ans += _[i];
  ans = m - ans;
  cout << ans << endl;
  tmpk = 0;
  for (i = 1; i <= n; i++)
    if (_[i]) d[k[i]] = true;
  for (i = 1; i <= m; i++)
    if (!d[i]) {
      cout << i;
      break;
    }
  for (i++; i <= m; i++)
    if (!d[i]) cout << " " << i;
  if (ans != 0) cout << endl;
  return EXIT_SUCCESS;
}
