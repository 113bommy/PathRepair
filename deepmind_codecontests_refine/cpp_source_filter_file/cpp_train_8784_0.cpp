#include <bits/stdc++.h>
using namespace std;
int h, n, m, k, cntj, val[100005];
long long a[100005], dist[10005], jump[25];
bool tk[100005];
priority_queue<pair<int, int> > vq;
void dijkstra() {
  priority_queue<pair<long long, int> > pq;
  fill(dist, dist + k, LLONG_MAX);
  pq.push(make_pair(0, 0));
  dist[0] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    long long cost = -pq.top().first;
    pq.pop();
    if (dist[u] < cost) continue;
    for (int i = 0; i < cntj; i++) {
      int v = ((long long)u + jump[i]) % k;
      if (cost + jump[i] < dist[v]) {
        dist[v] = cost + jump[i];
        pq.push(make_pair(-dist[v], v));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!tk[i]) {
      int v = a[i] % k;
      if (dist[v] <= a[i]) {
        tk[i] = true;
        vq.push(make_pair(val[i], -i));
      }
    }
  }
}
void dec(int x, int y) {
  val[x] -= y;
  if (tk[x]) vq.push(make_pair(val[x], -x));
}
int maxval() {
  while (!vq.empty()) {
    int u = -vq.top().second, v = vq.top().first;
    vq.pop();
    if (val[u] == v) {
      val[u] = 0;
      tk[u] = false;
      return v;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> h >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> val[i];
    a[i]--;
  }
  dijkstra();
  while (m--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      long long x;
      cin >> x;
      jump[cntj++] = x;
      dijkstra();
    } else if (opt == 2) {
      int x, y;
      cin >> x >> y;
      dec(--x, y);
    } else {
      cout << maxval() << endl;
    }
  }
  return 0;
}
