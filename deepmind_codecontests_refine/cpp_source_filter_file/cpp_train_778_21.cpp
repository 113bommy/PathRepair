#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
  int s, t, nxt;
} e[1000005];
int e_cnt, last[300005], tot, e_cnt_bak, last_bak[300005];
inline void ins(int a, int b) {
  e[e_cnt] = (edge){a, b, last[a]};
  last[a] = e_cnt++;
}
int bl[300005], num;
int dfn[300005], low[300005], TOT;
bool inst[300005];
int st[300005], top;
void tarjan(int x) {
  dfn[x] = low[x] = ++TOT;
  inst[x] = 1;
  st[++top] = x;
  for (int i = last[x]; i != -1; i = e[i].nxt)
    if (!dfn[e[i].t]) {
      tarjan(e[i].t);
      low[x] = min(low[x], low[e[i].t]);
    } else if (inst[e[i].t])
      low[x] = min(low[x], low[e[i].t]);
  if (low[x] == dfn[x]) {
    while (inst[x]) {
      inst[st[top]] = 0;
      bl[st[top]] = x;
      top--;
    }
  }
}
vector<int> T[300005], mb[300005];
int d[300005];
int q[300005];
bool val[300005];
bool check() {
  memset(dfn, 0, sizeof(dfn));
  TOT = 0;
  for (int i = 2; i <= tot * 2 + 1; i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 2; i <= tot * 2 + 1; i++) mb[i].clear(), T[i].clear();
  for (int i = 2; i <= tot * 2 + 1; i++) mb[bl[i]].push_back(i);
  for (int i = 0; i < e_cnt; i++)
    if (bl[e[i].s] != bl[e[i].t])
      T[bl[e[i].t]].push_back(bl[e[i].s]), d[bl[e[i].s]]++;
  int h, t;
  h = t = 0;
  for (int i = 2; i <= tot * 2 + 1; i++)
    if (bl[i] == i && !d[i]) q[++t] = i;
  memset(val, 0, sizeof(val));
  while (h < t) {
    h++;
    int x = q[h];
    bool ok = 1;
    for (int i = 0; i < mb[x].size(); i++)
      if (val[mb[x][i] ^ 1]) ok = 0;
    if (ok)
      for (int i = 0; i < mb[x].size(); i++) val[mb[x][i]] = 1;
    for (int i = 0; i < T[x].size(); i++) {
      d[T[x][i]]--;
      if (!d[T[x][i]]) q[++t] = T[x][i];
    }
  }
  for (int i = 1; i <= tot; i++)
    if (!(val[i * 2] ^ val[i * 2 + 1])) return false;
  return true;
}
struct E {
  int u, v, c, t, org;
  bool operator<(const E b) const { return t < b.t; }
} ee[50005];
bool us[50005];
map<int, int> vis;
vector<int> EE[50005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d%d", &ee[i].u, &ee[i].v, &ee[i].c, &ee[i].t), ee[i].org = i;
  sort(ee + 1, ee + m + 1);
  for (int i = 1; i <= m; i++) {
    EE[ee[i].u].push_back(i);
    EE[ee[i].v].push_back(i);
  }
  memset(last, -1, sizeof(last));
  tot = m;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    vis.clear();
    for (int j = 0; j < EE[i].size(); j++) {
      int id = EE[i][j];
      if (!vis.count(ee[id].c)) {
        vis[ee[id].c] = id;
        continue;
      }
      cnt++;
      int p = vis[ee[id].c];
      us[p] = us[id] = 1;
      ins(id * 2 + 1, p * 2);
      ins(p * 2 + 1, id * 2);
    }
    if (cnt > 1) {
      puts("No");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    bool fst = 1;
    int cnt = 0;
    for (int j = 0; j < EE[i].size(); j++)
      if (us[EE[i][j]]) cnt++;
    if (cnt < 2) continue;
    for (int j = 0; j < EE[i].size(); j++)
      if (us[EE[i][j]]) {
        int id = EE[i][j];
        tot++;
        ins(id * 2, tot * 2);
        ins(tot * 2 + 1, id * 2 + 1);
        if (!fst) {
          ins(id * 2, (tot - 1) * 2 + 1);
          ins((tot - 1) * 2, id * 2 + 1);
          ins((tot - 1) * 2, tot * 2);
          ins(tot * 2 + 1, (tot - 1) * 2 + 1);
        }
        fst = 0;
      }
  }
  if (!check()) {
    puts("No");
    return 0;
  }
  e_cnt_bak = e_cnt;
  memcpy(last_bak, last, sizeof(last));
  int l = 1, r = m;
  while (l < r) {
    int mid = l + ((r - l) >> 1);
    e_cnt = e_cnt_bak;
    memcpy(last, last_bak, sizeof(last));
    for (int i = mid + 1; i <= m; i++) ins(i * 2, i * 2 + 1);
    if (check())
      r = mid;
    else
      l = mid + 1;
  }
  puts("Yes");
  e_cnt = e_cnt_bak;
  memcpy(last, last_bak, sizeof(last));
  for (int i = l + 1; i <= m; i++) ins(i * 2, i * 2 + 1);
  check();
  int cnt = 0;
  for (int i = 1; i <= m; i++)
    if (us[i] && val[i * 2]) cnt++;
  printf("%d %d\n", ee[l].t, cnt);
  for (int i = 1; i <= m; i++)
    if (us[i] && val[i * 2]) printf("%d ", ee[i].org);
  puts("");
}
