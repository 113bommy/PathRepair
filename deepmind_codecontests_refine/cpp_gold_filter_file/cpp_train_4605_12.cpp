#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct edge {
  int t, nxt, f, c;
} e[5010];
int n, m, Q, u, v, w, be[55], cnt, sz, fv[2510], fl[2510], dis[55], iq[55],
    ls[55], fe[55], t, lf;
double l, r, mid;
long long sv[2510];
queue<int> q;
void add(const int& x, const int& y, const int& fl, const int& cs) {
  e[++cnt] = (edge){y, be[x], fl, cs}, be[x] = cnt;
}
bool SPFA() {
  for (int i = 2; i <= n; ++i) dis[i] = INF;
  q.push(1), iq[1] = 1;
  while (!q.empty()) {
    iq[t = q.front()] = 0, q.pop();
    for (int i = be[t]; i; i = e[i].nxt)
      if (e[i].f && dis[e[i].t] > dis[t] + e[i].c) {
        dis[e[i].t] = dis[t] + e[i].c, ls[e[i].t] = t, fe[e[i].t] = i;
        if (!iq[e[i].t]) q.push(e[i].t), iq[e[i].t] = 1;
      }
  }
  if (dis[n] >= INF) return false;
  t = 0, lf = INF;
  for (int i = n; i != 1; i = ls[i]) lf = min(lf, e[fe[i]].f);
  for (int i = n; i != 1; i = ls[i])
    e[fe[i]].f -= lf, e[(fe[i] & 1 ? fe[i] + 1 : fe[i] - 1)].f += lf,
        t += e[fe[i]].c;
  if (!sz || fv[sz] != t)
    fv[++sz] = t, sv[sz] = sv[sz - 1] + lf * t, fl[sz] = fl[sz - 1] + lf;
  else
    sv[sz] += lf * t, fl[sz] += lf;
  return true;
}
bool Check(double x) {
  int tl = 1, tr = sz, tm;
  while (tl < tr) tm = tl + tr + 1 >> 1, fv[tm] < x ? tl = tm : tr = tm - 1;
  return fl[tl] * x - sv[tl] <= w;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d%d%d", &u, &v, &w), add(u, v, 1, w), add(v, u, 0, -w);
  while (SPFA())
    ;
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &w);
    l = 1, r = 1e26;
    while (r - l > 1e-7) mid = (l + r) / 2.0, Check(mid) ? l = mid : r = mid;
    printf("%.10lf\n", l);
  }
  return 0;
}
