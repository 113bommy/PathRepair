#include <bits/stdc++.h>
using namespace std;
const long long maxn = 4e5 + 10;
long long n, m, a[maxn], f[maxn], val, size[maxn];
set<pair<long long, long long> > Set[maxn];
multiset<long long> ans;
inline long long find(long long x) { return x == f[x] ? x : find(f[x]); }
inline long long Get(long long x) {
  return (*(--Set[x].end())).first - (*Set[x].begin()).first;
}
inline void Erase(long long x) { ans.erase(ans.find(Get(x))); }
inline void Insert(long long x) { ans.insert(Get(x)); }
inline bool fuck(long long x, long long y) {
  auto it = Set[x].lower_bound(pair<long long, long long>(y, 0));
  return it != Set[x].end() && (*it).first == y;
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = (1), _end_ = (n); i <= _end_; ++i) {
    f[i] = i;
    size[i] = 1;
    Set[i].insert(pair<long long, long long>(0, i));
  }
  for (long long i = (2), _end_ = (n - 1); i <= _end_; ++i) ans.insert(0);
  for (long long i = (1), _end_ = (m); i <= _end_; ++i) {
    long long s, t, v, w;
    scanf("%lld%lld%lld%lld", &s, &t, &v, &w);
    long long x = find(s), y = find(t), W = a[s] - a[t] + v * w;
    ;
    if (x == y) {
      if (a[s] + v * w != a[t]) {
        printf("BAD %lld\n", i);
        return 0;
      }
      continue;
    }
    if (x != find(1) && x != find(n)) Erase(x);
    if (y != find(1) && y != find(n)) Erase(y);
    if (size[x] < size[y]) {
      for (auto it : Set[x]) {
        Set[y].insert(pair<long long, long long>(it.first - W, it.second));
        a[it.second] -= W;
      }
      f[x] = y;
      size[y] += size[x];
    } else {
      for (auto it : Set[y]) {
        Set[x].insert(pair<long long, long long>(it.first + W, it.second));
        a[it.second] += W;
      }
      f[y] = x;
      size[x] += size[y];
    }
    long long pos = find(s);
    if (pos != find(1) && pos != find(n)) Insert(pos);
    if (find(n) == find(1)) val = Get(find(1));
    if (val && ans.lower_bound(val) != ans.end()) {
      printf("BAD %lld\n", i);
      return 0;
    }
    if (pos == find(1) && (--Set[pos].upper_bound(pair<long long, long long>(
                              a[1], n + 1))) != Set[pos].begin()) {
      printf("BAD %lld\n", i);
      return 0;
    }
    if (pos == find(n) && Set[pos].lower_bound(pair<long long, long long>(
                              a[n], 0)) != (--Set[pos].end())) {
      printf("BAD %lld\n", i);
      return 0;
    }
  }
  if (!val)
    puts("UNKNOWN");
  else
    printf("%lld\n", val);
  return 0;
}
