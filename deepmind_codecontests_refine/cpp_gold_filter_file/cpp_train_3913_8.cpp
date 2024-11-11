#include <bits/stdc++.h>
using namespace std;
inline int Min(int x, int y) { return x < y ? x : y; }
inline int Max(int x, int y) { return x > y ? x : y; }
inline int read() {
  int kkk = 0, x = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') c = getchar(), x = -1;
  while (c >= '0' && c <= '9')
    kkk = (kkk << 3) + (kkk << 1) + (c - '0'), c = getchar();
  return kkk * x;
}
inline void write(int k) {
  if (k > 9) write(k / 10);
  putchar('0' + k % 10);
}
inline void del(multiset<int> &aa, int value) {
  aa.erase(aa.lower_bound(value));
}
multiset<int> oth, mp[100001], anc;
int n, fa[100001], son[100001], size[100001], rt, head[100001], tot,
    ans[100001];
struct sb {
  int to, nextn;
} a[100001];
inline void ADD(int from, int to) {
  a[++tot].to = to, a[tot].nextn = head[from];
  head[from] = tot;
}
inline void find(int u) {
  size[u] = 1;
  for (register int i = head[u]; i != 0; i = a[i].nextn) {
    int v = a[i].to;
    find(v);
    size[u] += size[v];
    if (size[v] > size[son[u]]) son[u] = v;
  }
  if (u != rt) oth.insert(size[u]);
}
inline int check(int F, int mid, int u, int minn, int maxn) {
  if (F) {
    multiset<int>::iterator mmp = mp[son[u]].lower_bound(maxn - mid);
    if (mmp != mp[son[u]].end() && (*mmp) <= mid - minn) return 1;
  } else {
    multiset<int>::iterator mmp = oth.lower_bound(maxn - mid);
    if (mmp != oth.end() && (*mmp) <= mid - minn) return 1;
    mmp = anc.lower_bound(maxn - mid + size[u]);
    if (mmp != anc.end() && (*mmp) <= mid - minn + size[u]) return 1;
  }
  return 0;
}
inline void fun(int u) {
  if (u != rt) del(oth, size[u]);
  if (fa[u] && fa[u] != rt) anc.insert(size[fa[u]]);
  int maxn = Max(size[son[u]], n - size[u]);
  int sec = Min(size[son[u]], n - size[u]);
  int minn = n - size[u];
  if (!minn) minn = size[son[u]];
  for (register int i = head[u]; i != 0; i = a[i].nextn) {
    int v = a[i].to;
    if (v == son[u]) continue;
    fun(v);
    for (register multiset<int>::iterator j = mp[v].begin(); j != mp[v].end();
         ++j)
      oth.insert(*j);
    sec = Max(sec, size[v]);
    minn = Min(minn, size[v]);
  }
  if (son[u]) fun(son[u]), minn = Min(minn, size[son[u]]);
  for (register int i = head[u]; i != 0; i = a[i].nextn) {
    int v = a[i].to;
    if (v == son[u]) continue;
    for (register multiset<int>::iterator j = mp[v].begin(); j != mp[v].end();
         ++j)
      del(oth, *j);
  }
  if (maxn != sec) {
    int l = sec, r = maxn;
    int F = (maxn == size[son[u]]);
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(F, mid, u, minn, maxn))
        ans[u] = mid, r = mid - 1;
      else
        l = mid + 1;
    }
  }
  if (!ans[u]) ans[u] = maxn;
  if (son[u]) swap(mp[u], mp[son[u]]);
  for (register int i = head[u]; i != 0; i = a[i].nextn) {
    int v = a[i].to;
    if (v == son[u]) continue;
    for (register multiset<int>::iterator j = mp[v].begin(); j != mp[v].end();
         mp[v].erase(j++))
      mp[u].insert(*j);
  }
  if (fa[u] && fa[u] != rt) del(anc, size[fa[u]]);
  mp[u].insert(size[u]);
}
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i) {
    int u = read(), v = read();
    if (u == 0) {
      rt = v;
      continue;
    }
    ADD(u, v), fa[v] = u;
  }
  find(rt);
  fun(rt);
  for (register int i = 1; i <= n; ++i) write(ans[i]), putchar('\n');
  return 0;
}
