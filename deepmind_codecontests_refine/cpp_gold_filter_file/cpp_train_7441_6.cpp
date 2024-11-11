#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void umax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void umin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
const int inf = 1e9 + 143;
inline int read() {
  int x;
  scanf(" %d", &x);
  return x;
}
const int N = 1 << 19;
const int M = 1 << 20;
int id[M];
int n, k;
int h[N], s[N];
vector<int> g[N];
vector<int> ds[N];
int min1[N], min2[N];
void dfs(int u, int p, int m1, int m2) {
  if (m1 == 0 || h[u] < h[m1]) {
    m2 = m1;
    m1 = u;
  } else if (m2 == 0 || h[u] < h[m2]) {
    m2 = u;
  }
  min1[u] = m1;
  min2[u] = m2;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u, m1, m2);
    }
  }
}
struct node {
  int op, cl;
  node() {}
  node(int _op, int _cl) : op(_op), cl(_cl) {}
};
node t[N << 1];
void add(int x, int cop, int ccl) {
  x += N;
  t[x].op += cop;
  t[x].cl += ccl;
  while (x > 1) {
    x >>= 1;
    int mc = min(t[x + x].op, t[x + x + 1].cl);
    t[x].op = t[x + x].op + t[x + x + 1].op - mc;
    t[x].cl = t[x + x].cl + t[x + x + 1].cl - mc;
  }
}
bool can(int u, int nh) {
  int sz = ds[u].size();
  for (int d : ds[u]) add(id[min(d, nh)], 0, +1);
  bool res = (t[1].op == 0);
  for (int d : ds[u]) add(id[min(d, nh)], 0, -1);
  return res;
}
int main() {
  n = read();
  vector<int> vs;
  for (int i = 1; i <= n; i++) {
    h[i] = read();
    vs.push_back(h[i]);
  }
  for (int i = 1; i < n; i++) {
    int a = read();
    int b = read();
    g[a].push_back(b);
    g[b].push_back(a);
  }
  k = read();
  for (int i = 0; i < k; i++) {
    s[i] = read();
    vs.push_back(s[i]);
  }
  sort(s, s + k);
  vs.push_back(0);
  sort((vs).begin(), (vs).end());
  vs.erase(unique((vs).begin(), (vs).end()), vs.end());
  for (int i = 1; i <= n; i++)
    h[i] = lower_bound((vs).begin(), (vs).end(), h[i]) - vs.begin();
  for (int i = 0; i < k; i++)
    s[i] = lower_bound((vs).begin(), (vs).end(), s[i]) - vs.begin();
  h[0] = M - 1;
  dfs(1, 0, 0, 0);
  for (int i = 1; i <= n; i++) {
    ds[min1[i]].push_back(h[min2[i]]);
  }
  int ptr = 0;
  for (int x = 0; x < M; x++) {
    while (ptr < k && s[ptr] <= x) ++ptr;
    id[x] = ptr;
  }
  for (int i = 0; i < k; i++) add(i, +1, 0);
  for (int i = 1; i <= n; i++) add(id[h[min1[i]]], 0, +1);
  int cur = t[k + N].cl;
  int to = -1;
  for (int i = k - 1; i >= 0; i--) {
    cur--;
    if (cur < 0) {
      to = s[i];
      break;
    }
    cur += t[i + N].cl;
  }
  if (to == -1) {
    puts("0");
    return 0;
  }
  int ans = inf;
  for (int u = 1; u <= n; u++) {
    add(id[h[u]], 0, -int(ds[u].size()));
    if (can(u, to)) {
      umin(ans, vs[to] - vs[h[u]]);
    }
    add(id[h[u]], 0, +int(ds[u].size()));
  }
  printf("%d\n", (ans == inf) ? -1 : ans);
  return 0;
}
