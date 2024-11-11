#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int tp, tu, td;
int a[333][333], su[333][333], sd[333][333], sl[333][333], sr[333][333];
inline int get(int a, int b) { return a == b ? tp : a < b ? tu : td; }
inline int get(int x1, int y1, int x2, int y2) {
  return sl[x1][y2] - sl[x1][y1] + sr[x2][y1] - sr[x2][y2] + sd[x2][y2] -
         sd[x1][y2] + su[x1][y1] - su[x2][y1];
}
int main() {
  scanf("%d %d %d", &n, &m, &t);
  scanf("%d %d %d", &tp, &tu, &td);
  for (int i = (1), _b = (n); i <= _b; i++)
    for (int j = (1), _b = (m); j <= _b; j++) scanf("%d", &a[i][j]);
  memset(su, 0, sizeof(su));
  memset(sd, 0, sizeof(sd));
  memset(sl, 0, sizeof(sl));
  memset(sr, 0, sizeof(sr));
  for (int i = (2), _b = (n); i <= _b; i++)
    for (int j = (1), _b = (m); j <= _b; j++)
      sd[i][j] = sd[i - 1][j] + get(a[i - 1][j], a[i][j]);
  for (int i = (n - 1), _b = (1); i >= _b; i--)
    for (int j = (1), _b = (m); j <= _b; j++)
      su[i][j] = su[i + 1][j] + get(a[i + 1][j], a[i][j]);
  for (int i = (1), _b = (n); i <= _b; i++)
    for (int j = (2), _b = (m); j <= _b; j++)
      sl[i][j] = sl[i][j - 1] + get(a[i][j - 1], a[i][j]);
  for (int i = (1), _b = (n); i <= _b; i++)
    for (int j = (m - 1), _b = (1); j >= _b; j--)
      sr[i][j] = sr[i][j + 1] + get(a[i][j + 1], a[i][j]);
  int bx1, bx2, by1, by2, bestDiff = 1000111222;
  for (int r1 = (1), _b = (n); r1 <= _b; r1++)
    for (int r2 = (r1 + 2), _b = (n); r2 <= _b; r2++) {
      set<pair<int, int> > recs;
      set<pair<int, int> >::iterator it;
      for (int j = (3), _b = (m); j <= _b; j++)
        recs.insert(make_pair(get(r1, 1, r2, j), j));
      for (int j = (1), _b = (m - 2); j <= _b; j++) {
        recs.erase(make_pair(get(r1, 1, r2, j + 1), j + 1));
        int k = sl[r1][j] + sr[r2][1] - sr[r2][j] + su[r1][1] - su[r2][1] -
                (su[r1][j] - su[r2][j]);
        int ex = t + k;
        it = recs.lower_bound(make_pair(ex, -1));
        if (it != recs.end()) {
          int val = it->first - k;
          int diff = abs(t - val);
          if (diff < bestDiff) {
            bestDiff = diff;
            bx1 = r1, bx2 = r2, by1 = j, by2 = it->second;
          }
        }
        it = recs.upper_bound(make_pair(ex, 10000));
        if (it != recs.begin()) it--;
        int val = it->first - k;
        int diff = abs(t - val);
        if (diff < bestDiff) {
          bestDiff = diff;
          bx1 = r1, bx2 = r2, by1 = j, by2 = it->second;
        }
      }
    }
  printf("%d %d %d %d\n", bx1, by1, bx2, by2);
  return 0;
}
