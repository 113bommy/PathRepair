#include <bits/stdc++.h>
using namespace std;
const int block = sqrt(400000);
string str[100001];
struct AC_automation {
  int ch[26];
  int fail;
  vector<int> v;
} t[100001];
int ed[100001];
int ver_cnt = 0;
int insert(int u, int x, int i) {
  if (str[i].size() >= block) t[u].v.push_back(i);
  if (x == str[i].size()) return u;
  int nxt = str[i][x] - 'a';
  if (!t[u].ch[nxt]) t[u].ch[nxt] = ++ver_cnt;
  return insert(t[u].ch[nxt], x + 1, i);
}
void get_fail() {
  queue<int> q;
  for (int i = 0; i < 26; i++)
    if (t[0].ch[i]) q.push(t[0].ch[i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (!t[u].ch[i])
        t[u].ch[i] = t[t[u].fail].ch[i];
      else {
        t[t[u].ch[i]].fail = t[t[u].fail].ch[i];
        q.push(t[u].ch[i]);
      }
    }
  }
}
int dfn_cnt;
vector<int> e[100001];
int dfn[100001];
int siz[100001];
void dfs(int u, int fa) {
  siz[u] = 1, dfn[u] = ++dfn_cnt;
  for (int i = 0; i < e[u].size(); i++) {
    int to = e[u][i];
    if (to != fa) {
      dfs(to, u);
      siz[u] += siz[to];
    }
  }
}
struct fenwick {
  int c[100001];
  void add(int x, int ind) {
    while (x <= 100000) c[x] += ind, x += x & -x;
  }
  int ask(int x) {
    if (x == 0) return 0;
    int ans = 0;
    while (x) ans += c[x], x -= x & -x;
    return ans;
  }
} f;
int n;
vector<int> v;
map<int, int> mp[100001];
map<int, int> res[100001];
long long cnt[100001];
void predone(int u, int fa) {
  for (int i = 0; i < t[u].v.size(); i++) {
    int x = t[u].v[i];
    mp[u][x]++;
  }
  for (int i = 0; i < e[u].size(); i++) {
    int to = e[u][i];
    if (to != fa) {
      predone(to, u);
      for (int j = 0; j < v.size(); j++) mp[u][v[j]] += mp[to][v[j]];
    }
  }
}
void solve1() {
  for (int i = 1; i <= n; i++)
    if (str[i].size() >= block) v.push_back(i);
  predone(0, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < v.size(); j++) cnt[v[j]] += mp[ed[i]][v[j]];
    for (int j = 0; j < v.size(); j++) res[i][v[j]] = cnt[v[j]];
  }
}
struct node {
  int l, r, k, ind, id;
  long long ans;
} q[100001];
vector<node> rem[100001];
signed main() {
  int T;
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
    ed[i] = insert(0, 0, i);
  }
  get_fail();
  for (int i = 1; i <= ver_cnt; i++) e[t[i].fail].push_back(i);
  dfs(0, 0);
  solve1();
  for (int i = 1; i <= T; i++) {
    scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k);
    q[i].id = i;
    if (str[q[i].k].size() >= block)
      q[i].ans = res[q[i].r][q[i].k] - res[q[i].l - 1][q[i].k];
    else {
      q[i].ind = -1, rem[q[i].l - 1].push_back(q[i]);
      q[i].ind = 1, rem[q[i].r].push_back(q[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    f.add(dfn[ed[i]], 1);
    f.add(dfn[ed[i]] + siz[ed[i]], -1);
    for (int j = 0; j < rem[i].size(); j++) {
      int cur = rem[i][j].id;
      int u = 0, k = q[cur].k;
      for (int p = 0; p < str[k].size(); p++) {
        int nxt = str[k][p] - 'a';
        u = t[u].ch[nxt];
        q[cur].ans += rem[i][j].ind * f.ask(dfn[u]);
      }
    }
  }
  for (int i = 1; i <= T; i++) printf("%lld\n", q[i].ans);
  return 0;
}
