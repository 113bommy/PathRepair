#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
const int mod = 1e9 + 7;
int n, m, i, j, sz[100005], mx[100005], rt, vis[100005], ans = 1;
vector<pair<int, pair<int, int> > > e[100005];
int pw(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) z = 1ll * z * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return z;
}
struct bit {
  int a[400005];
  int b[400005];
  void init() {
    int i;
    for (((i)) = (1); ((i)) <= ((n * 4)); ((i))++) {
      a[i] = 0;
      b[i] = 1;
    }
  }
  void add(int x, int da, int db) {
    x += n * 2;
    while (x <= n * 4) {
      a[x] += da;
      b[x] = 1ll * b[x] * db % mod;
      x += (x & -x);
    }
  }
  void qry(int x, int &sa, int &sb) {
    x += n * 2;
    sa = 0;
    sb = 1;
    while (x) {
      sa += a[x];
      sb = 1ll * sb * b[x] % mod;
      x -= (x & -x);
    }
  }
} t1, t2;
void dfs_sz(int x, int fa) {
  sz[x] = 1;
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++) {
    if (it->first == fa || vis[it->first]) continue;
    dfs_sz(it->first, x);
    sz[x] += sz[it->first];
  }
}
void dfs_rt(int x, int fa, int all) {
  mx[x] = all - sz[x];
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++) {
    if (it->first == fa || vis[it->first]) continue;
    dfs_rt(it->first, x, all);
    mx[x] = max(mx[x], sz[it->first]);
  }
  if (rt == -1 || mx[x] < mx[rt]) rt = x;
}
vector<pair<pair<int, int>, int> > v1, v2;
void dfs_in(int x, int fa, int c0, int c1, int v) {
  v2.push_back(make_pair(make_pair(2 * c0 - c1, 2 * c1 - c0), v));
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (it->first != fa && !vis[it->first]) {
      dfs_in(it->first, x, c0 + (it->second.second == 0),
             c1 + (it->second.second == 1), 1ll * v * it->second.first);
    }
}
void calc(int x) {
  v1.clear();
  int a = 0, b = 0, w = 1;
  v1.push_back(make_pair(make_pair(a, b), w));
  t1.add(-a, 1, w);
  t2.add(b, 1, w);
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (!vis[it->first]) {
      v2.clear();
      dfs_in(it->first, x, it->second.second == 0, it->second.second == 1,
             it->second.first);
      for (__typeof((v2).begin()) it = (v2).begin(); it != (v2).end(); it++) {
        int s1, s2, a = it->first.first, b = it->first.second, w = it->second;
        t1.qry(a, s1, s2);
        ans = 1ll * ans * s2 % mod * pw(w, s1) % mod;
        t2.qry(-b - 1, s1, s2);
        ans = 1ll * ans * pw(1ll * s2 * pw(w, s1) % mod, mod - 2) % mod;
      }
      for (__typeof((v2).begin()) it = (v2).begin(); it != (v2).end(); it++) {
        int a = it->first.first, b = it->first.second, w = it->second;
        v1.push_back(*it);
        t1.add(-a, 1, w);
        t2.add(b, 1, w);
      }
    }
  for (__typeof((v1).begin()) it = (v1).begin(); it != (v1).end(); it++) {
    int a = it->first.first, b = it->first.second, w = it->second;
    w = pw(w, mod - 2);
    t1.add(-a, -1, w);
    t2.add(b, -1, w);
  }
}
void dfs(int x) {
  rt = -1;
  dfs_sz(x, 0);
  dfs_rt(x, 0, sz[x]);
  x = rt;
  vis[x] = 1;
  calc(x);
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (!vis[it->first]) {
      dfs(it->first);
    }
}
int main() {
  read(n);
  t1.init();
  t2.init();
  for (((i)) = (1); ((i)) <= ((n - 1)); ((i))++) {
    int x, y, z, c;
    read(x);
    read(y);
    read(z);
    read(c);
    e[x].push_back(make_pair(y, make_pair(z, c)));
    e[y].push_back(make_pair(x, make_pair(z, c)));
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}
