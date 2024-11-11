#include <bits/stdc++.h>
using namespace std;
int n, m;
bool debug = false;
int k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
class MinCostFlow {
 public:
  int V, E;
  int cap[6000];
  long long cost[6000], dist[2500], pot[2500];
  int to[6000], prev[6000], last[2500], path[2500];
  bool used[2500];
  MinCostFlow(int n) {
    V = n;
    E = 0;
    for (int(i) = 0; (i) < (int)(V); (i)++) last[i] = -1;
  }
  void add_edge(int x, int y, int w, long long c) {
    cap[E] = w;
    cost[E] = c;
    to[E] = y;
    prev[E] = last[x];
    last[x] = E;
    E++;
    cap[E] = 0;
    cost[E] = -c;
    to[E] = x;
    prev[E] = last[y];
    last[y] = E;
    E++;
  }
  pair<int, long long> search(int s, int t) {
    int ansf = 0;
    long long ansc = 0;
    int x;
    for (int(i) = 0; (i) < (int)(V); (i)++) used[i] = false;
    for (int(i) = 0; (i) < (int)(V); (i)++) dist[i] = (1LL << 60);
    dist[s] = 0;
    path[s] = -1;
    while (1) {
      x = -1;
      for (int(i) = 0; (i) < (int)(V); (i)++)
        if (dist[i] < (1LL << 60) && !used[i] && (x == -1 || dist[i] < dist[x]))
          x = i;
      if (x == -1) break;
      used[x] = true;
      for (int e = last[x]; e >= 0; e = prev[e])
        if (cap[e] > 0) {
          long long tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
          if (tmp < dist[to[e]] && !used[to[e]]) {
            dist[to[e]] = tmp;
            path[to[e]] = e;
          }
        }
    }
    for (int(i) = 0; (i) < (int)(V); (i)++) pot[i] += dist[i];
    if (used[t]) {
      ansf = (1 << 29);
      for (int e = path[t]; e >= 0; e = path[to[e ^ 1]])
        ansf = min(ansf, cap[e]);
      for (int e = path[t]; e >= 0; e = path[to[e ^ 1]]) {
        ansc += cost[e] * ansf;
        cap[e] -= ansf;
        cap[e ^ 1] += ansf;
      }
    }
    return make_pair(ansf, ansc);
  }
  void bellman(int s) {
    int e;
    for (int(i) = 0; (i) < (int)(V); (i)++) pot[i] = (1LL << 60);
    pot[s] = 0;
    for (int(i) = 0; (i) < (int)(V + 10); (i)++)
      for (int(x) = 0; (x) < (int)(V); (x)++)
        for (e = last[x]; e >= 0; e = prev[e])
          if (cap[e] > 0) pot[to[e]] = min(pot[to[e]], pot[x] + cost[e]);
  }
  pair<int, long long> mincostflow(int s, int t) {
    int ansf = 0;
    long long ansc = 0;
    bellman(s);
    while (1) {
      pair<int, long long> p = search(s, t);
      if (!used[t]) break;
      ansf += p.first;
      ansc += p.second;
    }
    return make_pair(ansf, ansc);
  }
};
long long s[1005], t[1005], c[1005];
long long id[1005 * 2];
map<long long, int> mp;
int main() {
  scanf("%d%d", &n, &k);
  long long mm = -1;
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    scanf("%lld%lld%lld", s + i, t + i, c + i);
    t[i] += s[i];
    mp[s[i]] = 0;
    mp[t[i]] = 0;
    mm = max(mm, c[i]);
  }
  int M = 0;
  for (auto &p : mp) {
    p.second = M;
    id[M] = p.first;
    M++;
  }
  MinCostFlow mcf(M + 1);
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    int a = mp[s[i]], b = mp[t[i]];
    mcf.add_edge(a, b, 1, mm * (id[b] - id[a]) - c[i]);
  }
  for (int(i) = 0; (i) < (int)(M - 1); (i)++)
    mcf.add_edge(i, i + 1, k, mm * (id[i + 1] - id[i]));
  mcf.add_edge(M, 0, k, 0);
  mcf.mincostflow(M, M - 1);
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    printf("%d ", mcf.cap[i * 2] == 0);
  }
  return 0;
}
