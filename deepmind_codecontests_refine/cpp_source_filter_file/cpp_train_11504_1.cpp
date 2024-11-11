#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, Mod = 1e9 + 7, MAXN = 3e5 + 10, LG = 20, M = 1e9,
          P = 727, Sq = 445;
const long long inf = 3e18 + 10;
set<int> s;
set<int>::iterator it, io;
int n, q, p[N];
int Find(int x) {
  if (!p[x]) return x;
  return p[x] = Find(p[x]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) s.insert(i);
  for (int i = 1; i <= q; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1 && Find(y) != Find(x)) p[Find(y)] = Find(x);
    if (t == 2) {
      it = s.lower_bound(Find(x));
      while (it != s.end() && (*it) <= y) {
        if (Find((*it)) != Find(x)) p[Find((*it))] = Find(x);
        io = it++;
        s.erase(io);
      }
      s.insert(x);
    }
    if (t == 3) {
      if (Find(x) == Find(y))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
