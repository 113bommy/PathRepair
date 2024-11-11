#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? x : -x;
}
const long long N = 1e5 + 5;
long long n, m, p, q, cnt, fa[N], siz[N];
long long find(long long x) { return x == fa[x] ? x : find(fa[x]); }
void merge(long long x, long long y, long long l) {
  x = find(x), y = find(y);
  if (x == y)
    siz[x] += l;
  else {
    fa[y] = x;
    cnt--;
    siz[x] += siz[y] + l;
  }
}
long long id1, id2;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
               greater<pair<long long, long long>>>
    que;
signed main() {
  n = cnt = read(), m = read(), p = read(), q = read();
  for (long long i = 1; i <= n; i++) fa[i] = i;
  for (long long i = 1; i <= m; i++) {
    long long x = read(), y = read(), l = read();
    merge(x, y, l);
  }
  if (cnt < q || cnt - p > q || (cnt == n && p && !m)) return puts("NO") * 0;
  puts("YES");
  for (long long i = 1; i <= n; i++)
    if (fa[i] == i) que.push({siz[i], i});
  while (cnt > q) {
    pair<long long, long long> x = que.top();
    que.pop();
    pair<long long, long long> y = que.top();
    que.pop();
    long long val1 = x.first, val2 = y.first;
    id1 = x.second;
    id2 = y.second;
    merge(id1, id2, val1 + val2 + 1);
    p--;
    printf("%lld %lld\n", id1, id2);
    que.push({siz[id1], id1});
  }
  for (long long i = 1; i <= n; i++) {
    if (i != find(i)) {
      id1 = i;
      id2 = find(i);
      break;
    }
  }
  if (p)
    while (p--) printf("%lld %lld\n", id1, id2);
  return 0;
}
