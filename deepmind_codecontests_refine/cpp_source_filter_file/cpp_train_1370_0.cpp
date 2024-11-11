#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
struct Edge {
  int to, next;
} edge[N * 2];
int head[N], num;
void add_edge(int a, int b) { edge[++num] = (Edge){b, head[a]}, head[a] = num; }
int n, q[N], a[N], a0[N], ccc;
char s[N];
void dfs(int x, int d, int f, int ff) {
  if (x != ff) a[x] = 1;
  if (!d) return;
  for (int i = head[x]; i; i = edge[i].next)
    if (edge[i].to != f) dfs(edge[i].to, d - 1, x, ff);
}
void wen() {
  printf("? ");
  for (int i = 1; i <= n; i++) printf("%d ", min(q[i], n - 1));
  printf("\n");
  fflush(stdout);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
}
bool vis[N], vv[N];
vector<int> t[N], tt[N], nt[N], td[3];
int st[N], dep[N], ea[N], ce;
pair<int, int> ee[N];
int main() {
  scanf("%d", &n);
  t[0].push_back(1);
  for (int i = 1; i <= n; i++) tt[0].push_back(i);
  int cnt = n - 1;
  vis[0] = vis[1022] = vv[1] = true;
  int la;
  while (cnt) {
    if (la == 20) break;
    la++;
    int top = 0;
    for (int i = 0; i <= 1022; i++)
      if (vis[i]) st[++top] = i;
    for (int i = 1; i <= top - 1; i++)
      if ((i & 1) && tt[st[i]].size()) {
        int tmp = (st[i + 1] - st[i]) / 2;
        vis[st[i] + tmp] = true;
        for (int j = 0; j <= t[st[i]].size() - 1; j++) q[t[st[i]][j]] = tmp;
      }
    wen();
    for (int i = 1; i <= n; i++) {
      a0[i] = a[i];
      if (q[i]) q[i]--;
    }
    wen();
    memset(q, 0, sizeof(q));
    for (int i = 1; i <= top - 1; i++)
      if ((i & 1) && tt[st[i]].size()) {
        int tmp = (st[i + 1] - st[i]) / 2;
        for (int j = 0; j <= tt[st[i]].size() - 1; j++) {
          if (vv[tt[st[i]][j]] || a[tt[st[i]][j]])
            nt[st[i]].push_back(tt[st[i]][j]);
          else
            nt[st[i] + tmp].push_back(tt[st[i]][j]);
          if (!vv[tt[st[i]][j]] && a0[tt[st[i]][j]] && !a[tt[st[i]][j]])
            cnt--, vv[tt[st[i]][j]] = true,
                   t[st[i] + tmp].push_back(tt[st[i]][j]);
        }
      }
    for (int i = 1; i <= top - 1; i++)
      if (!(i & 1) && tt[st[i]].size()) {
        int tmp = (st[i + 1] - st[i]) / 2;
        vis[st[i] + tmp] = true;
        for (int j = 0; j <= t[st[i]].size() - 1; j++) q[t[st[i]][j]] = tmp;
      }
    wen();
    for (int i = 1; i <= n; i++) {
      a0[i] = a[i];
      if (q[i]) q[i]--;
    }
    wen();
    memset(q, 0, sizeof(q));
    for (int i = 1; i <= top - 1; i++)
      if (!(i & 1) && tt[st[i]].size()) {
        int tmp = (st[i + 1] - st[i]) / 2;
        for (int j = 0; j <= tt[st[i]].size() - 1; j++) {
          if (vv[tt[st[i]][j]] || a[tt[st[i]][j]])
            nt[st[i]].push_back(tt[st[i]][j]);
          else
            nt[st[i] + tmp].push_back(tt[st[i]][j]);
          if (!vv[tt[st[i]][j]] && a0[tt[st[i]][j]] && !a[tt[st[i]][j]])
            cnt--, vv[tt[st[i]][j]] = true,
                   t[st[i] + tmp].push_back(tt[st[i]][j]);
        }
      }
    for (int i = 0; i <= n; i++) {
      tt[i] = nt[i];
      nt[i].clear();
    }
  }
  for (int i = 0; i <= n; i++)
    if (t[i].size())
      for (int j = 0; j <= t[i].size() - 1; j++) {
        dep[t[i][j]] = i, td[i % 3].push_back(t[i][j]);
      }
  for (int i = 0; i <= 2; i++)
    if (td[i].size()) {
      for (int j = 0; j <= 9; j++) {
        for (int k = 0; k <= td[i].size() - 1; k++)
          if (td[i][k] & (1 << (j - 1))) q[td[i][k]] = 1;
        wen();
        memset(q, 0, sizeof(q));
        for (int k = 1; k <= n; k++)
          if (a[k] && dep[k] % 3 == (i + 1) % 3) ea[k] |= (1 << (j - 1));
      }
      for (int j = 1; j <= n; j++)
        if (dep[j] % 3 == (i + 1) % 3 && ea[j]) ee[++ce] = make_pair(ea[j], j);
    }
  printf("!\n");
  for (int i = 1; i <= n - 1; i++) {
    printf("%d %d", ee[i].first, ee[i].second);
    if (i != n - 1) printf("\n");
  }
  return 0;
}
