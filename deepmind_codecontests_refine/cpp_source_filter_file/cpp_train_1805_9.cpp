#include <bits/stdc++.h>
using namespace std;
inline int add(int a, int b, int m = 1000000007) {
  a += b;
  if (a >= m) a -= m;
  return a;
}
inline int mul(int a, int b, int m = 1000000007) {
  return (int)(((long long)a * (long long)b) % m);
}
inline int neg(int x, int m = 1000000007) {
  x = -x;
  return norm(x);
}
inline int norm(int x, int m = 1000000007) {
  if (x >= m) x %= m;
  if (x < 0) x += m;
  return x;
}
int V, E;
int cap[10000], flow[10000];
long long cost[10000], dist[3000], pot[3000];
int to[10000], prv[10000], last[3000], path[3000];
bool used[3000];
priority_queue<pair<long long, int> > q;
class MinCostFlow {
 public:
  MinCostFlow(int n) {
    V = n;
    E = 0;
    int i;
    for ((i) = 0; (i) < (int)(V); (i)++) last[i] = -1;
  }
  void add_edge(int x, int y, int w, long long c) {
    cap[E] = w;
    flow[E] = 0;
    cost[E] = c;
    to[E] = y;
    prv[E] = last[x];
    last[x] = E;
    E++;
    cap[E] = 0;
    flow[E] = 0;
    cost[E] = -c;
    to[E] = x;
    prv[E] = last[y];
    last[y] = E;
    E++;
  }
  pair<int, long long> search(int s, int t) {
    int ansf = 0;
    long long ansc = 0;
    int i;
    for ((i) = 0; (i) < (int)(V); (i)++) used[i] = false;
    for ((i) = 0; (i) < (int)(V); (i)++) dist[i] = (1ll << 60);
    dist[s] = 0;
    path[s] = -1;
    q.push(make_pair(0, s));
    while (!q.empty()) {
      int x = q.top().second;
      q.pop();
      if (used[x]) continue;
      used[x] = true;
      for (int e = last[x]; e >= 0; e = prv[e])
        if (cap[e] > 0) {
          long long tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
          if (tmp < dist[to[e]] && !used[to[e]]) {
            dist[to[e]] = tmp;
            path[to[e]] = e;
            q.push(make_pair(-dist[to[e]], to[e]));
          }
        }
    }
    for ((i) = 0; (i) < (int)(V); (i)++) pot[i] += dist[i];
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
  pair<int, long long> mincostflow(int s, int t) {
    int ansf = 0;
    long long ansc = 0;
    int i;
    for ((i) = 0; (i) < (int)(V); (i)++) pot[i] = 0;
    while (1) {
      pair<int, long long> p = search(s, t);
      if (!used[t]) break;
      ansf += p.first;
      ansc += p.second;
    }
    return make_pair(ansf, ansc);
  }
};
int s[1001], t[1001], c[1001];
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= n - 1; ++i) {
    cin >> s[i] >> t[i] >> c[i];
    t[i] += s[i];
    v.push_back(s[i]);
    v.push_back(t[i]);
  }
  v.push_back(0);
  v.push_back(1000000007);
  sort(((v)).begin(), ((v)).end());
  (v).erase(unique(((v)).begin(), ((v)).end()), (v).end());
  MinCostFlow rng(int((v).size()));
  long long X = 10010;
  for (int i = 0; i <= n - 1; ++i) {
    int uu = lower_bound((v).begin(), (v).end(), s[i]) - v.begin();
    int vv = lower_bound((v).begin(), (v).end(), t[i]) - v.begin();
    rng.add_edge(uu, vv, 1, (vv - uu) * X - c[i]);
  }
  for (int i = 1; i <= int((v).size()) - 1; ++i) rng.add_edge(i - 1, i, k, X);
  pair<int, long long> x = rng.mincostflow(0, int((v).size()) - 1);
  for (int i = 0; i <= n - 1; ++i) {
    int ans = 0;
    if (cap[2 * i] == 0) ans = 1;
    cout << ans << " ";
  }
  return 0;
}
