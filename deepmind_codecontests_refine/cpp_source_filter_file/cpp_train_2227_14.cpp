#include <bits/stdc++.h>
using namespace std;
struct timer {
  time_t start;
  timer() { start = clock(); }
  ~timer() {
    cerr << 1. * (clock() - start) / CLOCKS_PER_SEC << " secs" << endl;
  }
};
int n;
pair<int, int> p[100010];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < (n); i++) {
    long long x, y;
    cin >> x >> y;
    p[i] = make_pair(x - y, x + y);
  }
  sort(p, p + n);
  long long lo = -1, hi = 1070000000LL * 2;
  while (lo + 1 < hi) {
    long long mi = lo + hi >> 1;
    multiset<int> S;
    multiset<int>::iterator it;
    int to = n, ok = 0;
    while (to > 0 && p[to - 1].first > p[0].first + mi) {
      S.insert(p[--to].second);
    }
    for (int i = 0; i < (n); i++) {
      while (to < n && p[to].first <= p[i + 1].first + mi) {
        it = S.find(p[to].second);
        S.erase(it);
        to++;
      }
      if (S.empty() || *S.rbegin() <= *S.begin() + mi) {
        ok = 1;
        break;
      }
      if (to == n) break;
      S.insert(p[i].second);
    }
    if (ok)
      hi = mi;
    else
      lo = mi;
  }
  cout << setprecision(16) << hi / 2.;
}
