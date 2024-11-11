#include <bits/stdc++.h>
long long gi() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
std::mt19937 rnd(time(NULL));
template <class T>
void cxk(T& a, T b) {
  a = a > b ? a : b;
}
template <class T>
void cnk(T& a, T b) {
  a = a < b ? a : b;
}
int pow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % 1000000007;
    x = 1ll * x * x % 1000000007;
    y >>= 1;
  }
  return ret;
}
template <class Ta, class Tb>
void inc(Ta& a, Tb b) {
  a = a + b >= 1000000007 ? a + b - 1000000007 : a + b;
}
template <class Ta, class Tb>
void dec(Ta& a, Tb b) {
  a = a >= b ? a - b : a + 1000000007 - b;
}
struct block {
  int x1, y1, x2, y2;
} blo[100010];
struct Key {
  int x, y, i;
} key[100010];
int n, m;
int f[100010], up[100010], le[100010], st[100010];
int t[1000010];
void update(int x, int d) {
  while (x) inc(t[x], d), x -= x & -x;
}
int query(int x) {
  int r = 0;
  while (x <= 1000000) inc(r, t[x]), x += x & -x;
  return r;
}
std::vector<Key> v1[262147], v2[262147];
void prepare(int x, int l, int r) {
  if (l == r) {
    v1[x] = {key[l]}, v2[x] = {{key[l].x, up[l], l}};
    return;
  }
  prepare(x << 1, l, ((l + r) >> 1)),
      prepare(x << 1 | 1, ((l + r) >> 1) + 1, r);
  v1[x].resize(r - l + 1), v2[x].resize(r - l + 1);
  std::merge((v1[x << 1]).begin(), (v1[x << 1]).end(), (v1[x << 1 | 1]).begin(),
             (v1[x << 1 | 1]).end(), v1[x].begin(),
             [](Key a, Key b) { return a.y < b.y; });
  std::merge((v2[x << 1]).begin(), (v2[x << 1]).end(), (v2[x << 1 | 1]).begin(),
             (v2[x << 1 | 1]).end(), v2[x].begin(),
             [](Key a, Key b) { return a.y < b.y; });
}
void divide(int x, int l, int r) {
  if (l == r) return;
  divide(x << 1, l, ((l + r) >> 1));
  int i = 0, p = 0, j = 0;
  std::vector<Key>&A = v1[x << 1], &B = v1[x << 1 | 1], &C = v2[x << 1];
  while (i < A.size() || j < B.size()) {
    int min =
        std::min({i < A.size() ? A[i].y : 1e9, j < B.size() ? B[j].y : 1e9,
                  p < C.size() ? C[p].y : 1e9});
    if (C[p].y == min)
      update(C[p].x, 1000000007 - f[C[p].i]), ++p;
    else if (B[j].y == min)
      inc(f[B[j].i], query(le[B[j].i] + 1)), ++j;
    else
      update(A[i].x, f[A[i].i]), ++i;
  }
  while (p < C.size()) update(C[p].x, 1000000007 - f[C[p].i]), ++p;
  divide(x << 1 | 1, ((l + r) >> 1) + 1, r);
}
std::set<std::pair<int, int> > set;
int main() {
  int H = gi(), W = gi(), n = gi(), m = n + 2;
  for (int i = 1; i <= n; ++i)
    blo[i].x1 = gi(), blo[i].y1 = gi(), blo[i].x2 = gi(), blo[i].y2 = gi(),
    key[i] = {blo[i].x2 + 1, blo[i].y1 - 1};
  key[n + 1] = {1, 0}, key[n + 2] = {H, W};
  std::sort(key + 1, key + m + 1,
            [](Key a, Key b) { return a.x == b.x ? a.y > b.y : a.x < b.x; });
  for (int i = 1; i <= m; ++i) key[i].i = i;
  for (int i = 1; i <= m; ++i)
    if (key[i].x == 1 && key[i].y == 0) f[i] = 1;
  for (int i = 1; i <= m; ++i) st[i] = i;
  {
    std::sort(blo + 1, blo + n + 1,
              [](block a, block b) { return a.x1 > b.x1; });
    std::sort(st + 1, st + m + 1,
              [&](int a, int b) { return key[a].x > key[b].x; });
    set.clear();
    int i = 1, j = 1;
    while (i <= m || j <= n) {
      if (i <= m && (j > n || key[st[i]].x > blo[j].x1))
        set.insert({key[st[i]].y, st[i]}), ++i;
      else {
        while (1) {
          auto it = set.lower_bound({blo[j].y1, -1});
          if (it == set.end() || it->first > blo[j].y2) break;
          le[it->second] = blo[j].x2;
          set.erase(it);
        }
        ++j;
      }
    }
  }
  {
    set.clear();
    for (int i = 1; i <= m; ++i) up[i] = 1e9;
    std::sort(blo + 1, blo + n + 1,
              [](block a, block b) { return a.y1 < b.y1; });
    std::sort(st + 1, st + m + 1,
              [&](int a, int b) { return key[a].y < key[b].y; });
    int i = 1, j = 1;
    while (i <= m || j <= n) {
      if (i <= m && (j > n || key[st[i]].y < blo[j].y1))
        set.insert({key[st[i]].x, st[i]}), ++i;
      else {
        while (1) {
          auto it = set.lower_bound({blo[j].x1, -1});
          if (it == set.end() || it->first > blo[j].x2) break;
          up[it->second] = blo[j].y2;
          set.erase(it);
        }
        ++j;
      }
    }
  }
  prepare(1, 1, m);
  divide(1, 1, m);
  int ans = 0;
  for (int i = 1; i <= m; ++i)
    if (key[i].x == H && up[i] == 1e9) inc(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}
