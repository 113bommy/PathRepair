#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int mv = 314000000, inf = 1000000000;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 101000;
int n, m, k, p;
int rp[N], d[N], ind[N], val[N], vad[N];
int dis[N], Dis[N], q[N], t;
priority_queue<pair<int, int> > hp;
vector<int> e[N], ev[N], rl[N], rr[N];
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; i++) {
    scanf("%d", rp + i);
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &p);
      if (p == -1)
        ++val[i];
      else {
        rl[i].push_back(p);
        ev[p].push_back(i);
      }
    }
    d[i] = ((int)(rl[i]).size());
  }
  for (int i = 1; i < n + 1; i++) dis[i] = inf;
  for (int i = 0; i < m; i++)
    if (d[i] == 0) hp.push(make_pair(-val[i], rp[i]));
  while (!hp.empty()) {
    int u = hp.top().second, v = -hp.top().first;
    hp.pop();
    if (dis[u] != inf) continue;
    dis[u] = v;
    for (int j = 0; j < ((int)(ev[u]).size()); j++) {
      v = ev[u][j];
      if (!(--d[v])) {
        int sm = val[v];
        for (int k = 0; k < ((int)(rl[v]).size()); k++)
          sm = min(mv, sm + dis[rl[v][k]]);
        hp.push(make_pair(-sm, rp[v]));
      }
    }
  }
  for (int i = 0; i < m; i++) {
    vad[i] = 1;
    for (int j = 0; j < ((int)(rl[i]).size()); j++)
      vad[i] &= (dis[rl[i][j]] != inf);
    if (vad[i]) {
      rr[rp[i]].push_back(i);
      for (int j = 0; j < ((int)(rl[i]).size()); j++) {
        e[rl[i][j]].push_back(rp[i]);
        ind[rp[i]]++;
      }
    }
  }
  for (int i = 1; i < n + 1; i++)
    if (ind[i] == 0) q[t++] = i;
  for (int i = 0; i < t; i++) {
    int u = q[i];
    for (int j = 0; j < ((int)(e[u]).size()); j++) {
      int v = e[u][j];
      if (!(--ind[v])) q[t++] = v;
    }
  }
  for (int i = 1; i < n + 1; i++) Dis[i] = -inf;
  for (int i = 0; i < t; i++) {
    int u = q[i];
    for (int j = 0; j < ((int)(rr[u]).size()); j++) {
      int v = rr[u][j];
      int sm = val[v];
      for (int k = 0; k < ((int)(rl[v]).size()); k++)
        sm = min(mv, sm + Dis[rl[v][k]]);
      Dis[u] = max(Dis[u], sm);
    }
  }
  for (int i = 1; i < n + 1; i++)
    if (dis[i] == inf)
      puts("-1 -1");
    else if (Dis[i] < 0)
      printf("%d -2\n", dis[i]);
    else
      printf("%d %d\n", Dis[i], dis[i]);
}
