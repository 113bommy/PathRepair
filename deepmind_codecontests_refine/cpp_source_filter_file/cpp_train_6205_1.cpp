#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, Q;
map<pair<int, int>, int> m;
int Read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x * 10) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
void Put1(int x) {
  if (x > 9) Put1(x / 10);
  putchar(x % 10 ^ 48);
}
void Put(int x, char c = -1) {
  if (x < 0) putchar('-'), x = -x;
  Put1(x);
  if (c >= 0) putchar(c);
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T Abs(T x) {
  return x < 0 ? -x : x;
}
vector<pair<int, int> > t[MAXN << 2];
void update(int x, int l, int r, int ql, int qr, pair<int, int> p) {
  if (ql > r || qr < l) return;
  if (ql <= l && r <= qr) {
    t[x].push_back(p);
    return;
  }
  int mid = (l + r) >> 1;
  update(x << 1, l, mid, ql, qr, p);
  update(x << 1 | 1, mid + 1, r, ql, qr, p);
}
int f[MAXN], d[MAXN], s[MAXN], c[MAXN], stot;
int findSet(int x) {
  if (x == f[x]) return x;
  return findSet(f[x]);
}
void unionSet(int u, int v, bool FLAG) {
  int x = findSet(u), y = findSet(v);
  if (d[x] < d[y]) swap(x, y);
  if (d[x] == d[y]) ++d[x], s[++stot] = -x;
  f[y] = x;
  s[++stot] = y;
  c[y] = FLAG;
}
void Restore(int recover) {
  int u;
  while (stot > recover) {
    u = s[stot];
    --stot;
    if (u > 0)
      f[u] = u, c[u] = 0;
    else
      --d[-u];
  }
}
int dis(int x) {
  if (x == f[x]) return 0;
  return (dis(f[x]) ^ c[x]);
}
void dfs(int x, int l, int r) {
  int recover = stot, len = t[x].size();
  for (int i = 0; i < len; ++i) {
    int u = t[x][i].first, v = t[x][i].second;
    bool ji = (dis(u) ^ dis(v) ^ 1);
    if (findSet(u) == findSet(v)) {
      if (ji) {
        for (int j = l; j <= r; ++j) printf("NO\n");
        Restore(recover);
        return;
      }
    } else
      unionSet(u, v, ji);
  }
  if (l == r) {
    printf("YES\n");
    Restore(recover);
    return;
  }
  int mid = (l + r) >> 1;
  dfs(x << 1, l, mid);
  dfs(x << 1 | 1, mid + 1, r);
  Restore(recover);
}
int main() {
  n = Read();
  Q = Read();
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (int i = 1, u, v; i <= Q; ++i) {
    u = Read();
    v = Read();
    pair<int, int> p = make_pair(u, v);
    if (m.count(p))
      update(1, 1, Q, m[p], i - 1, p), m[p] = 0;
    else
      m[p] = i;
  }
  map<pair<int, int>, int>::iterator it;
  for (it = m.begin(); it != m.end(); ++it)
    update(1, 1, Q, (*it).second, Q, (*it).first);
  dfs(1, 1, Q);
  return 0;
}
