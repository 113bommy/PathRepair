#include <bits/stdc++.h>
#pragma target("avx")
using namespace std;
const int INF = 1e9, MOD = 1e9 + 7, ohara = 1e6 + 10;
const long long LINF = 1e18;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
string alph("abcdefghijklmnopqrstuvwxyz"), s, t;
long long n, cnt, ans, a, b, c, d, tmp, m, h, w, x, y, sum, k, q;
int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  cin >> q;
  while (q--) {
    cin >> s >> t;
    for (long long(i) = 0; (i) < (int)((s).size()); (i)++) {
      char kae = 'z';
      tmp = -1;
      for (long long j = (i + 1); j < ((s).size()); j++) {
        if (kae > s[j]) kae = s[j], tmp = j;
      }
      if (tmp == -1) continue;
      if (s[i] > kae) {
        kae = s[tmp];
        s[tmp] = s[i];
        s[i] = kae;
        break;
      }
    }
    int ok = -1, ok2 = 0;
    for (long long(i) = 0; (i) < (int)(min((s).size(), (t).size())); (i)++) {
      if (s[i] < t[i]) {
        ok = 1;
        break;
      } else if (s[i] > t[i]) {
        ok = 0;
        break;
      }
    }
    if (ok == -1) {
      if ((s).size() < (t).size())
        ok = 1;
      else
        ok = 0;
    }
    if (ok)
      cout << (s) << endl;
    else
      cout << ("---") << endl;
  }
  return 0;
}
