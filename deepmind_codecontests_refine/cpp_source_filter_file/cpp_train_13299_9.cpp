#include <bits/stdc++.h>
using std::map;
using std::priority_queue;
const int KV2 = 56, S = 32000000;
map<long long, int> mi;
int mar;
long long pr[2333333], pi;
bool vis[S + 1];
void sieve() {
  for (long long i = 2; i <= S; i++) {
    if (!vis[i]) pr[++pi] = i;
    for (int j = 1; j <= pi && pr[j] * i <= S; j++) {
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    }
  }
}
struct sumireko {
  int to, ne;
  long long w;
} e[4000069];
int he[100069], ecnt;
void addline(int f, long long lt, long long w) {
  int t = lt;
  e[++ecnt].to = t;
  e[ecnt].ne = he[f];
  e[ecnt].w = w;
  he[f] = ecnt;
}
struct shion {
  int x;
  long long d;
  shion() {}
  shion(int x, long long d) : x(x), d(d) {}
  bool operator<(const shion &b) const { return d < b.d; }
} g;
long long dis[KV2][100069];
priority_queue<shion> q;
bool vv[100069];
void dijkstra(int ki) {
  memset(dis[ki], 0x7f, sizeof(dis[ki]));
  dis[ki][0] = 0;
  q.push(shion(0, 0));
  while (!q.empty()) {
    g = q.top(), q.pop();
    int px = g.x;
    long long pd = g.d;
    if (vv[px]) continue;
    vv[px] = 1;
    for (int i = he[px], t = e[i].to; i; i = e[i].ne, t = e[i].to) {
      if (pd + e[i].w < dis[ki][t]) {
        dis[ki][t] = pd + e[i].w;
        q.push(shion(t, dis[ki][t]));
      }
    }
  }
}
long long pl[KV2][68], pc[KV2];
void div(long long k, int ki) {
  int ti = 0;
  for (int i = 1; i <= pi && pr[i] * pr[i] <= k; i++) {
    if (k % pr[i] == 0) pl[ki][++ti] = pr[i];
    while (k % pr[i] == 0) k /= pr[i];
  }
  if (k != 1ll) pl[ki][++ti] = k;
  if (ti >= 3) {
    long long p1 = pl[ki][1];
    memset(he, 0, sizeof(he)), ecnt = 0;
    memset(vv, 0, sizeof(vv));
    for (int x = 0; x < p1; x++)
      for (int j = 1; j <= ti; j++) addline(x, (pl[ki][j] + x) % p1, pl[ki][j]);
    dijkstra(ki);
  }
  pc[ki] = ti;
}
long long fpow(long long a, long long p, long long mo) {
  a %= mo;
  long long ret = 1;
  while (p) {
    if (p & 1ll) ret = ret * a % mo;
    a = a * a % mo;
    p >>= 1;
  }
  return ret;
}
long long n, k;
int T;
int main() {
  sieve();
  scanf("%d", &T);
  while (T--) {
    scanf("%I64d%I64d", &n, &k);
    if (k == 1) {
      puts("NO");
      continue;
    }
    if (mi.find(k) == mi.end()) {
      mi[k] = ++mar;
      div(k, mar);
    }
    int ki = mi[k];
    switch (pc[ki]) {
      case 1: {
        puts(n % pl[ki][1] ? "NO" : "YES");
        break;
      }
      case 2: {
        long long p1 = pl[ki][1], p2 = pl[ki][2];
        puts(fpow(p2, p1 - 2, p1) * (n % p1) % p1 * p2 <= n ? "YES" : "NO");
        break;
      }
      default: {
        n < pl[ki][1]
            ? (puts("NO"))
            : (dis[ki][n % pl[ki][1]] <= n ? puts("YES") : puts("NO"));
        break;
      }
    }
  }
  return 0;
}
