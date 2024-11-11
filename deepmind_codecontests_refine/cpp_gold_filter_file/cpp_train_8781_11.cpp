#include <bits/stdc++.h>
using namespace std;
const int N = 155;
const int INF = 123456789;
struct edge {
  int to, lim, pri, rev;
  edge() : to(0), lim(0), pri(0), rev(0){};
  edge(int to, int lim, int pri, int rev)
      : to(to), lim(lim), pri(pri), rev(rev){};
};
vector<edge> nei[N];
char ss[105];
int hv[26];
int n, sl, s, t, cst, flw;
int d[N], f[N], p[N], v[N];
queue<int> q;
void add_edge(int x, int y, int l, int p) {
  nei[x].push_back(edge(y, l, p, int(nei[y].size())));
  nei[y].push_back(edge(x, 0, -p, int(nei[x].size()) - 1));
}
int spfa() {
  for (int i = s; i <= t; i++) {
    v[i] = 0;
    d[i] = f[i] = INF;
  }
  d[s] = 0, v[s] = 1;
  while (!q.empty()) q.pop();
  q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    v[x] = 0;
    for (int i = 0; i < nei[x].size(); i++) {
      int to = nei[x][i].to;
      int lim = nei[x][i].lim;
      int pri = nei[x][i].pri;
      int rev = nei[x][i].rev;
      if (lim == 0) continue;
      if (d[to] > d[x] + pri) {
        p[to] = rev;
        d[to] = d[x] + pri;
        f[to] = min(f[x], lim);
        if (!v[to]) {
          v[to] = 1;
          q.push(to);
        }
      }
    }
  }
  return d[t] != INF;
}
void mcmf() {
  while (spfa()) {
    flw += f[t];
    cst += d[t] * f[t];
    int x = t;
    while (x != s) {
      int r = p[x];
      int to = nei[x][r].to;
      int rev = nei[x][r].rev;
      nei[x][r].lim += f[t];
      nei[to][rev].lim -= f[t];
      x = to;
    }
  }
}
int main() {
  scanf("%s", &ss);
  sl = strlen(ss);
  int Sl = sl;
  for (int i = 0; i < sl; i++) hv[ss[i] - 'a']++;
  scanf("%d", &n);
  s = 1;
  t = n + 28;
  for (int i = 0; i < 26; i++)
    if (hv[i]) {
      add_edge(n + 2 + i, t, hv[i], 0);
      hv[i] = 0;
    }
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%s%d", ss, &x);
    sl = strlen(ss);
    for (int j = 0; j < sl; j++) hv[ss[j] - 'a']++;
    add_edge(s, i + 1, x, 0);
    for (int j = 0; j < 26; j++)
      if (hv[j]) {
        add_edge(i + 1, n + 2 + j, hv[j], i);
        hv[j] = 0;
      }
  }
  mcmf();
  if (Sl == flw)
    printf("%d\n", cst);
  else
    puts("-1");
  return 0;
}
