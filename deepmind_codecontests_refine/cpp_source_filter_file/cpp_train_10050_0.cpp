#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int n, k, Hatate[100050], st[100050], stop = 0;
long long w[100050], g[100050], Aya[100050], succ[100050], ans = 0;
vector<int> G[100050];
struct SegTree {
  int l, r;
  long long max_succ, max_p, min_p, tag;
} t[500050];
inline void Push_Down(int id) {
  if (t[id].tag) {
    t[id << 1].tag += t[id].tag;
    t[id << 1].max_succ += t[id].tag;
    t[id << 1].min_p += t[id].tag;
    t[id << 1 | 1].tag += t[id].tag;
    t[id << 1 | 1].max_succ += t[id].tag;
    t[id << 1 | 1].min_p += t[id].tag;
    t[id].tag = 0;
  }
}
inline long long Calc(int id, long long val) {
  if (t[id].l == t[id].r) return val + t[id].max_p;
  Push_Down(id);
  int mid = (t[id].l + t[id].r) >> 1;
  if (t[id << 1].max_succ >= val)
    return min(Calc(id << 1, val), t[id].min_p);
  else
    return min(val + t[id << 1].max_p, Calc(id << 1 | 1, val));
}
inline void Push_Up(int id) {
  t[id].max_succ = max(t[id << 1].max_succ, t[id << 1 | 1].max_succ);
  t[id].min_p = Calc(id << 1 | 1, t[id << 1].max_succ);
}
inline void Build(int id, int l, int r) {
  t[id].l = l;
  t[id].r = r;
  if (l == r) {
    t[id].max_succ = succ[l];
    t[id].max_p = -succ[l];
    return;
  }
  int mid = (l + r) >> 1;
  Build(id << 1, l, mid);
  Build(id << 1 | 1, mid + 1, r);
  Push_Up(id);
  t[id].max_p = min(t[id << 1].max_p, t[id << 1 | 1].max_p);
}
inline void Change(int id, int l, int r, long long val) {
  if (l > r) return;
  if (l <= t[id].l && t[id].r <= r) {
    t[id].tag += val;
    t[id].max_succ += val;
    t[id].min_p += val;
    return;
  }
  Push_Down(id);
  int mid = (t[id].l + t[id].r) >> 1;
  if (r <= mid)
    Change(id << 1, l, r, val);
  else if (l > mid)
    Change(id << 1 | 1, l, r, val);
  else {
    Change(id << 1, l, mid, val);
    Change(id << 1 | 1, mid + 1, r, val);
  }
  Push_Up(id);
}
inline long long Solve(int id, long long val) {
  if (t[id].l == t[id].r) return t[id].max_p + val <= k ? t[id].l : 0;
  Push_Down(id);
  int mid = (t[id].l + t[id].r) >> 1;
  if (val + t[id << 1 | 1].max_p <= k)
    return Solve(id << 1 | 1, val);
  else
    return Solve(id << 1, val);
}
inline long long Query(int id, long long val) {
  if (t[id].l == t[id].r) return t[id].max_p + val <= k ? t[id].l : 0;
  Push_Down(id);
  int mid = (t[id].l + t[id].r) >> 1;
  if (t[id << 1].max_succ >= val) {
    if (t[id].min_p <= k)
      return Query(id << 1 | 1, t[id << 1].max_succ);
    else
      return Query(id << 1, val);
  } else
    return max(Solve(id << 1, val), Query(id << 1 | 1, val));
}
inline void dfs(int u) {
  st[++stop] = u;
  if (u != n + 1) {
    Change(1, 1, u - 1, -1e16);
    Change(1, Hatate[u] - 1, n, Aya[u - 1] - Aya[Hatate[u] - 1]);
    int l = 1, r = stop;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (Aya[u - 1] - Aya[st[mid] - 1] <= k)
        r = mid;
      else
        l = mid + 1;
    }
    Change(1, st[r - 1], n, 1e16);
    ans = max(ans, Query(1, -1e16) - u + 1);
    Change(1, st[r - 1], n, -1e16);
    Change(1, 1, u - 1, 1e16);
  }
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    dfs(v);
  }
  if (u != n + 1) Change(1, Hatate[u] - 1, n, Aya[Hatate[u] - 1] + Aya[u - 1]);
  stop--;
}
int main() {
  n = read(), k = read();
  for (int i = 1; i < n; i++) w[i] = read();
  w[n] = 1e16;
  for (int i = 1; i <= n; i++) {
    g[i] = read();
    Aya[i] = Aya[i - 1] + g[i] - w[i];
    succ[i] = succ[i - 1] + g[i] - w[i - 1];
  }
  stop = 0;
  st[0] = n;
  for (int i = n - 1; i >= 0; i--) {
    while (stop && Aya[st[stop]] >= Aya[i]) stop--;
    Hatate[i + 1] = st[stop] + 1;
    G[Hatate[i + 1]].push_back(i + 1);
    st[++stop] = i;
  }
  Build(1, 1, n);
  stop = 0;
  memset(st, 0, sizeof(st));
  dfs(n + 1);
  cout << ans << endl;
  return 0;
}
