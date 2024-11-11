#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int maxn = 3e5 + 10;
const long long MOD = 1000000007;
const double EPS = 1e-10;
const double Pi = acos(-1.0);
struct edge {
  long long to, cost;
};
struct P {
  long long first, second, z;
  P(long long a = 0, long long b = 0, long long c = 0)
      : first(a), second(b), z(c) {}
  bool operator<(const P &rhs) const { return first > rhs.first; }
};
int V;
vector<edge> G[maxn];
long long d[maxn], d2[maxn], cnt1[maxn], cnt2[maxn], vis[maxn][2];
void dij(int s) {
  priority_queue<P> que;
  fill(d, d + V + 1, 0x3f3f3f3f);
  fill(d2, d2 + V + 1, 0x3f3f3f3f);
  d[s] = 0;
  cnt1[s] = 1;
  que.push(P(0, s, 0));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    long long v = p.second, z = p.z;
    if (d2[v] < p.first || vis[v][z]) continue;
    vis[v][z] = 1;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      long long temp = p.first + e.cost;
      if (d[e.to] > temp) {
        d2[e.to] = d[e.to];
        d[e.to] = temp;
        cnt2[e.to] = cnt1[e.to];
        cnt1[e.to] = z == 0 ? cnt1[v] : cnt2[v];
        que.push(P(d[e.to], e.to, 0));
        que.push(P(d2[e.to], e.to, 1));
      } else if (d[e.to] == temp)
        cnt1[e.to] += z == 0 ? cnt1[v] : cnt2[v];
      else if (temp < d2[e.to]) {
        d2[e.to] = temp;
        cnt2[e.to] = z == 0 ? cnt1[v] : cnt2[v];
        que.push(P(d2[e.to], e.to, 1));
      } else if (temp == d2[e.to])
        cnt2[e.to] += z == 0 ? cnt1[v] : cnt2[v];
      cnt1[e.to] %= 10000000;
      cnt2[e.to] %= 10000000;
    }
  }
}
edge train[maxn];
int main() {
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    for (int i = 0; i <= n; i++) G[i].clear();
    V = n;
    for (int i = 0; i < m; i++) {
      int a, b, l;
      scanf("%d%d%d", &a, &b, &l);
      G[a].push_back(edge{b, l});
      G[b].push_back(edge{a, l});
    }
    for (int i = 0; i < k; i++) {
      int a, l;
      scanf("%d%d", &a, &l);
      G[a].push_back(edge{1, l});
      G[1].push_back(edge{a, l});
      train[i].to = a;
      train[i].cost = l;
    }
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    memset(vis, 0, sizeof vis);
    dij(1);
    int ans = 0;
    for (int i = 0; i < k; i++) {
      if (train[i].cost > d[train[i].to])
        ans++;
      else {
        if (train[i].cost == d[train[i].to] && cnt1[train[i].to] >= 2)
          ans++, cnt1[train[i].to]--;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
