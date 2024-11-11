#include <bits/stdc++.h>
using namespace std;
const int MAXV = 100001, MAXE = 100001;
const long long mod1 = 2860486313;
const long long mod2 = 1500450271;
int s[MAXE];
int t[MAXE];
long long w[MAXE];
int nxt[MAXE];
int rnxt[MAXE];
int head[MAXV];
int rhead[MAXV];
int len = 1;
long long diss[MAXV];
long long dist[MAXV];
long long cnts[MAXV];
long long cntt[MAXV];
int V, E;
int S, T;
void add_edge(int u, int v, long long w_) {
  s[len] = u;
  t[len] = v;
  w[len] = w_;
  nxt[len] = head[u];
  rnxt[len] = rhead[v];
  head[u] = len;
  rhead[v] = len;
  len++;
}
void dijkstra(int *to, int *nxt, int *head, long long *dis, long long *cnt,
              int s, long long mod) {
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  memset(dis, 0x3f, (V + 1) * sizeof(long long));
  dis[s] = 0;
  cnt[s] = 1;
  q.push(pair<long long, int>(0, s));
  while (!q.empty()) {
    pair<long long, int> p = q.top();
    q.pop();
    int v = p.second;
    if (dis[v] < p.first) continue;
    for (int i = head[v]; i != 0; i = nxt[i]) {
      int u = to[i];
      if (dis[u] == dis[v] + w[i])
        cnt[u] = (cnt[v] + cnt[u]) % mod;
      else if (dis[u] > dis[v] + w[i]) {
        cnt[u] = cnt[v];
        dis[u] = dis[v] + w[i];
        q.push(pair<long long, int>(dis[u], u));
      }
    }
  }
}
int main() {
  scanf("%d%d%d%d", &V, &E, &S, &T);
  for (int i = 0; i < E; i++) {
    int u, v;
    long long w_;
    scanf("%d%d%lld", &u, &v, &w_);
    add_edge(u, v, w_);
  }
  dijkstra(t, nxt, head, diss, cnts, S, mod1);
  dijkstra(s, rnxt, rhead, dist, cntt, T, mod1);
  for (int i = 1; i <= E; i++) {
    if (diss[s[i]] + w[i] + dist[t[i]] == diss[T] &&
        cnts[s[i]] * cntt[t[i]] % mod1 == cnts[T])
      printf("YES\n");
    else {
      long long goal = diss[T];
      long long crt = diss[s[i]] + w[i] + dist[t[i]];
      if (crt - goal + 1 < w[i])
        printf("CAN %lld\n", crt - goal + 1);
      else
        printf("NO\n");
    }
  }
  return 0;
}
