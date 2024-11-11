#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long inf = (long long)2e18;
int ed, T, ans[10005], fir[N];
long long que[66], dis[N];
struct Edge {
  int v, nxt;
  long long w;
} e[N * 66];
struct Info {
  long long n, k;
  int id;
  bool operator<(const Info& x) const { return k < x.k; }
} qry[10005];
void adde(int x, int y, long long z) {
  e[++ed].v = y;
  e[ed].w = z;
  e[ed].nxt = fir[x];
  fir[x] = ed;
}
namespace Prim {
const int maxn = 31700000;
int np, p[maxn / 10];
bool vis[maxn];
void init() {
  int i, j;
  for (i = 2; i < maxn; ++i) {
    if (!vis[i]) p[++np] = i;
    for (j = 1; j <= np && i * p[j] < maxn; ++j) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}
int cut(long long n, long long* q) {
  int i, t = 0;
  for (i = 1; i <= np && p[i] <= n; ++i)
    if (n % p[i] == 0) {
      for (; n % p[i] == 0; n /= p[i])
        ;
      q[++t] = p[i];
    }
  if (n != 1) q[++t] = n;
  return t;
}
}  // namespace Prim
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (!b) return x = 1, y = 0, a;
  long long d = exgcd(b, a % b, y, x);
  return y -= a / b * x, d;
}
int solve2(long long a, long long b, long long n) {
  assert(a > 1 && b > 1);
  long long x, y;
  long long d = exgcd(a, b, x, y);
  if (n % d) return 0;
  a /= d;
  b /= d;
  n /= d;
  x = (x % b * (n % b) + b) % b;
  y = (n - a * x) / b;
  return y >= 0;
}
struct P {
  long long d;
  int x;
  P() {}
  P(long long _d, int _x) { d = _d, x = _x; }
  bool operator<(const P& t) const { return d > t.d; }
};
priority_queue<P> Q;
void dijkstra(int n) {
  int i;
  for (; Q.size(); Q.pop())
    ;
  for (i = 1; i < n; ++i) dis[i] = inf;
  Q.push(P(0, 0));
  for (; Q.size();) {
    P t = Q.top();
    Q.pop();
    if (dis[t.x] < t.d) continue;
    for (i = fir[t.x]; i; i = e[i].nxt)
      if (dis[e[i].v] > dis[t.x] + e[i].w) {
        Q.push(P(dis[e[i].v] = dis[t.x] + e[i].w, e[i].v));
      }
  }
}
int main() {
  int i, j;
  Prim::init();
  scanf("%d", &T);
  for (i = 1; i <= T; ++i)
    scanf("%I64d%I64d", &qry[i].n, &qry[i].k), qry[i].id = i;
  sort(qry + 1, qry + 1 + T);
  int l, r;
  for (l = 1; l <= T; l = r) {
    for (r = l; r <= T && qry[r].k == qry[l].k; ++r)
      ;
    int cnt = Prim::cut(qry[l].k, que);
    if (cnt == 1)
      for (i = l; i < r; ++i) ans[qry[i].id] = qry[i].n % que[1] == 0;
    if (cnt == 2)
      for (i = l; i < r; ++i) ans[qry[i].id] = solve2(que[1], que[2], qry[i].n);
    if (cnt >= 3) {
      assert(que[1] < 100000);
      for (ed = i = 0; i < que[1]; ++i) fir[i] = 0;
      for (i = 0; i < que[1]; ++i) {
        for (j = 2; j <= cnt; ++j) {
          adde(i, (i + que[j]) % que[1], que[j]);
        }
      }
      dijkstra(que[1]);
      for (i = l; i < r; ++i)
        ans[qry[i].id] = dis[qry[i].n % que[1]] <= qry[i].n;
    }
  }
  for (i = 1; i <= T; ++i) printf("%s\n", ans[i] ? "YES" : "NO");
  return 0;
}
