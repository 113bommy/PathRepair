#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dblcmp(double d) {
  if (fabs(d) < eps) return 0;
  return d > eps ? 1 : -1;
}
const int inf = 2139062143;
const int maxn = 3400;
const int maxe = 501000;
struct graph {
  struct edge {
    int u, v, flow, cost, next;
  } a[maxe];
  int start[maxn], tot, n, m;
  int s, t, pre[maxe];
  void init() {
    memset(start, -1, sizeof(start));
    tot = 0;
  }
  void _addedge(int u, int v, int flow, int cost) {
    a[tot].u = u;
    a[tot].v = v;
    a[tot].flow = flow;
    a[tot].cost = cost;
    a[tot].next = start[u];
    start[u] = tot++;
  }
  void addedge(int u, int v, int flow, int cost) {
    _addedge(u, v, flow, cost);
    _addedge(v, u, 0, -cost);
  }
  int d[maxn];
  bool qu[maxn];
  int spfa() {
    int i, j, k, tmp;
    memset(d, 0x7f, sizeof(d));
    d[s] = 0;
    queue<int> q;
    q.push(s);
    pre[s] = -1;
    qu[s] = 1;
    while (!q.empty()) {
      tmp = q.front();
      q.pop();
      qu[tmp] = 0;
      for (i = start[tmp]; i != -1; i = a[i].next) {
        k = a[i].cost;
        j = a[i].v;
        if (a[i].flow && d[j] > d[tmp] + k) {
          d[j] = d[tmp] + k;
          if (!qu[j]) {
            q.push(j);
            qu[j] = 1;
          }
          pre[j] = i;
        }
      }
    }
    return d[t];
  }
  int ek(int rec) {
    int mi, i, j, k;
    int ans = 0, ansc = 0;
    while (1) {
      k = spfa();
      if (k == inf) break;
      mi = inf;
      for (i = t; i != s; i = a[pre[i] ^ 1].v) {
        mi = min(mi, a[pre[i]].flow);
      }
      ans += mi;
      ansc += mi * k;
      for (i = t; i != s; i = a[pre[i] ^ 1].v) {
        a[pre[i]].flow -= mi;
        a[pre[i] ^ 1].flow += mi;
      }
    }
    if (ans < rec) return -1;
    return ansc;
  }
} g;
string t, s[111];
int v[130], vv[111][130];
int main() {
  int i, j, k;
  g.init();
  cin >> t;
  memset((v), 0, sizeof(v));
  memset((vv), 0, sizeof(vv));
  for (i = 0; i < (int)((t).size()); i++) {
    v[t[i] - 'a' + 1]++;
  }
  g.s = 0;
  g.t = 3300;
  int sum = 0;
  for (i = 1; i <= 26; i++) {
    g.addedge(0, i, v[i], 0);
    sum += v[i];
  }
  int cc;
  cin >> cc;
  for (j = 0; j < cc; j++) {
    cin >> t;
    for (i = 0; i < (int)((t).size()); i++) {
      vv[j][t[i] - 'a' + 1]++;
    }
    cin >> k;
    g.addedge(2800 + j, g.t, k, 0);
    for (i = 1; i <= 26; i++) {
      g.addedge(100 + 26 * j + i, 2800 + j, vv[j][i], 0);
    }
  }
  for (i = 1; i <= 26; i++) {
    for (j = 0; j < cc; j++) {
      if (v[i] && vv[j][i]) {
        g.addedge(i, 100 + 26 * j + i, inf, j + 1);
      }
    }
  }
  cout << g.ek(sum) << endl;
  return 0;
}
