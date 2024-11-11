#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, q, k, x, ans[N], tag, fa[N], dep[N];
struct data {
  int u, v, w, id, x, y;
} e[N];
bool cmp_w(const data x, const data y) { return x.w < y.w; }
bool cmp_id(const data x, const data y) { return x.id < y.id; }
struct E {
  int u, v, w;
} a[N];
bool cmp(const E x, const E y) { return x.w < y.w; }
stack<E> stck;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return f * x;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
inline int getfa(int x) { return (fa[x] == x) ? x : getfa(fa[x]); }
inline void merge(int u, int v) {
  int fu = getfa(u), fv = getfa(v);
  if (fu == fv) return;
  if (dep[fu] > dep[fv]) swap(u, v), swap(fu, fv);
  fa[fu] = fv;
  if (dep[fu] == dep[fv])
    dep[fv]++, stck.push((E){u, v, 1});
  else
    stck.push((E){u, v, 0});
  return;
}
inline void del() {
  while (stck.size()) {
    E tmp = stck.top();
    stck.pop();
    dep[tmp.v] -= tmp.w;
    fa[tmp.u] = tmp.u;
  }
  return;
}
int main() {
  n = read(), m = read();
  for (register int i = (1); i <= (m); i++)
    e[i].u = read(), e[i].v = read(), e[i].w = read(), e[i].id = i;
  sort(e + 1, e + m + 1, cmp_w);
  for (register int i = (1); i <= (n); i++) fa[i] = i;
  for (register int i = (1); i <= (m); i++) {
    int l = i, r = i - 1;
    while (r < m && e[r + 1].w == e[l].w) {
      r++;
      e[r].x = getfa(e[r].u);
      e[r].y = getfa(e[r].v);
    }
    for (register int j = (l); j <= (r); j++) merge(e[j].u, e[j].v);
    i = r;
  }
  while (stck.size()) stck.pop();
  sort(e + 1, e + m + 1, cmp_id);
  for (register int i = (1); i <= (n); i++) fa[i] = i;
  q = read();
  for (register int Case = (1); Case <= (q); Case++) {
    tag = 1;
    k = read();
    for (register int i = (1); i <= (k); i++)
      x = read(), a[i] = (E){e[x].x, e[x].y, e[x].w};
    sort(a + 1, a + k + 1, cmp);
    for (register int i = (1); i <= (k); i++) {
      int l = i, r = i - 1;
      while (r < k && a[r + 1].w == a[l].w) {
        r++;
        if (getfa(a[r].u) == getfa(a[r].v)) tag = 0;
        merge(a[r].u, a[r].v);
      }
      i = r;
      del();
    }
    ans[Case] = tag;
  }
  for (register int i = (1); i <= (q); i++) {
    if (ans[i])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
