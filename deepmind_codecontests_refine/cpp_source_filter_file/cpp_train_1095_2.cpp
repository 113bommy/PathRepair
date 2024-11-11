#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int y, len;
  Edge *next;
};
struct Data {
  int val, pl;
  Data() {}
  Data(int tv, int tp) {
    val = tv;
    pl = tp;
  }
};
Data tmp1[1000010];
Edge *b[6000010];
int dis[6000010], d[6000010];
int tmp[2000000];
int *a[1000010];
int f[1000010];
int tot;
queue<int> q;
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void addedge(int x, int y, int len) {
  Edge *p = new Edge;
  p->y = y;
  p->len = len;
  p->next = b[x];
  b[x] = p;
  d[y]++;
}
bool cmp(Data a, Data b) { return a.val < b.val; }
void toposort() {
  for (int i = 1; i <= tot; i++)
    if (d[i] == 0) {
      q.push(i);
      dis[i] = 1;
    }
  for (; !q.empty();) {
    int x = q.front();
    q.pop();
    for (Edge *i = b[x]; i != NULL; i = i->next) {
      dis[i->y] = max(dis[i->y], dis[x] + i->len);
      d[i->y]--;
      if (d[i->y] == 0) q.push(i->y);
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) a[i] = tmp + (i - 1) * (m + 2);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) tmp1[j] = Data(a[i][j], j);
    sort(tmp1 + 1, tmp1 + m + 1, cmp);
    for (int j = 1; j <= m; j++) {
      int k = j;
      for (; k + 1 <= m && tmp1[k + 1].val == tmp1[j].val; k++)
        ;
      int tmp = (i - 1) * m + tmp1[j].pl;
      for (int l = j; l <= k; l++) f[(i - 1) * m + tmp1[l].pl] = tmp;
      j = k;
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) tmp1[i] = Data(a[i][j], i);
    sort(tmp1 + 1, tmp1 + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
      int k = i;
      for (; k + 1 <= n && tmp1[k + 1].val == tmp1[i].val; k++)
        ;
      int mn = find((tmp1[i].pl - 1) * m + j);
      for (int l = i; l <= k; l++) mn = min(mn, find((tmp1[l].pl - 1) * m + j));
      for (int l = i; l <= k; l++) f[(tmp1[l].pl - 1) * m + j] = mn;
      i = k;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) f[(i - 1) * m + j] = find((i - 1) * m + j);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) tmp1[j] = Data(a[i][j], j);
    sort(tmp1 + 1, tmp1 + m + 1, cmp);
    for (int j = 1; j <= m; j++) {
      int k = j;
      for (; k + 1 <= m && tmp1[k + 1].val == tmp1[j].val; k++)
        ;
      if (j != 1)
        addedge(f[(i - 1) * m + tmp1[j - 1].pl], f[(i - 1) * m + tmp1[j].pl],
                1);
      j = k;
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) tmp1[i] = Data(a[i][j], i);
    sort(tmp1 + 1, tmp1 + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
      int k = i;
      for (; k + 1 <= n && tmp1[k + 1].val == tmp1[i].val; k++)
        ;
      if (i != 1)
        addedge(f[(tmp1[i - 1].pl - 1) * m + j], f[(tmp1[i].pl - 1) * m + j],
                1);
      i = k;
    }
  }
  tot = n * m;
  toposort();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) printf("%d ", dis[f[(i - 1) * m + j]]);
    printf("%d\n", dis[f[i * m]]);
  }
  return 0;
}
