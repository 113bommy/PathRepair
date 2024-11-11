#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int vis[N];
int fa[N];
int size[N];
int c[N];
int son[N];
vector<int> col[N], vec[N];
int flag;
int n, m;
int T;
void print() {
  int i;
  printf("YES\n");
  for (i = 1; i <= n; i++) printf("%d ", c[i]);
  printf("\n");
}
void dfs1(int x) {
  int i, y;
  int ok = 0;
  col[T].push_back(x);
  vis[x] = T;
  for (i = 0; i <= (int)vec[x].size() - 1; i++) {
    if (flag) return;
    y = vec[x][i];
    if (y == fa[x]) {
      if (!ok) {
        ok = 1;
        continue;
      }
    }
    if (vis[y]) {
      flag = 1;
      while (true) {
        c[x] = 1;
        if (x == y) break;
        x = fa[x];
      }
      return;
    }
    fa[y] = x;
    dfs1(y);
  }
}
void dfs2(int x) {
  int i, y;
  size[x] = 1;
  for (i = 0; i <= (int)vec[x].size() - 1; i++) {
    y = vec[x][i];
    if (y == fa[x]) continue;
    fa[y] = x;
    dfs2(y);
    size[x] += size[y];
  }
}
void dfs3(int x, int last, int d) {
  last -= d;
  if (!last) return;
  c[x] = last;
  int i, y;
  for (i = 0; i <= (int)vec[x].size() - 1; i++) {
    y = vec[x][i];
    if (y == fa[x]) continue;
    dfs3(y, last, d);
  }
}
bool cmp(int aa, int bb) { return size[aa] < size[bb]; }
bool work(int id) {
  static int d[5], dep[5], cd;
  int cnt, rt, i, j, x;
  cd = 0;
  cnt = 0;
  for (i = 0; i <= (int)col[id].size() - 1; i++)
    if (son[col[id][i]] == 3) cnt++, rt = col[id][i];
  if (!cnt) return false;
  dfs2(rt);
  if (cnt > 1) {
    for (i = 0; i <= (int)col[id].size() - 1; i++) c[col[id][i]] = 1;
    for (i = 0; i <= (int)col[id].size() - 1; i++) {
      x = vec[id][i];
      if (x != rt && son[x] == 3) {
        flag = 1;
        while (true) {
          c[x] = 2;
          if (x == rt) break;
          x = fa[x];
        }
        break;
      }
    }
    return true;
  }
  for (i = 0; i <= 2; i++) d[++cd] = vec[rt][i];
  sort(d + 1, d + 1 + cd, cmp);
  dep[1] = size[d[1]] + 1;
  dep[2] = size[d[2]] + 1;
  dep[3] = size[d[3]] + 1;
  if (dep[1] >= 3) {
    c[rt] = 3;
    flag = 1;
    for (i = 1; i <= 3; i++) dfs3(d[i], 3, 1);
    return true;
  }
  if (dep[2] == 2) return false;
  if (dep[3] >= 6) {
    c[rt] = 5;
    flag = 1;
    dfs3(d[1], 6, 3);
    dfs3(d[2], 6, 2);
    dfs3(d[3], 6, 1);
    return true;
  }
  if ((dep[2] + dep[3]) * 2 > dep[2] * dep[3])
    return false;
  else {
    flag = 1;
    c[rt] = dep[1] * dep[2] * dep[3];
    dfs3(d[1], c[rt], c[rt] / dep[1]);
    dfs3(d[2], c[rt], c[rt] / dep[2]);
    dfs3(d[3], c[rt], c[rt] / dep[3]);
    return true;
  }
}
int main() {
  int cas;
  int i, x, y, j;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d%d", &n, &m);
    T = 0;
    flag = 0;
    for (i = 1; i <= n; i++) {
      fa[i] = 0;
      vis[i] = 0;
      son[i] = 0;
      vec[i].clear();
      c[i] = 0;
      col[i].clear();
    }
    for (i = 1; i <= m; i++) {
      scanf("%d%d", &x, &y);
      son[x]++;
      son[y]++;
      vec[x].push_back(y);
      vec[y].push_back(x);
    }
    for (i = 1; i <= n; i++)
      if (!vis[i]) {
        T++;
        dfs1(i);
        if (flag) break;
      }
    if (flag) {
      print();
      continue;
    }
    for (i = 1; i <= n; i++)
      if (son[i] > 3) {
        flag = 1;
        c[i] = 2;
        for (j = 0; j <= (int)vec[i].size() - 1; j++) c[vec[i][j]] = 1;
        break;
      }
    if (flag) {
      print();
      continue;
    }
    for (i = 1; i <= n; i++) fa[i] = 0;
    for (i = 1; i <= T; i++)
      if (work(i)) break;
    if (flag)
      print();
    else
      printf("NO\n");
  }
}
