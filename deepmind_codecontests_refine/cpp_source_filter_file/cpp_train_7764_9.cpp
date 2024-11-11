#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> lev(long long a) {
  int ind = 1;
  while (true) {
    long long cur = a - (1ll << (ind - 1));
    if (cur < 0) break;
    if (cur % (1ll << ind) == 0) {
      return make_pair(ind, (cur / ind) % 2 == 0);
      ;
    }
    ind++;
  }
  return make_pair(1, true);
  ;
}
int main() {
  long long n, q;
  while (cin >> n >> q) {
    for (int j = 0; j < q; ++j) {
      long long t;
      string st;
      cin >> t;
      cin >> st;
      long long mx = (n >> 1) + 1;
      for (int i = 0; i < st.size(); ++i) {
        pair<long long, long long> cur = lev(t);
        long long sc = (1ll << (cur.first - 1));
        if (st[i] == 'U' && t != mx) {
          if (cur.second) {
            t += sc;
          } else {
            t -= sc;
          }
        } else if (st[i] == 'L' && !(t & 1)) {
          t -= (sc >> 1);
        } else if (st[i] == 'R' && !(t & 1)) {
          t += (sc >> 1);
        }
      }
      cout << t << endl;
    }
  }
  return 0;
}
