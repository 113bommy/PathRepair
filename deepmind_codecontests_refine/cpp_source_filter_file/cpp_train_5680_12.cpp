#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e9 + 7;
const int N = 200;
struct edge {
  int a, b;
  long long w, f, c;
  edge() {}
  edge(int a, int b, long long w, long long f, long long c)
      : a(a), b(b), w(w), f(f), c(c) {}
};
int n, m, s, t;
int f_n[N];
vector<edge> e;
vector<int> ed[N];
long long d[N];
long long en[N];
long long g[N];
void make_edge(int a, int b, long long c, long long w) {
  edge x = edge(a, b, w, 0, c);
  ed[a].push_back(e.size());
  e.push_back(x);
  swap(x.a, x.b);
  x.c = 0;
  x.w = -x.w;
  ed[b].push_back(e.size());
  e.push_back(x);
}
long long flow(int k) {
  long long nowc = 0;
  for (; k > 0;) {
    fill(d, d + t + 1, inf);
    fill(g, g + t + 1, -1);
    d[s] = 0;
    fill(en, en + t + 1, 0);
    queue<int> q;
    q.push(s);
    en[s] = 1;
    for (; !q.empty(); q.pop()) {
      int x = q.front();
      en[x] = 0;
      for (int &to : ed[x]) {
        int u = e[to].b;
        long long w = e[to].w;
        long long fr = e[to].c - e[to].f;
        if (fr == 0) continue;
        if (d[u] > d[x] + w) {
          d[u] = d[x] + w;
          g[u] = to;
          if (!en[u]) q.push(u), en[u] = 1;
        }
      }
    }
    int now = t;
    long long mn = k;
    for (; now != s;) {
      int to = g[now];
      mn = min(mn, e[to].c - e[to].f);
      now = e[to].a;
    }
    nowc += d[t] * mn;
    now = t;
    for (; now != s;) {
      int to = g[now];
      e[to].f += mn;
      e[to ^ 1].f -= mn;
      now = e[to].a;
    }
    k -= mn;
  }
  return nowc;
}
int main() {
  scanf("%d%d", &n, &m);
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, c, f;
    scanf("%d%d%d", &u, &v, &c, &f);
    --u, --v;
    f_n[u] -= f, f_n[v] += f;
    if (f <= c) {
      make_edge(u, v, c - f, 1);
      make_edge(u, v, inf, 2);
      make_edge(v, u, f, 1);
    } else {
      ans += f - c;
      make_edge(u, v, inf, 2);
      make_edge(v, u, f - c, 0);
      make_edge(v, u, c, 1);
    }
  }
  long long red = 0;
  s = n;
  t = n + 1;
  for (int i = 1; i < n - 1; ++i) {
    red += abs(f_n[i]);
    if (f_n[i] < 0) {
      make_edge(i, t, -f_n[i], -inf);
    } else {
      make_edge(s, i, f_n[i], -inf);
    }
  }
  make_edge(s, 0, inf, 0);
  make_edge(s, n - 1, inf, 0);
  make_edge(0, t, inf, 0);
  make_edge(n - 1, t, inf, 0);
  cout << ans + red * inf + flow(red);
  return 0;
}
