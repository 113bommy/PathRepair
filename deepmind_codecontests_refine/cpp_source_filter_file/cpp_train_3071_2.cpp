#include <bits/stdc++.h>
using namespace std;
const long long maxn = 500000 + 5;
long long findset(long long x, long long* fa) {
  return x == fa[x] ? x : findset(fa[x], fa);
}
long long univfa[maxn], univsize[maxn], univeff[maxn];
vector<int> add[maxn], pre[maxn];
long long milifa[maxn], milisize[maxn], milieff[maxn], tag[maxn];
inline void merge(long long x, long long y, long long* fa, long long* size,
                  long long* eff, long long rep) {
  long long u = findset(x, fa), v = findset(y, fa);
  if (size[u] < size[v]) swap(u, v);
  fa[v] = u;
  size[u] += size[v];
  eff[v] = rep;
}
inline void inc(long long x, long long* size, long long T) {
  x = findset(x, univfa);
  add[x].push_back(T);
  if (pre[x].size() == 0)
    pre[x].push_back(size[x]);
  else
    pre[x].push_back(pre[x][pre[x].size() - 1] + size[x]);
}
inline void raid(long long x, long long T) {
  x = findset(x, milifa);
  tag[x] = T;
}
long long getlastclear(long long x, long long* fa, long long* eff,
                       long long T) {
  if (x == fa[x]) return tag[x] > T ? tag[x] : 0;
  return max(tag[x] > T ? tag[x] : 0,
             getlastclear(fa[x], fa, eff, max(T, eff[x])));
}
long long cal(long long x, long long* fa, long long* size, long long* eff,
              long long T) {
  long long val;
  if (add[x].size() == 0 || add[x][add[x].size() - 1] <= T)
    val = 0;
  else {
    long long p = lower_bound(add[x].begin(), add[x].end(), T) - add[x].begin();
    val = pre[x][pre[x].size() - 1] - (p > 0 ? pre[x][p - 1] : 0);
  }
  if (x == fa[x]) return val;
  return val + cal(fa[x], fa, size, eff, max(T, eff[x]));
}
inline long long query(long long x) {
  long long T = getlastclear(x, milifa, milieff, 0);
  return cal(x, univfa, univsize, univeff, T);
}
int main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++)
    univsize[i] = milisize[i] = 1, univfa[i] = milifa[i] = i, tag[i] = 0,
    add[i].clear();
  for (long long rep = 1; rep <= m; rep++) {
    char op[3];
    long long x, y;
    scanf("%s", op);
    switch (op[0]) {
      case 'U':
        scanf("%lld%lld", &x, &y);
        merge(x, y, univfa, univsize, univeff, rep);
        break;
      case 'M':
        scanf("%lld%lld", &x, &y);
        merge(x, y, milifa, milisize, milieff, rep);
        break;
      case 'A':
        scanf("%lld", &x);
        inc(x, univsize, rep);
        break;
      case 'Z':
        scanf("%lld", &y);
        raid(y, rep);
        break;
      case 'Q':
        scanf("%lld", &x);
        printf("%lld\n", query(x));
        break;
    }
  }
}
