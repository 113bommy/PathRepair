#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
void fastio() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  long long r = exgcd(b, a % b, x, y);
  long long te = y;
  y = x - (a / b) * y;
  x = te;
  return r;
}
long long qpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % m;
    b >>= 1;
    a = a * a % m;
  }
  return ans;
}
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    b >>= 1;
    a = a * a;
  }
  return ans;
}
long long jiecheng(long long a) {
  if (a == 0) return 1;
  return a * jiecheng(a - 1);
}
struct edge {
  long long to, cost;
};
long long v;
vector<edge> G[N];
long long d[N];
long long sx, sy, fx, fy;
struct Pai {
  long long x, y, Index;
} pai[N];
bool cmp1(Pai a, Pai b) {
  if (a.x == b.x)
    return a.y < b.y;
  else
    return a.x < b.x;
}
bool cmp2(Pai a, Pai b) {
  if (a.y == b.y)
    return a.x < b.x;
  else
    return a.y < b.y;
}
void dijkstra(long long s) {
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      que;
  fill(d, d + v, INF);
  d[s] = 0;
  que.push(pair<long long, long long>(0, s));
  while (que.size()) {
    pair<long long, long long> P = que.top();
    que.pop();
    long long w = P.second;
    if (d[w] < P.first) continue;
    for (long long i = 0; i < G[w].size(); ++i) {
      edge e = G[w][i];
      if (d[e.to] > e.cost + d[w]) {
        d[e.to] = e.cost + d[w];
        que.push(pair<long long, long long>(d[e.to], e.to));
      }
    }
  }
}
signed main() {
  fastio();
  long long n, m;
  cin >> n >> m;
  cin >> sx >> sy >> fx >> fy;
  for (long long i = 1; i <= m; ++i) {
    cin >> pai[i].x >> pai[i].y;
    pai[i].Index = i;
  }
  sort(pai + 1, pai + m + 1, cmp1);
  for (long long i = 1; i < m; ++i) {
    long long dis = abs(pai[i].x - pai[i + 1].x);
    G[pai[i].Index].push_back({pai[i + 1].Index, dis});
    G[pai[i + 1].Index].push_back({pai[i].Index, dis});
  }
  sort(pai + 1, pai + m + 1, cmp2);
  for (long long i = 1; i < m; ++i) {
    long long dis = abs(pai[i].y - pai[i + 1].y);
    G[pai[i].Index].push_back({pai[i + 1].Index, dis});
    G[pai[i + 1].Index].push_back({pai[i].Index, dis});
  }
  for (long long i = 1; i <= m; ++i) {
    long long dis = abs(pai[i].x - fx) + abs(pai[i].y - fy);
    long long dis2 = min(abs(pai[i].x - sx), abs(pai[i].y - sy));
    G[pai[i].Index].push_back({m + 1, dis});
    G[0].push_back({pai[i].Index, dis2});
  }
  G[0].push_back({m + 1, abs(sx - fx) + abs(sy - fy)});
  v = m + 2;
  dijkstra(0);
  cout << d[m + 1] << '\n';
  return 0;
}
