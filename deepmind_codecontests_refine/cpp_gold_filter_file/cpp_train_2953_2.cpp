#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e) {
  cout << e << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
long long Pow(long long B, long long P) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) R = (R * B);
    P /= 2;
    B = (B * B);
  }
  return R;
}
long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return R;
}
long long n;
long long dist[100050];
set<long long> S[100050];
struct data {
  long long to, w;
  data(int a, int b) {
    to = a;
    w = b;
  }
};
vector<data> v[100050];
struct vertice {
  long long node, dist;
  vertice(int a, int b) {
    node = a;
    dist = b;
  }
  bool operator<(const vertice& x) const { return dist > x.dist; }
};
long long dijkstra(int source) {
  for (int i = 0; i <= n; i++) dist[i] = (1LL << 50);
  dist[source] = 0;
  priority_queue<vertice> Q;
  Q.push(vertice(source, 0));
  while (!Q.empty()) {
    long long now = Q.top().node, cost = Q.top().dist;
    Q.pop();
    if (now == n) return cost;
    while (S[now].find(cost) != S[now].end()) cost++;
    for (int i = 0; i < (int)v[now].size(); i++) {
      long long to = v[now][i].to;
      long long w = v[now][i].w;
      if (dist[to] > cost + w) {
        dist[to] = cost + w;
        Q.push(vertice(to, cost + w));
      }
    }
  }
  return -1;
}
int main() {
  long long m, a, b, c;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    v[a].push_back(data(b, c));
    v[b].push_back(data(a, c));
  }
  for (int i = 1; i <= n; i++) {
    cin >> c;
    while (c--) {
      cin >> a;
      S[i].insert(a);
    }
  }
  long long ans = dijkstra(1);
  cout << ans << endl;
  return 0;
}
