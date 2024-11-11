#include <bits/stdc++.h>
using namespace std;
int n, j, i, k, l[15], r[15];
int cur, e, q, t, x, y, ans, J, X, Y;
string s, p[15];
vector<pair<int, int> > v;
int main() {
  cin >> s;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> p[i] >> l[i] >> r[i];
  for (i = 0; i < s.size(); i++)
    for (j = 0; j < s.size(); j++) {
      t = 1;
      for (q = 1; q <= n; q++) {
        cur = 0;
        for (k = 0; k <= (int)p[q].size() - j + i - 1; k++) {
          J = 1;
          for (e = 0; e < j - i + 1; e++)
            if (s[i + e] != p[q][k + e]) {
              J = 0;
              break;
            }
          if (J) cur++;
        }
        if (!(cur >= l[q] && cur <= r[q])) {
          t = 0;
          break;
        }
      }
      if (t) v.push_back(make_pair(i, j));
    }
  for (i = 0; i < v.size(); i++) {
    t = 1;
    x = v[i].first;
    y = v[i].second;
    for (j = 0; j < i; j++) {
      X = v[j].first;
      Y = v[j].second;
      if (Y - X != y - x) continue;
      e = 1;
      for (k = 0; k < Y - X + 1; k++)
        if (s[x + k] != s[X + k]) {
          e = 0;
          break;
        }
      if (e == 1) {
        t = 0;
        break;
      }
    }
    if (t) ans++;
  }
  cout << ans << endl;
}
