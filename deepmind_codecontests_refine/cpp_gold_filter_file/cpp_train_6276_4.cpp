#include <bits/stdc++.h>
using namespace std;
vector<int> l;
bool Dist(int ax, int ay, int bx, int by, int cal) {
  float d;
  ax -= bx;
  ay -= by;
  ax *= ax;
  ay *= ay;
  ax += ay;
  d = sqrt(ax);
  if (d > cal) {
    return false;
  } else {
    return true;
  }
}
int main() {
  int ax, ay, bx, by, n, sol = 0;
  vector<pair<int, int> > st;
  cin >> ax;
  cin >> ay;
  cin >> bx;
  cin >> by;
  cin >> n;
  for (int i = 0, t1, t2, t3; i < n; i++) {
    cin >> t1;
    cin >> t2;
    st.push_back(make_pair(t1, t2));
    cin >> t3;
    l.push_back(t3);
  }
  if (ax > bx) {
    int c;
    c = ax;
    ax = bx;
    bx = c;
  }
  if (ay > by) {
    int c;
    c = ay;
    ay = by;
    by = c;
  }
  for (int i = ax, j; i <= bx; i++) {
    if ((i == ax) || (i == bx)) {
      for (j = ay; j <= by; j++) {
        for (int k = 0; k < n; k++) {
          if (Dist(i, j, st[k].first, st[k].second, l[k])) {
            goto esc2;
          }
        }
        sol++;
      esc2:;
      }
    } else {
      j = ay;
      for (int k = 0; k < n; k++) {
        if (Dist(i, j, st[k].first, st[k].second, l[k])) {
          goto esc;
        }
      }
      sol++;
    esc:;
      j = by;
      for (int k = 0; k < n; k++) {
        if (Dist(i, j, st[k].first, st[k].second, l[k])) {
          goto esc1;
        }
      }
      sol++;
    esc1:;
    }
  }
  cout << sol;
  return 0;
}
