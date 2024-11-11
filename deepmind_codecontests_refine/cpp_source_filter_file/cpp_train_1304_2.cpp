#include <bits/stdc++.h>
using namespace std;
set<pair<long long, long long> > st;
const long long INF = 1 << 30;
const long long N = 100005;
long long p[N], n, m;
long long nxt[N], pre[N];
long long a[N], x[N];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
bool cmp(long long x, long long y) { return p[x] < p[y]; }
long long calc(long long x, long long y) {
  if (x == y) return INF;
  long long d = (p[y] - p[x] + m) % m;
  if (x > y) d = (d + a[x]) % m;
  if (d <= a[x]) return 1;
  if (a[x] <= a[y]) return INF;
  long long dis = a[x] - a[y];
  return (d - a[y] - 1) / dis + 1;
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) {
    p[i] = read();
    a[i] = read();
    x[i] = i;
  }
  sort(x + 1, x + n + 1, cmp);
  for (long long i = 1; i <= n; i++) {
    if (i < n)
      nxt[x[i]] = x[i + 1];
    else
      nxt[x[i]] = x[1];
    pre[nxt[x[i]]] = x[i];
  }
  for (long long i = 1; i <= n; i++) {
    st.insert(make_pair(calc(i, nxt[i]), i));
  }
  while (!st.empty()) {
    set<pair<long long, long long> >::iterator it = st.begin();
    if ((*it).first == INF) break;
    long long i = (*it).second;
    st.erase(it);
    st.erase(make_pair(calc(nxt[i], nxt[nxt[i]]), nxt[i]));
    st.erase(make_pair(calc(pre[i], i), pre[i]));
    p[i] += calc(i, nxt[i]);
    --a[i];
    nxt[i] = nxt[nxt[i]];
    pre[nxt[i]] = i;
    st.insert(make_pair(calc(pre[i], i), pre[i]));
    st.insert(make_pair(calc(i, nxt[i]), i));
  }
  printf("%d\n", st.size());
  for (set<pair<long long, long long> >::iterator it = st.begin();
       it != st.end(); it++)
    printf("%lld ", (*it).second);
}
