#include <bits/stdc++.h>
inline int getint() {
  int x = 0, p = 1;
  char c = getchar();
  while (c <= 32) c = getchar();
  if (c == 45) p = -p, c = getchar();
  while (c > 32) x = x * 10 + c - 48, c = getchar();
  return x * p;
}
using namespace std;
const int mod = 1e9 + 7;
inline void reduce(int &x) { x += x >> 31 & mod; }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
const int N = 1e5 + 5;
int n, m, st[N];
long long tim[N], dep[N];
int tag[N], par[N], to[N][2];
vector<pair<int, int>> g[N];
inline int get(int x) { return to[par[x]][1] == x; }
inline bool isroot(int x) {
  int f = par[x];
  return to[f][0] != x && to[f][1] != x;
}
inline void pd(int x) {
  if (tag[x] != -1) {
    tag[to[x][0]] = tim[to[x][0]] = tag[x];
    tag[to[x][1]] = tim[to[x][1]] = tag[x];
    tag[x] = -1;
  }
}
inline void rotate(int x) {
  int f = par[x], ff = par[f], g = get(x), gg = get(f);
  par[x] = ff;
  if (!isroot(f)) to[ff][gg] = x;
  to[f][g] = to[x][g ^ 1];
  if (to[f][g]) par[to[f][g]] = f;
  par[f] = x;
  to[x][g ^ 1] = f;
}
inline void splay(int x) {
  vector<int> st;
  int y = x;
  st.emplace_back(x);
  while (!isroot(y)) {
    y = par[y];
    st.emplace_back(y);
  }
  for (int i = st.size() - 1; i >= 0; i--) pd(st[i]);
  while (!isroot(x)) {
    int f = par[x];
    if (!isroot(f)) rotate(get(x) == get(f) ? f : x);
    rotate(x);
  }
}
void dfs(int x, long long d) {
  dep[x] = d;
  tim[x] = -d;
  for (pair<int, int> u : g[x]) dfs(u.first, d + u.second);
}
int main() {
  n = getint();
  m = getint();
  for (int(i) = 0; (i) < (n - 1); (i)++) {
    int x = getint(), y = getint();
    g[x].emplace_back(y, getint());
    to[x][1] = y;
    par[y] = x;
  }
  dfs(1, 0);
  vector<pair<long long, long long>> v;
  memset(tag, -1, sizeof(tag));
  for (int(i) = 0; (i) < (m); (i)++) {
    int x = getint(), t = getint();
    splay(x);
    int s = x;
    x = par[x];
    for (int y = s; x; y = x, x = par[x]) {
      splay(x);
      to[x][1] = y;
      v.emplace_back(tim[x] + dep[x] + 1, dep[x] + t);
    }
    splay(s);
    if (to[s][0]) tim[to[s][0]] = tag[to[s][0]] = t;
  }
  sort(v.begin(), v.end());
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  long long now = 1;
  int res = 0;
  for (int(i) = 0; (i) < (v.size()); (i)++) {
    pair<long long, long long> u = v[i];
    while (now < u.first && pq.size()) {
      if (pq.top() < now) {
        long long val = pq.top();
        for (int(j) = 0; (j) < (i); (j)++) res -= v[i].second >= val;
        while (pq.size()) {
          res += pq.top() >= val;
          pq.pop();
        }
        return !printf("%lld %d\n", now - 1, res);
      }
      pq.pop();
      ++res;
      ++now;
    }
    now = max(now, u.first);
    pq.emplace(u.second);
  }
  while (!pq.empty()) {
    if (pq.top() < now) {
      long long val = pq.top();
      for (pair<long long, long long> x : v) res -= x.second >= val;
      while (pq.size()) {
        res += pq.top() >= val;
        pq.pop();
      }
      return !printf("%lld %d\n", now - 1, res);
    }
    pq.pop();
    ++now;
    ++res;
  }
  cout << -1 << " " << res << endl;
  return 0;
}
