#include <bits/stdc++.h>
using namespace std;
const int maxint = ~0U >> 1;
char *cp = (char *)malloc(200000000);
inline void sin(int &x) {
  while ((*cp < '0' || *cp > '9') && *cp != '-') ++cp;
  int sgn = 1;
  if (*cp == '-') {
    sgn = -1;
    cp++;
  }
  for (x = 0; *cp >= '0' && *cp <= '9';) x = x * 10 + (*cp++ ^ '0');
  x = sgn * x;
}
const int maxn = 111111;
const int maxm = 666;
const int INF = 0x3f3f3f3f;
struct node {
  int v, next;
} e[maxn];
int n, m, k, cnt = 0, ans = 0;
int fa[maxn], t[maxn], q[maxn], dep[maxn];
bool in[maxn];
int head[maxn];
set<int> qset;
bool islca[maxn];
vector<int> link[maxm];
int sortedlink[maxm][maxm * 4 + 10];
int linkfa[maxn], linkid[maxn], linkcur[maxn], linkfrom[maxm], linkcnt = 0;
void dfs_fk(int u) {
  if (qset.count(u)) {
    linkid[u] = ++linkcnt;
    linkfrom[linkid[u]] = u;
    islca[u] = 1;
  }
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].v;
    dfs_fk(v);
  }
  if (!linkid[u]) return;
  if (!qset.count(u)) link[linkid[u]].push_back(u);
  if (!linkid[fa[u]])
    linkid[fa[u]] = linkid[u];
  else {
    if (!islca[fa[u]]) {
      islca[fa[u]] = 1;
      linkfa[linkid[fa[u]]] = ++linkcnt;
      linkid[fa[u]] = linkcnt;
    }
    linkfa[linkid[u]] = linkid[fa[u]];
  }
}
void query(int i) {
  int x = linkid[abs(q[i])];
  in[abs(q[i])] = !in[abs(q[i])];
  bool flag = 0;
  while (x) {
    if (flag) {
      int tmp = linkfrom[x];
      if (tmp) {
        if (q[i] > 0) {
          t[tmp]--;
          if (!in[tmp] && t[tmp] == -1) ans++;
        } else {
          t[tmp]++;
          if (!in[tmp] && t[tmp] == 0) ans--;
        }
      }
    }
    if (q[i] > 0) {
      if (abs(linkcur[x]) < maxm * 2)
        ans += sortedlink[x][linkcur[x] + maxm * 2];
      linkcur[x]++;
    } else {
      linkcur[x]--;
      if (abs(linkcur[x]) < maxm * 2)
        ans -= sortedlink[x][linkcur[x] + maxm * 2];
    }
    x = linkfa[x];
    flag = 1;
  }
  if (t[abs(q[i])] < 0) {
    if (in[abs(q[i])])
      ans--;
    else
      ans++;
  }
  if (i > 1) printf(" ");
  printf("%d", ans);
}
void sortlink(int x) {
  for (int i = 0; i < link[x].size(); ++i) {
    int tmp = t[link[x][i]];
    if (!in[link[x][i]] && !qset.count(link[x][i])) {
      if (abs(tmp) < maxm * 2) sortedlink[x][tmp + maxm * 2]++;
    }
  }
}
void solve(int st, int n) {
  if (n == 1) {
    int x = abs(q[st]);
    in[x] = !in[x];
    if (t[x] < 0) {
      if (in[x])
        ans--;
      else
        ans++;
    }
    while (x) {
      if (q[st] > 0) {
        t[x]--;
        if (!in[x] && t[x] == -1) ans++;
      } else {
        t[x]++;
        if (!in[x] && t[x] == 0) ans--;
      }
      x = fa[x];
    }
    if (st > 1) printf(" ");
    printf("%d", ans);
    return;
  }
  qset.clear();
  qset.insert(abs(q[st]));
  memset(sortedlink, 0, sizeof sortedlink);
  memset(linkfrom, 0, sizeof linkfrom);
  memset(islca, 0, sizeof islca);
  memset(linkfa, 0, sizeof linkfa);
  memset(linkid, 0, sizeof linkid);
  memset(linkcur, 0, sizeof linkcur);
  linkcnt = 0;
  for (int i = st + 1; i < st + n; ++i) {
    qset.insert(abs(q[i]));
  }
  dfs_fk(1);
  for (int i = 0; i <= linkcnt; ++i) sortlink(i);
  for (int i = 0; i < n; ++i) query(i + st);
  for (int i = 0; i <= linkcnt; ++i) {
    for (int j = 0; j < link[i].size(); ++j) {
      t[link[i][j]] -= linkcur[i];
    }
    link[i].clear();
  }
}
int main() {
  fread(cp, 1, 200000000, stdin);
  sin(n), sin(m);
  memset(head, -1, sizeof head);
  k = sqrt(max(m, n));
  fa[1] = 0;
  for (int i = 2; i <= n; ++i) {
    sin(fa[i]);
    e[cnt].v = i;
    e[cnt].next = head[fa[i]];
    head[fa[i]] = cnt++;
  }
  for (int i = 1; i <= n; ++i) sin(t[i]);
  for (int i = 1; i <= m; ++i) sin(q[i]);
  int cnt = 0;
  for (int i = 1; i <= m; ++i) {
    cnt++;
    if (cnt == k) {
      solve(i - cnt + 1, cnt);
      cnt = 0;
    }
  }
  if (cnt) solve(m - cnt + 1, cnt);
  printf("\n");
}
