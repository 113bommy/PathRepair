#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long inf = LLONG_MAX;
vector<pair<pair<int, int>, int>> g[N];
int n, m, k;
long long CostMin[N];
bool vizitat[N];
int Dijkstra() {
  for (int i = 2; i <= n; i++) {
    CostMin[i] = inf;
  }
  priority_queue<pair<pair<long long, int>, int>> heap;
  heap.push({{0, 1}, 1});
  int ans = 0;
  while (!heap.empty()) {
    int NodCurent = heap.top().second;
    long long CostCurent = -heap.top().first.first;
    int CaleCurenta = heap.top().first.second;
    heap.pop();
    if (vizitat[NodCurent]) {
      continue;
    }
    vizitat[NodCurent] = true;
    if (CaleCurenta == 0) {
      ans++;
    }
    for (auto neigh : g[NodCurent]) {
      int NextNod = neigh.first.first;
      int NextCost = neigh.first.second;
      int NextCale = neigh.second;
      if (CostCurent + NextCost <= CostMin[NextNod]) {
        CostMin[NextNod] = CostCurent + NextCost;
        heap.push({{-CostMin[NextNod], NextCale}, NextNod});
      }
    }
  }
  return ans;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({{b, c}, 1});
    g[b].push_back({{a, c}, 1});
  }
  for (int i = 0; i < k; i++) {
    int city, cost;
    cin >> city >> cost;
    g[1].push_back({{city, cost}, 0});
    g[city].push_back({{1, cost}, 0});
  }
  cout << k - Dijkstra();
}
