#include <bits/stdc++.h>
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
using namespace std;
int n, m, K, f[N];
vector<pair<int, int> > add[N], del[N];
vector<int> vec;
set<pair<int, int> > s;
set<int> pot;
template <typename T>
inline T read() {
  T x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * w;
}
int upd(int x) { return x + (x >> 31 & mod); }
struct BIT {
  int t[N];
  void add(int x, int y) {
    for (int i = x; i <= m; i += (i & (-i))) t[i] = upd(t[i] + y - mod);
  }
  int query(int x) {
    int res = 0;
    for (int i = x; i; i -= (i & (-i))) res = upd(res + t[i] - mod);
    return res;
  }
} T;
int main() {
  n = read<int>(), m = read<int>(), K = read<int>();
  for (int xl, xr, yl, yr, i = 1; i <= K; i++) {
    xl = read<int>(), yl = read<int>(), xr = read<int>(), yr = read<int>();
    add[xl].push_back(make_pair(yl, yr)),
        del[xr + 1].push_back(make_pair(yl, yr));
  }
  add[++n].push_back(make_pair(1, m - 1)), T.add(1, 1), f[1] = 1;
  pot.insert(1), s.insert(make_pair(m + 1, m + 1)), s.insert(make_pair(0, 0));
  for (int i = 1; i <= n; i++)
    if (add[i].size() || del[i].size()) {
      sort(add[i].begin(), add[i].end(),
           [](pair<int, int> x, pair<int, int> y) {
             return x.second > y.second;
           });
      if (i > 1)
        for (auto tmp : add[i]) {
          int l = tmp.first, r = tmp.second, x;
          auto it = s.lower_bound(make_pair(r + 1, r + 1)),
               it1 = prev(s.upper_bound(make_pair(r, m + 1)));
          x = T.query(r) - T.query(min(it1->second, r));
          if (it->first > r + 1)
            f[r + 1] = upd(f[r + 1] + x - mod), T.add(r + 1, x),
                  pot.insert(r + 1);
        }
      for (auto tmp : del[i]) s.erase(tmp);
      for (auto tmp : add[i]) {
        int l = tmp.first, r = tmp.second;
        auto it = pot.lower_bound(l);
        vec.clear();
        while (it != pot.end() && *it <= r)
          T.add(*it, upd(-f[*it])), vec.push_back(*it), it++;
        for (auto x : vec) pot.erase(x), f[x] = 0;
      }
      for (auto tmp : add[i]) s.insert(tmp);
    }
  printf("%d\n", T.query(m));
  return 0;
}
