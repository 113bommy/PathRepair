#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const long long oo = 1 << 30;
const long long loo = 1ll << 62;
const long long mods = 1e9 + 7;
const long long MAXN = 1000005;
const long long INF = 0x3f3f3f3f;
inline long long read() {
  long long f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
struct snode {
  long long id, x, lt;
  snode(long long _id, long long _x, long long _lt) {
    id = _id, x = _x, lt = _lt;
  }
};
set<snode> Set;
struct wnode {
  long long id, x, lt;
};
set<wnode> wque;
bool operator<(snode x, snode y) {
  return (x.x < y.x) || (x.x == y.x && x.lt < y.lt) ||
         (x.x == y.x && x.lt == y.lt && x.id < y.id);
}
bool operator<(wnode x, wnode y) {
  return (x.lt < y.lt) || (x.lt == y.lt && x.id < y.id);
}
signed main() {
  long long n = read(), k = read(), m = read();
  for (long long i = 1; i <= k; i++) Set.insert((snode){i, read(), 0});
  for (long long i = 1, T = 0; i <= m; i++) {
    long long t = read(), x = read(), y = read();
    auto add = [&](long long T) {
      while (wque.size() && wque.begin()->lt <= T) {
        auto it = wque.begin();
        Set.insert((snode){it->id, it->x, it->lt});
        wque.erase(it);
      }
    };
    upmax(T, t), add(T);
    if (!Set.size()) T = wque.begin()->lt, add(T);
    snode l(INF, INF, INF), r(INF, INF, INF);
    auto it = Set.lower_bound((snode){0, x, 0}), it2 = it;
    if (it != Set.end()) r = (snode){it->id, it->x - x, it->lt};
    if (it != Set.begin())
      it2--, it2 = Set.lower_bound((snode){0, it2->x, 0}),
             l = (snode){it2->id, x - it2->x, it2->lt};
    if (l < r)
      wque.insert((wnode){l.id, y, T + l.x + abs(y - x)}),
          printf("%d %d\n", l.id, T - t + l.x), Set.erase(it2);
    else
      wque.insert((wnode){r.id, y, T + r.x + abs(y - x)}),
          printf("%d %d\n", r.id, T - t + r.x), Set.erase(it);
  }
  return 0;
}
