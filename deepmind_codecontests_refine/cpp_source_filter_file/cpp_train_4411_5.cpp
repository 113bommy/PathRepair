#include <bits/stdc++.h>
using namespace std;
struct pt {
  int n;
  long long t;
} z, c;
struct cmp {
  bool operator()(pt x, pt y) { return x.t > y.t; };
};
priority_queue<pt, vector<pt>, cmp> q;
struct ed {
  int t, n;
  long long w;
} e[200010];
int n, m, k, l, h[100010];
bool v[100010];
long long w, d[100010];
vector<long long> t[100010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%I64d", &k, &l, &w);
    e[i * 2 + 1].t = l;
    e[i * 2 + 1].w = w;
    e[i * 2 + 1].n = h[k];
    h[k] = i * 2 + 1;
    e[i * 2 + 2].t = l;
    e[i * 2 + 2].w = w;
    e[i * 2 + 2].n = h[k];
    h[k] = i * 2 + 2;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%I64d", &w);
      t[i + 1].push_back(w);
    }
  }
  for (int i = 1; i <= n; i++) d[i] = 1e13;
  d[1] = 0;
  z.n = 1;
  z.t = 0;
  q.push(z);
  while (!q.empty()) {
    c = q.top();
    q.pop();
    if (c.t != d[c.n]) continue;
    for (int i = 0; i < t[c.n].size() && c.t >= t[c.n][i]; i++) {
      if (c.t == t[c.n][i]) c.t++;
    }
    for (int i = h[c.n]; i != 0; i = e[i].n) {
      if (d[e[i].t] > c.t + e[i].w) {
        d[e[i].t] = c.t + e[i].w;
        z.t = d[e[i].t];
        z.n = e[i].t;
        q.push(z);
      }
    }
  }
  if (d[n] == 1e13)
    printf("-1\n");
  else
    printf("%I64d\n", d[n]);
  return 0;
}
