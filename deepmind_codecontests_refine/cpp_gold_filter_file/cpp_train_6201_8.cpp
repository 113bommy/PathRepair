#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, long long> mp;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long cx = 0, cy = 0;
  mp[make_pair(0, 0)] = 0;
  long long di = 0, dj = 0;
  while (!(cx == n and cy == m) and !(cx == n and cy == 0) and
         !(cx == 0 and cy == m)) {
    long long d = mp[make_pair(cx, cy)];
    long long diff = 0;
    if (!di and !dj) {
      if (!cx) {
        if (m - cy < n) {
          cx = m - cy;
          diff = m - cy;
          cy = m;
          di = 0;
          dj = 1;
        } else {
          cx = n;
          diff = n;
          cy += n;
          di = 1;
          dj = 0;
        }
      } else if (!cy) {
        if (n - cx < m) {
          cy = n - cx;
          diff = n - cx;
          cx = n;
          di = 1;
          dj = 0;
        } else {
          cy = m;
          cx += m;
          diff = m;
          di = 0;
          dj = 1;
        }
      }
    } else if (di and !dj) {
      if (cx == n) {
        if (m - cy < n) {
          cx -= (m - cy);
          diff = m - cy;
          cy = m;
          di = 1;
          dj = 1;
        } else {
          cx = 0;
          cy += n;
          diff = n;
          di = 0;
          dj = 0;
        }
      } else if (!cy) {
        if (cx < m) {
          cy = cx;
          diff = cx;
          cx = 0;
          di = 0;
          dj = 0;
        } else {
          cy = m;
          cx -= (m);
          diff = m;
          di = 1;
          dj = 1;
        }
      }
    } else if (!di and dj) {
      if (!cx) {
        if (cy < n) {
          cx = cy;
          diff = cy;
          cy = 0;
          di = 0;
          dj = 0;
        } else {
          cx = n;
          cy -= (n);
          diff = n;
          di = 1;
          dj = 1;
        }
      } else if (cy == m) {
        if (n - cx < m) {
          cy -= (n - cx);
          diff = n - cx;
          cx = n;
          di = 1;
          dj = 1;
        } else {
          cy = 0;
          cx += (m);
          diff = m;
          di = 0;
          dj = 0;
        }
      }
    } else {
      if (cx == n) {
        if (cy < n) {
          diff = cy;
          cx -= diff;
          cy = 0;
          di = 1;
          dj = 0;
        } else {
          diff = n;
          cx = 0;
          cy -= (n);
          di = 0;
          dj = 1;
        }
      } else if (cy == m) {
        if (cx < m) {
          diff = cx;
          cy -= diff;
          cx = 0;
          di = 0;
          dj = 1;
        } else {
          diff = m;
          cy = 0;
          cx -= (m);
          di = 1;
          dj = 0;
        }
      }
    }
    mp[make_pair(cx, cy)] = diff + d;
  }
  for (int i = 1; i <= k; i++) {
    long long x, y;
    cin >> x >> y;
    int chx = x & 1, chy = y & 1;
    pair<long long, long long> c1, c2, c3, c4;
    if ((!chx and !chy) or (chx and chy)) {
      long long val = 1e18;
      pair<long long, long long> ct;
      if (m - y < n - x) {
        long long diff = m - y;
        c1 = make_pair(x + diff, m);
      } else {
        long long diff = n - x;
        c1 = make_pair(n, y + diff);
      }
      if (x < y) {
        long long diff = x;
        c2 = make_pair(0, y - diff);
      } else {
        long long diff = y;
        c2 = make_pair(x - diff, 0);
      }
      if (x < m - y) {
        long long diff = x;
        c3 = make_pair(0, y + diff);
      } else {
        long long diff = m - y;
        c3 = make_pair(x - diff, m);
      }
      if (y < n - x) {
        long long diff = y;
        c4 = make_pair(x + diff, 0);
      } else {
        long long diff = n - x;
        c4 = make_pair(n, y - diff);
      }
      if (val > mp[c1]) {
        if (mp[c1] == 0 and (c1.first != 0 or c1.second != 0)) {
        } else {
          val = mp[c1];
          ct = c1;
        }
      }
      if (val > mp[c2]) {
        if (mp[c2] == 0 and (c2.first != 0 or c2.second != 0)) {
        } else {
          val = mp[c2];
          ct = c2;
        }
      }
      if (val > mp[c3]) {
        if (mp[c3] == 0 and (c3.first != 0 or c3.second != 0)) {
        } else {
          val = mp[c3];
          ct = c3;
        }
      }
      if (val > mp[c4]) {
        if (mp[c4] == 0 and (c4.first != 0 or c4.second != 0)) {
        } else {
          val = mp[c4];
          ct = c4;
        }
      }
      if (val == 1e18) {
        cout << "-1\n";
        continue;
      }
      cout << (val + abs(ct.first - x)) << endl;
    } else
      cout << "-1\n";
  }
  return 0;
}
