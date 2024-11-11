#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> gr;
vector<int> cnt_leafs;
int MarkCnt(int v) {
  if (gr[v].empty()) {
    cnt_leafs[v] = 1;
    return 1;
  }
  int sum = 0;
  for (int u : gr[v]) {
    sum += MarkCnt(u);
  }
  cnt_leafs[v] = sum;
  return sum;
}
int DpMaxSecond(int v);
int DpMaxFirst(int v) {
  if (cnt_leafs[v] == 1) {
    return 1;
  }
  int total_leafs = 0;
  int dist = numeric_limits<int>::max();
  for (int u : gr[v]) {
    total_leafs += cnt_leafs[u];
    dist = min(dist, cnt_leafs[u] - DpMaxSecond(u));
  }
  return total_leafs - dist;
}
int DpMaxSecond(int v) {
  if (cnt_leafs[v] == 1) {
    return 1;
  }
  int total_leafs = 0;
  int sum_dist = 0;
  for (int u : gr[v]) {
    total_leafs += cnt_leafs[u];
    sum_dist += cnt_leafs[u] - DpMaxFirst(u) + 1;
  }
  return total_leafs - sum_dist;
}
int DpMinFirst(int v);
int DpMinSecond(int v) {
  if (cnt_leafs[v] == 1) {
    return 1;
  }
  int dist = numeric_limits<int>::max();
  for (int u : gr[v]) {
    dist = min(dist, DpMinFirst(u));
  }
  return dist;
}
int DpMinFirst(int v) {
  if (cnt_leafs[v] == 1) {
    return 1;
  }
  int sum_dist = 0;
  for (int u : gr[v]) {
    sum_dist += DpMinSecond(u);
  }
  return sum_dist;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  gr.resize(N);
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    gr[a].push_back(b);
  }
  cnt_leafs.assign(N, 0);
  MarkCnt(0);
  cout << DpMaxFirst(0) << ' ' << DpMinFirst(0) << '\n';
  return 0;
}
