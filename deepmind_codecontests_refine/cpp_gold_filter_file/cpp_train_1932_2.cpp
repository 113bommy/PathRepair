#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
template <class T>
class Cmp {
 public:
  bool operator()(const T& lhs, const T& rhs) { return lhs > rhs; }
};
set<int> unread[300010];
int event[300010];
int main() {
  int n, q, type, x, res = 0, pos = 1, add = 1;
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> type >> x;
    if (type == 1) {
      unread[x].insert(add);
      event[add++] = x;
      res++;
    } else if (type == 2) {
      res -= unread[x].size();
      unread[x].clear();
    } else {
      for (; pos <= x; pos++) {
        if (unread[event[pos]].count(pos) == 1) {
          unread[event[pos]].erase(pos);
          res--;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
