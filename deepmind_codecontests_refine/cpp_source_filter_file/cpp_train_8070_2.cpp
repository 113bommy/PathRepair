#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, pre;
} e[2000010 * 2];
struct sor {
  int id, key;
} b[2000010];
int n, m, tot, num = 0, a[2000010] = {0}, last[2000010] = {0},
               du[2000010] = {0}, tuan[2000010] = {0}, tuannum = 0,
               ans[2000010];
vector<int> tua[2000010];
vector<int>::iterator it;
inline int cal(int i, int j) { return i * m + j; }
bool cmp(sor a, sor b) {
  return (a.key < b.key || (a.key == b.key && a.id < b.id));
}
void addedge(int u, int v) {
  e[++num].u = u;
  e[num].v = v;
  e[num].pre = last[u];
  last[u] = num;
}
int que[2000010], l, r;
void bfs(int dot) {
  l = 0;
  r = 1;
  que[0] = dot;
  tuan[dot] = ++tuannum;
  tua[tuannum].push_back(dot);
  while (l != r) {
    int u = que[l], tmp = last[u];
    while (tmp) {
      if (tuan[e[tmp].v] == 0 && a[e[tmp].v] == a[u]) {
        que[r] = e[tmp].v;
        tua[tuannum].push_back(e[tmp].v);
        tuan[e[tmp].v] = tuannum;
        ++r;
      }
      tmp = e[tmp].pre;
    }
    ++l;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  tot = n * m;
  for (int i = 0; i < tot; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[j].id = j;
      b[j].key = a[cal(i, j)];
    }
    sort(b, b + m, cmp);
    for (int j = 0; j < m - 1; j++) {
      if (b[j].key == b[j + 1].key) {
        addedge(cal(i, b[j].id), cal(i, b[j + 1].id));
        addedge(cal(i, b[j + 1].id), cal(i, b[j].id));
      } else
        addedge(cal(i, b[j].id), cal(i, b[j + 1].id));
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      b[j].id = j;
      b[j].key = a[cal(j, i)];
    }
    sort(b, b + n, cmp);
    for (int j = 0; j < n - 1; j++) {
      if (b[j].key == b[j + 1].key) {
        addedge(cal(b[j].id, i), cal(b[j + 1].id, i));
        addedge(cal(b[j + 1].id, i), cal(b[j].id, i));
      } else
        addedge(cal(b[j].id, i), cal(b[j + 1].id, i));
    }
  }
  for (int i = 0; i < tot; i++)
    if (tuan[i] == 0) bfs(i);
  for (int i = 0; i < num; i++)
    if (tuan[e[i].u] != tuan[e[i].v]) du[tuan[e[i].v]]++;
  l = r = 0;
  for (int i = 0; i < tot; i++) {
    ans[tuan[i]] = 1;
    if (!du[tuan[i]]) que[r++] = i;
  }
  while (l != r) {
    int u = que[l], tmp = last[u];
    while (tmp) {
      if (tuan[e[tmp].v] != tuan[u]) {
        int now = tuan[e[tmp].v];
        ans[now] = max(ans[now], ans[tuan[u]] + 1);
        du[now]--;
        if (!du[now]) {
          for (it = tua[now].begin(); it != tua[now].end(); ++it)
            que[r++] = *it;
        }
      }
      tmp = e[tmp].pre;
    }
    l++;
  }
  for (int i = 0; i < n; i++) {
    int st = cal(i, 0);
    for (int j = st; j < st + m; j++) printf("%d ", ans[tuan[j]]);
    printf("\n");
  }
  return 0;
}
