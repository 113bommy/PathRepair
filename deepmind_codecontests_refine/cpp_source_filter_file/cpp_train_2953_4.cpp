#include <bits/stdc++.h>
using namespace std;
long long read() {
  char ch = ' ';
  long long x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x;
}
struct Node {
  long long num;
  vector<long long> tour;
  vector<long long> really;
  void init() {
    long long k = read();
    tour.resize(k);
    really.resize(k);
    for (int i = 0; i < k; i++) tour[i] = read();
    for (int i = k - 1; i >= 0; i--) {
      really[i] = (i == k - 1 || tour[i] != tour[i - 1] + 1) ? (tour[i] + 1)
                                                             : (really[i + 1]);
    }
  }
  long long time_to_go(long long arrive_time) {
    long long pos =
        lower_bound(tour.begin(), tour.end(), arrive_time) - tour.begin();
    long long temp = arrive_time;
    if (pos == tour.size())
      return temp;
    else if (tour[pos] != temp)
      return temp;
    else
      return really[pos];
    return temp;
  }
  bool operator<(const Node &A) const { return num < A.num; }
};
long long n, m;
vector<pair<long long, long long> > g[100005];
vector<Node> iton;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    q;
long long dis[100005];
void Dijkstra(long long s, vector<pair<long long, long long> > graph[],
              long long dist[]) {
  for (int i = 0; i < n; i++) dist[i] = 0x3f3f3f3f3f3f3f3fLL;
  dist[s] = 0;
  q.push(make_pair(iton[0].time_to_go(0), s));
  while (!q.empty()) {
    pair<long long, long long> t = q.top();
    q.pop();
    for (int i = 0; i < graph[t.second].size(); i++) {
      long long to = graph[t.second][i].second;
      long long di = graph[t.second][i].first;
      if (dist[to] > t.first + di) {
        dist[to] = t.first + di;
        q.push(make_pair(iton[to].time_to_go(dist[to]), to));
      }
    }
  }
}
void Init() {
  n = read(), m = read();
  for (int i = 0; i < m; i++) {
    long long x = read(), y = read(), z = read();
    x--, y--;
    g[x].push_back(make_pair(z, y));
    g[y].push_back(make_pair(z, x));
  }
  iton.resize(n);
  for (int i = 0; i < n; i++) {
    iton[i].num = i;
    iton[i].init();
  }
}
int main() {
  Init();
  Dijkstra(0, g, dis);
  printf("%I64d", dis[n - 1] < 0x3f3f3f3f3f3f3f3fLL ? dis[n - 1] : -1);
  return 0;
}
