#include <bits/stdc++.h>
using namespace std;
const int N = 110000, M = N * 9;
int x, y, z, n, m, k, lt, rt, fr, bk, up, dn, ans[N], num, tree[N];
struct point {
  int x, y, z, ind;
  point(int x = 0, int y = 0, int z = 0, int i = 0)
      : x(x), y(y), z(z), ind(i) {}
  inline bool operator<(const point &a) const {
    if (y != a.y) return y < a.y;
    if (x != a.x) return x < a.x;
    if (z != a.z) return z < a.z;
    return !ind;
  }
} poi[M], tmp[M];
template <class T>
inline void read(T &x) {
  x = 0;
  char ch = getchar(), w = 0;
  while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = w ? -x : x;
  return;
}
inline void modify(int x, int w) {
  while (x <= z) tree[x] += w, x += x & -x;
  return;
}
inline int query(int x) {
  int ret = 0;
  while (x) ret += tree[x], x -= x & -x;
  return ret;
}
inline int sgn(int x) { return x > 0 ? 1 : -1; }
void solve(int l, int r, int lt, int rt) {
  if (l > r) return;
  if (lt == rt) {
    for (register int i = l; i <= r; ++i) {
      if (!poi[i].ind)
        modify(poi[i].z, 1);
      else
        ans[abs(poi[i].ind)] += sgn(poi[i].ind) * query(poi[i].z);
    }
    for (register int i = l; i <= r; ++i)
      if (!poi[i].ind) modify(poi[i].z, -1);
    return;
  }
  int mid = (lt + rt) >> 1, p = 0, q;
  for (register int i = l; i <= r; ++i) {
    if (poi[i].x <= mid) {
      ++p;
      if (!poi[i].ind) modify(poi[i].z, 1);
    } else {
      if (poi[i].ind) ans[abs(poi[i].ind)] += sgn(poi[i].ind) * query(poi[i].z);
    }
  }
  q = l + p, p = l;
  for (register int i = l; i <= r; ++i) {
    if (poi[i].x <= mid) {
      tmp[p++] = poi[i];
      if (!poi[i].ind) modify(poi[i].z, -1);
    } else
      tmp[q++] = poi[i];
  }
  for (register int i = l; i <= r; ++i) poi[i] = tmp[i];
  solve(l, p - 1, lt, mid), solve(p, r, mid + 1, rt);
  return;
}
int main() {
  int o, p, q, l, r, f, b, u, d;
  read(x), read(y), read(z), read(n), read(m), read(k);
  read(lt), rt = lt, read(fr), bk = fr, read(up), dn = up;
  while (--n) {
    read(o), read(p), read(q);
    lt = min(lt, o), rt = max(rt, o);
    fr = min(fr, p), bk = max(bk, p);
    up = min(up, q), dn = max(dn, q);
  }
  for (register int i = 1; i <= m; ++i) {
    read(o), read(p), read(q);
    if (o >= lt && o <= rt && p >= fr && p <= bk && q >= up && q <= dn)
      return printf("INCORRECT\n"), 0;
    poi[++num] = point(o, p, q, 0);
  }
  printf("CORRECT\n");
  for (register int i = 1; i <= k; ++i) {
    read(o), read(p), read(q);
    if (o >= lt && o <= rt && p >= fr && p <= bk && q >= up && q <= dn)
      ans[i] = -1;
    else {
      l = min(lt, o) - 1, r = max(rt, o), f = min(fr, p) - 1;
      b = max(bk, p), u = min(up, q) - 1, d = max(dn, q);
      poi[++num] = point(l, f, u, -i), poi[++num] = point(l, f, d, i);
      poi[++num] = point(l, b, u, i), poi[++num] = point(l, b, d, -i);
      poi[++num] = point(r, f, u, i), poi[++num] = point(r, f, d, -i);
      poi[++num] = point(r, b, u, -i), poi[++num] = point(r, b, d, i);
    }
  }
  sort(poi + 1, poi + 1 + num), solve(1, num, 0, x);
  for (register int i = 1; i <= k; ++i) {
    if (ans[i] == -1)
      printf("OPEN\n");
    else if (ans[i] == 0)
      printf("UNKNOWN\n");
    else
      printf("CLOSED\n");
  }
  return 0;
}
