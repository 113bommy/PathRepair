#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 100;
long long n, m, q, ans[N], h[N][110];
unordered_map<long long, long long> mp[N];
struct node {
  long long u, v, w;
} b[10];
bool operator==(node a, node b) {
  return a.u == b.u && a.v == b.v && a.w == b.w;
}
bool operator<(node a, node b) {
  if (a.w != b.w) return a.w < b.w;
  return a.u < b.u || (a.u == b.u && a.v < b.v);
}
multiset<node> s[N];
multiset<long long> all;
struct Set {
  priority_queue<long long, vector<long long>, greater<long long> > a, b;
  inline void push(long long x) { a.push(x); }
  inline void rem(long long x) { b.push(x); }
  inline long long top() {
    while (!b.empty() && a.top() == b.top()) a.pop(), b.pop();
    if (a.empty()) return 0x3f3f3f3f3f3f3f3f;
    return a.top();
  }
} T[110][2];
inline bool check(node a, node b) {
  return (a.u == b.u || a.u == b.v || a.v == b.u || a.v == b.v);
}
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
inline long long sum(multiset<node> &s) {
  if ((long long)s.size() < 3) return 0x3f3f3f3f3f3f3f3f;
  auto it = s.begin();
  long long ans = 0;
  ans += (*it).w;
  it++;
  ans += (*it).w;
  it++;
  ans += (*it).w;
  return ans;
}
inline void add_edge(long long u, long long v, long long w, long long t) {
  if (u > v) swap(u, v);
  mp[u][v] = w;
  node x = (node){u, v, w};
  all.erase(all.lower_bound(sum(s[u])));
  all.erase(all.lower_bound(sum(s[v])));
  s[u].insert(x);
  s[v].insert(x);
  all.insert(sum(s[u]));
  all.insert(sum(s[v]));
  long long *U = &h[u][0], *V = &h[v][0];
  for (long long i = 0; i < 110; i++, (*U++), (*V++))
    if (*U == *V) T[i][*U].push(w);
}
inline void del_edge(long long u, long long v, long long t) {
  if (u > v) swap(u, v);
  long long w = mp[u][v];
  node x = (node){u, v, w};
  all.erase(all.lower_bound(sum(s[u])));
  all.erase(all.lower_bound(sum(s[v])));
  s[u].erase(s[u].lower_bound(x));
  s[v].erase(s[v].lower_bound(x));
  all.insert(sum(s[u]));
  all.insert(sum(s[v]));
  long long *U = &h[u][0], *V = &h[v][0];
  for (long long i = 0; i < 110; i++, (*U++), (*V++))
    if (*U == *V) T[i][*U].rem(w);
}
inline long long getans() {
  long long ans = *all.begin();
  for (long long i = 0; i < 110; i++) {
    long long now = T[i][0].top() + T[i][1].top();
    ans = min(ans, now);
  }
  return ans;
}
signed main() {
  srand(time(0));
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) all.insert(sum(s[i]));
  for (long long j = 0; j < 110; j++)
    for (long long i = 1; i <= n; i++) h[i][j] = (rand() & 1);
  for (long long i = 1; i <= n; i++) random_shuffle(h[i], h[i] + 110);
  for (long long i = 1; i <= m; i++) {
    long long u = read(), v = read(), w = read();
    add_edge(u, v, w, 0);
  }
  printf("%lld\n", getans());
  q = read();
  for (long long i = 1; i <= q; i++) {
    long long op = read();
    if (op == 1) {
      long long u = read(), v = read(), w = read();
      add_edge(u, v, w, i);
    } else {
      long long u = read(), v = read();
      del_edge(u, v, i);
    }
    printf("%lld\n", getans());
  }
  return 0;
}
