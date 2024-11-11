#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f, NMAX = 200010;
int N, Q;
int X[NMAX], Y[NMAX];
int main() {
  ios_base::sync_with_stdio(false);
  int i, x, y;
  char dir;
  set<pair<int, int>> Events;
  set<pair<int, int>>::iterator where;
  Events.insert(make_pair(-oo, -oo));
  Events.insert(make_pair(oo, oo));
  cin >> N >> Q;
  for (i = 1; i <= Q; ++i) {
    cin >> x >> y >> dir;
    where = Events.lower_bound(make_pair(x, 0));
    if (where->first == x) {
      cout << "0\n";
      continue;
    }
    if (dir == 'U') {
      if (where->first == oo) {
        cout << y << '\n';
        X[i] = x;
        Y[i] = 0;
      } else {
        cout << y - Y[where->second] << '\n';
        X[i] = x;
        Y[i] = Y[where->second];
      }
    } else {
      --where;
      if (where->first == -oo) {
        cout << x << '\n';
        X[i] = 0;
        Y[i] = y;
      } else {
        cout << x - X[where->second] << '\n';
        X[i] = X[where->second];
        Y[i] = y;
      }
    }
    Events.insert(make_pair(x, i));
  }
  return 0;
}
