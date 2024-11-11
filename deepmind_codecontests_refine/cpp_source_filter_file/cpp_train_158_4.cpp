#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void maximize(T &x, U y) {
  if (x < y) x = y;
}
template <class T, class U>
void minimize(T &x, U y) {
  if (x > y) x = y;
}
template <class T>
T Abs(T x) {
  return (x < 0 ? -x : x);
}
template <class T>
T safe_sqrt(T x) {
  return sqrt(max(x, (T)0));
}
template <class T, class U, class V>
T addmod(T x, U k, V MOD) {
  return ((x + k) % MOD + MOD) % MOD;
}
template <class T, class U, class V>
T submod(T x, U k, V MOD) {
  return ((x - k) % MOD + MOD) % MOD;
}
template <class T, class U, class V>
T mul(T x, U y, V MOD) {
  return (long long)x * y % MOD;
}
namespace task {
const long long inf = 1e18;
const int N = 1e3 + 3;
vector<pair<int, int> > adj[N];
struct E {
  int u, v, w;
  E() {}
  E(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
} edge[10 * N];
int n, m, L, s, t;
long long dist[2][N];
bool mark[N];
void print() {
  puts("YES");
  for (int i = 1; i <= m; ++i)
    printf("%d %d %d\n", edge[i].u - 1, edge[i].v - 1, edge[i].w);
}
void dijkstra1() {
  priority_queue<pair<long long, int> > heap;
  fill(dist[0] + 1, dist[0] + 1 + n, inf);
  dist[0][t] = 0;
  heap.push(make_pair(dist[0][t], t));
  while (!heap.empty()) {
    pair<long long, int> top = heap.top();
    heap.pop();
    int u = top.second;
    if (dist[0][u] != -top.first) continue;
    for (auto e : adj[u])
      if (dist[0][u] + edge[e.second].w < dist[0][e.first])
        dist[0][e.first] = dist[0][u] + edge[e.second].w,
        heap.push(make_pair(-dist[0][e.first], e.first));
  }
}
void dijkstra2() {
  priority_queue<pair<long long, int> > heap;
  fill(dist[1] + 1, dist[1] + 1 + n, inf);
  dist[1][s] = 0;
  heap.push(make_pair(dist[1][s], s));
  while (!heap.empty()) {
    pair<long long, int> top = heap.top();
    heap.pop();
    int u = top.second;
    if (dist[1][u] != -top.first) continue;
    for (auto e : adj[u])
      if (dist[1][u] + edge[e.second].w < dist[1][e.first] and
          dist[1][u] + edge[e.second].w + dist[0][e.first] < L) {
        if (mark[e.second])
          edge[e.second].w +=
              L - (dist[1][u] + edge[e.second].w + dist[0][e.first]);
        else {
          dist[1][e.first] = dist[1][u] + edge[e.second].w;
          heap.push(make_pair(-dist[1][e.first], e.first));
        }
      }
  }
}
void solve() {
  scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
  ++s, ++t;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    ++edge[i].u, ++edge[i].v;
    if (!edge[i].w) edge[i].w = 1, mark[i] = true;
    adj[edge[i].u].push_back(make_pair(edge[i].v, i));
    adj[edge[i].v].push_back(make_pair(edge[i].u, i));
  }
  dijkstra1();
  if (dist[0][s] > L) puts("NO"), exit(0);
  if (dist[0][s] == L) print(), exit(0);
  dijkstra2();
  if (dist[1][t] == inf)
    print();
  else
    puts("NO");
}
}  // namespace task
int main(void) { task::solve(); }
