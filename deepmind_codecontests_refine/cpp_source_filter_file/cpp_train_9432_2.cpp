#include <bits/stdc++.h>
using namespace std;
struct EDGE {
  int to, next, w;
} e[400010];
int head[200010], top;
void add(int u, int v, int w) {
  e[top].to = v;
  e[top].next = head[u];
  e[top].w = w;
  head[u] = top++;
}
vector<int> vv;
int vis[200010], tmpp = -1;
long long in_max;
int fa[200010], id[400010];
long long dep[200010];
long long l[400010], r[400010], wl[400010], idtop, val[400010];
vector<int> o;
void dfs(int x, int fa) {
  if (vis[x]) {
    tmpp = x;
    throw "w23c3c3";
  }
  vis[x] = 1;
  vv.push_back(x);
  int i;
  for (i = head[x]; ~i; i = e[i].next) {
    if (e[i].to == fa) continue;
    o.push_back(e[i].w);
    dfs(e[i].to, x);
    o.pop_back();
  }
  vv.pop_back();
}
void dfs1(int x) {
  int i;
  long long max_ = 0, se = 0, tmp;
  for (i = head[x]; ~i; i = e[i].next) {
    if (vis[e[i].to] || e[i].to == fa[x]) continue;
    fa[e[i].to] = x;
    dfs1(e[i].to);
    tmp = dep[e[i].to] + e[i].w;
    if (tmp > max_) {
      se = max_;
      max_ = tmp;
    } else {
      if (tmp > se) {
        se = tmp;
      }
    }
  }
  in_max = max(in_max, max_ + se);
  dep[x] = max_;
}
struct __ {
  int id;
  long long val;
  bool operator<(const __ &ob) const {
    if (val != ob.val) return val > ob.val;
    return id < ob.id;
  }
};
multiset<__> L, R;
int main() {
  memset(head, 255, sizeof(head));
  int n;
  scanf("%d", &n);
  int i;
  int u, v, w;
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
  }
  int tmp;
  try {
    dfs(1, 0);
  } catch (...) {
  }
  tmp = tmpp;
  memset(vis, 0, sizeof(vis));
  int len = 1;
  wl[idtop] = o.back();
  o.pop_back();
  id[idtop++] = tmp;
  vis[tmp] = 1;
  while (1) {
    if (vv.back() == tmp) break;
    len++;
    wl[idtop] = o.back();
    o.pop_back();
    id[idtop++] = vv.back();
    vv.pop_back();
    vis[id[idtop - 1]] = 1;
  }
  vv.clear();
  for (i = 1; i <= n; i++) {
    if (vis[i]) {
      dfs1(i);
    }
  }
  for (i = 0; i < len; i++) {
    val[i] = dep[id[i]];
  }
  for (i = 0; i < len; i++) {
    id[i + len] = id[i];
    wl[i + len] = wl[i];
    val[i + len] = val[i];
  }
  l[0] = r[0] = dep[0];
  for (i = 1; i < (len << 1) - 1; i++) {
    l[i] = l[i - 1] - val[i - 1] - wl[i - 1] + val[i];
    r[i] = r[i - 1] - val[i - 1] + wl[i - 1] + val[i];
  }
  long long ans = 998244353998244347;
  for (i = 0; i < len - 1; i++) {
    L.insert((__){id[i], l[i]});
    R.insert((__){id[i], r[i]});
  }
  __ tmpl1, tmpl2, tmpr1, tmpr2;
  for (i = len - 1; i + 1 < len << 1; i++) {
    L.insert((__){id[i], l[i]});
    R.insert((__){id[i], r[i]});
    tmpl1 = *L.begin();
    tmpl2 = *++L.begin();
    tmpr1 = *R.begin();
    tmpr2 = *++R.begin();
    if (tmpl1.id != tmpr1.id) {
      ans = min(ans, max(in_max, tmpl1.val + tmpr1.val));
    } else {
      ans = min(ans,
                max(in_max, max(tmpl1.val + tmpr2.val, tmpl2.val + tmpr1.val)));
    }
    L.erase(L.lower_bound((__){id[i - (len - 1)], l[i - (len - 1)]}));
    R.erase(R.lower_bound((__){id[i - (len - 1)], r[i - (len - 1)]}));
  }
  printf("%lld\n", ans);
  return 0;
}
