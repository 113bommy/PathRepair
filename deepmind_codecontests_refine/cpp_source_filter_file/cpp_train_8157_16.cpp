#include <bits/stdc++.h>
using namespace std;
const int N = 10;
const int M = 110;
int mark[M], ptr[N];
vector<pair<int, int> > adj[N];
vector<int> E[N][N], vec;
void tour(int v, int id) {
  mark[id] = 1;
  while (ptr[v] < adj[v].size()) {
    int u = adj[v][ptr[v]].first, x = adj[v][ptr[v]].second;
    if (!mark[x]) tour(u, x);
    ptr[v]++;
  }
  vec.push_back(v);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, u, v, cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    E[u][v].push_back(i);
  }
  for (int i = 0; i < N; i++)
    if (adj[i].size() % 2) cnt++, v = i;
  if (2 < cnt) return cout << "No solution", 0;
  tour(v, 0);
  for (int i = 0; i < n; i++)
    if (ptr[i] < adj[i].size()) return cout << "No solution", 0;
  for (int i = 0; i < vec.size() - 1; i++) {
    u = vec[i], v = vec[i + 1];
    if (E[u][v].size()) {
      cout << E[u][v].back() << ' ' << '+' << '\n';
      E[u][v].pop_back();
    } else {
      cout << E[v][u].back() << ' ' << '-' << '\n';
      E[v][u].pop_back();
    }
  }
  return 0;
}
