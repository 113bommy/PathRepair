#include <bits/stdc++.h>
using namespace std;
int n, m, sum[1000005], fx[] = {1, 0, 0, -1, 0, 1, -1, 0};
int id(int x, int y) { return (x - 1) * m + y; }
int hd[1000005], nx[1000005], to[1000005], w[1000005], cnt = 1, a[1000005],
                                                       ans1[1000005];
char ans2[1000005];
void Add(int x, int y, int t) {
  nx[++cnt] = hd[x];
  hd[x] = cnt;
  to[cnt] = y;
  w[cnt] = t;
  nx[++cnt] = hd[y];
  hd[y] = cnt;
  to[cnt] = x;
  w[cnt] = 0;
}
void add(int x, int y, int l, int r) {
  if (r > l) Add(x, y, r - l);
  a[x] += l;
  a[y] -= l;
}
int dis[1000005], sk[1000005], ls[1000005], mk[1000005];
void init() {
  for (int i = 1; i <= n * m + 3; ++i) hd[i] = a[i] = mk[i] = ans1[i] = 0;
  cnt = 1;
}
bool bfs(int s, int t) {
  int l = 1, r = 0;
  for (int i = 1; i <= n * m + 3; ++i) dis[i] = 0;
  dis[s] = 1;
  sk[++r] = s;
  while (l <= r) {
    int p = sk[l++];
    for (int i = hd[p]; i; i = nx[i])
      if (w[i]) {
        int v = to[i];
        if (!dis[v]) dis[v] = dis[p] + 1, sk[++r] = v;
      }
  }
  return dis[t] != 0;
}
int dfs(int s, int t, int val) {
  if (s == t) return val;
  int rest = val;
  for (int &i = hd[s]; i; i = nx[i])
    if (w[i]) {
      int v = to[i];
      if (dis[v] == dis[s] + 1) {
        int tp = dfs(v, t, min(w[i], rest));
        w[i] -= tp;
        rest -= tp;
        w[i ^ 1] += tp;
        if (rest == 0) break;
      }
    }
  if (rest == val) dis[s] = 0;
  return val - rest;
}
int dinic(int s, int t) {
  while (bfs(s, t)) {
    for (int i = 1; i <= n * m + 3; ++i) ls[i] = hd[i];
    dfs(s, t, 1e9);
    for (int i = 1; i <= n * m + 3; ++i) hd[i] = ls[i];
  }
  for (int i = hd[s]; i; i = nx[i])
    if (w[i]) return 0;
  return 1;
}
void add(int x, int y, int t, char s) {
  if (x < 1 || x > n || y < 1 || y > m) return;
  int f = id(x, y);
  if (sum[f] < sum[t]) ans1[t] = sum[t] - sum[f], ans2[t] = s;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &sum[id(i, j)]);
  int s = n * m + 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int f = 0, t1 = id(i, j);
      for (int k = 0; k < 4; ++k) {
        int s1 = i + fx[k], s2 = j + fx[k + 4];
        if (s1 >= 1 && s1 <= n && s2 >= 1 && s2 <= m) {
          int t2 = id(s1, s2);
          if (sum[t1] == sum[t2] && ((i + j) & 1))
            add(t1, t2, 0, 1);
          else if (sum[t2] < sum[t1])
            f = 1;
        }
      }
      if (!f) {
        if ((i + j) & 1)
          add(s, t1, 1, 1);
        else
          add(t1, s, 1, 1);
      } else {
        if ((i + j) & 1)
          add(s, t1, 0, 1);
        else
          add(t1, s, 0, 1);
      }
    }
  }
  for (int i = 1; i <= n * m + 1; ++i)
    if (a[i] > 0)
      Add(i, n * m + 3, a[i]);
    else if (a[i] < 0)
      Add(n * m + 2, i, -a[i]);
  if (!dinic(n * m + 2, n * m + 3)) {
    puts("NO");
    return;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if ((i + j) & 1) {
        int t = id(i, j);
        for (int k = hd[t]; k; k = nx[k])
          if (!w[k]) {
            int v = to[k];
            if (v <= n * m) {
              ans1[t] = sum[v] - 1;
              ans1[v] = 1;
              mk[t] = mk[v] = 1;
              if (v == t + m)
                ans2[t] = 'D', ans2[v] = 'U';
              else if (v == t - m)
                ans2[t] = 'U', ans2[v] = 'D';
              else if (j > 1 && v == t - 1)
                ans2[t] = 'L', ans2[v] = 'R';
              else
                ans2[t] = 'R', ans2[v] = 'L';
            }
          }
      }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int t = id(i, j);
      if (!mk[t]) {
        add(i - 1, j, t, 'U');
        add(i + 1, j, t, 'D');
        add(i, j - 1, t, 'L');
        add(i, j + 1, t, 'R');
      }
    }
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%d ", ans1[id(i, j)]);
    puts("");
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%c ", ans2[id(i, j)]);
    puts("");
  }
  init();
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
