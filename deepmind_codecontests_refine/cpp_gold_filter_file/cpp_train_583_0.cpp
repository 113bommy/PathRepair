#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int n, fa[MAXN];
long long ans;
vector<int> vs[MAXN];
struct Tpoint {
  long long num, pos;
  long long cnt[5], odd[5];
  inline void reset() {
    num = 1;
    pos = 3;
    memset(cnt, 0, sizeof(cnt));
    memset(odd, 0, sizeof(odd));
  }
  inline void update(int t) {
    if (cnt[1] < t - 2)
      pos = 0;
    else if (cnt[1] == t - 2 && cnt[3] == 2)
      pos = 4, odd[0] = odd[3];
    else if (cnt[1] == t - 2 && cnt[3] == 1 && cnt[4] == 1)
      pos = 4, odd[0] = odd[4];
    else if (cnt[1] == t - 2)
      pos = 0;
    else if (cnt[1] == t)
      pos = 3, odd[0] = odd[1] + 1;
    else if (cnt[0] == 1)
      pos = 0;
    else if (cnt[2] == 1)
      pos = 4, odd[0] = odd[2];
    else if (cnt[3] == 1)
      pos = 1, odd[0] = odd[3];
    else if (cnt[4] == 1)
      pos = 2, odd[0] = odd[4];
  }
};
Tpoint ps[MAXN];
inline void dfs(int u) {
  int son = vs[u].size();
  for (int i = 0; i < son; ++i) {
    int v = vs[u][i];
    if (v == fa[u]) continue;
    fa[v] = u;
    dfs(v);
    ps[u].num += ps[v].num;
    ps[u].cnt[ps[v].pos]++;
    ps[u].odd[ps[v].pos] += ps[v].odd[0];
  }
  if (u > 1) --son;
  ps[u].update(son);
}
inline void dfs2(int u, Tpoint p) {
  int son = vs[u].size();
  Tpoint tmp = ps[u];
  if (u > 1) {
    tmp.num += p.num;
    tmp.cnt[p.pos]++;
    tmp.odd[p.pos] += p.odd[0];
  }
  for (int i = 0; i < son; ++i) {
    int v = vs[u][i];
    if (v == fa[u]) continue;
    p = tmp;
    p.num -= ps[v].num;
    p.cnt[ps[v].pos]--;
    p.odd[ps[v].pos] -= ps[v].odd[0];
    p.update(son - 1);
    if (p.pos == 1 && ps[v].pos == 1) ans += 1ll * p.num * ps[v].num;
    if (p.pos + ps[v].pos >= 6) ans += p.odd[0] * ps[v].odd[0];
    dfs2(v, p);
  }
}
inline void init() {
  memset(fa, 0, sizeof(fa));
  for (int i = 0; i < MAXN; ++i) ps[i].reset();
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    vs[u].push_back(v);
    vs[v].push_back(u);
  }
  fa[1] = -1;
  ans = 0;
}
inline void solve() {
  if (n & 1) {
    printf("0\n");
    return;
  }
  Tpoint p;
  dfs(1);
  dfs2(1, p);
  printf("%I64d\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
