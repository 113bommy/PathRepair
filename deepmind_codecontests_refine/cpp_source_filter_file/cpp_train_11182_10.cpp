#include <bits/stdc++.h>
using namespace std;
const int size = 5007;
const long long modulo = 1000000007;
const long long INF = 1e9;
const double EPS = 1e-10;
int parent[size], rang[size];
long long sum_dist[size];
bool isLeader[size];
int regions;
void make_set(int n) {
  parent[n] = n;
  rang[n] = 0;
  sum_dist[n] = 0LL;
  isLeader[n] = true;
}
int find_set(int v) {
  if (parent[v] == v)
    return v;
  else
    return parent[v] = find_set(parent[v]);
}
void unite_sets(int a, int b, long long road) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rang[a] < rang[b]) swap(a, b);
    parent[b] = a;
    isLeader[b] = false;
    sum_dist[a] = sum_dist[a] + sum_dist[b] + road;
    --regions;
    if (rang[a] == rang[b]) ++rang[a];
  } else
    sum_dist[a] += road;
}
int main() {
  int n, m, p, q;
  cin >> n >> m >> p >> q;
  regions = n;
  for (int i = 0; i < n; i++) make_set(i);
  pair<int, int> edge;
  for (int i = 0; i < m; i++) {
    cin >> edge.first >> edge.second;
    --edge.second;
    --edge.first;
    long long road;
    cin >> road;
    unite_sets(edge.first, edge.second, road);
  }
  if ((regions < q) || (regions - p > q) || (m == 0 && p > 0 && q == n)) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      heap;
  for (int i = 0; i < n; i++) {
    if (isLeader[i]) heap.push(make_pair(sum_dist[i], i));
  }
  while (p > 0 && regions > q) {
    pair<long long, int> c1 = heap.top();
    heap.pop();
    pair<long long, int> c2 = heap.top();
    heap.pop();
    int x = c1.second, y = c2.second;
    edge.first = x;
    edge.second = y;
    int leader = (rang[x] > rang[y] ? x : y);
    long long road = min(INF, sum_dist[x] + sum_dist[y] + 1);
    unite_sets(x, y, road);
    heap.push(make_pair(sum_dist[leader], leader));
    cout << x + 1 << ' ' << y + 1 << endl;
    --p;
  }
  for (int i = 0; i < p; i++)
    cout << edge.first + 1 << ' ' << edge.second + 1 << endl;
  return 0;
}
